#include<stdio.h>
main(){
    int x,y,z;
    scanf("%d%d",&x,&y);
    while(1){
        if(x>=2&&y>=2){
            x-=2;
            y-=2;
        }
        else if(x>=1&&y>=12){
            x--;
            y-=12;
        }
        else if(y>=22){
            y-=22;
        }
        else{
            puts("Hanako");
            break;
        }
        z=22;
        if(y>=22){
            y-=22;
        }
        else if(x>=1&&y>=12){
            x--;
            y-=12;
        }
        else if(x>=2&&y>=2){
            x-=2;
            y-=2;
        }
        else{
            puts("Ciel");
            break;
        }
    }
}