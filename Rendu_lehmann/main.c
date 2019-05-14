#include <stdio.h>
#include <stdlib.h>
#include <SDL2\SDL.h>

/*****************************************

Partie struct

*****************************************/
typedef struct tVector{
    int nX;
    int nY;

}tVector;

typedef struct tActor{

    SDL_Texture *g_texture;
    tVector vect;
    int H;
    int W;

}tActor;

typedef struct Liste{
    tActor *premier;
    tActor *deuxieme;
}Liste;

/*****************************************

Partie proto

****************************************/
void insertion(Liste *liste, tActor Actor);
void suppression(Liste *liste);
void afficherListe(Liste *liste,tActor Player,tActor Monstre);

/***************************************
Main
***************************************/
int main(int argc, char* argv[])
{

    Liste *maListe;
    tActor Player;
        Player.g_texture;
        Player.H = 60;
        Player.W = 60;
        Player.vect.nX = 325;
        Player.vect.nY = 50;

    tActor Monstre;
        Monstre.g_texture;
        Monstre.H=20;
        Monstre.W=20;
        Monstre.vect.nX = 200;
        Monstre.vect.nY = 350;

    insertion(maListe, Player);
    insertion(maListe, Monstre);
    afficherListe(maListe,Player,Monstre);


    return 0;
}

/************************

Procédure

************************/

void insertion(Liste *liste,  tActor Actor)
{
    /* Création of a new element */
    Liste *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->deuxieme = liste->premier;

    /* Insertion of a new element in the list */
    nouveau->deuxieme = liste->premier;
    liste->premier = nouveau->deuxieme;

}
    /*delete liste*/
void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        tActor *aSupprimer = liste->premier;
        liste->premier = liste->deuxieme;
        free(aSupprimer);
    }
}

/*  show list on screen      */
void afficherListe(Liste *liste,tActor Player,tActor Monstre){
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* screen = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* Renderer=SDL_CreateRenderer(screen,-1,SDL_RENDERER_ACCELERATED| SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;

    SDL_Rect Player_Rect;
        Player_Rect.x=Player.vect.nX;
        Player_Rect.y=Player.vect.nY;
        Player_Rect.w=Player.W;
        Player_Rect.h=Player.H;

    SDL_Rect Monstre_Rect;
        Monstre_Rect.x=Monstre.vect.nX;
        Monstre_Rect.y=Monstre.vect.nY;
        Monstre_Rect.w=Monstre.W;
        Monstre_Rect.h=Monstre.H;

    SDL_SetRenderDrawColor(Renderer,200,200,200,10);

    SDL_RenderClear(Renderer);

    SDL_SetRenderDrawColor(Renderer,0,225,0,10);

    SDL_RenderFillRect(Renderer,&Player_Rect);

    SDL_SetRenderDrawColor(Renderer,225,0,0,10);

    SDL_RenderFillRect(Renderer,&Monstre_Rect);

    SDL_RenderPresent(Renderer);
    int repeat = 0;

    while(!repeat)
    {
        SDL_PollEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
            repeat = 1;
            break;
        }
    }
    SDL_DestroyWindow(screen);
}
