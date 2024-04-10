#include<stdio.h>
int max(int x,int y){return x<y?y:x;}
main(){
    int x,y;
    scanf("%d%d",&x,&y);
    x=max(x,y);
    if(x==1)puts("1/1");
    else if(x==2)puts("5/6");
    else if(x==3)puts("2/3");
    else if(x==4)puts("1/2");
    else if(x==5)puts("1/3");
    else if(x==6)puts("1/6");
}