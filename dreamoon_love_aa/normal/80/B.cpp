#include<stdio.h>
main(){
    int x,y;
    scanf("%d : %d",&x,&y);
    x%=12;
    printf("%.1lf %d\n",x*30+y*0.5,y*6);
}