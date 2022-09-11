#include<stdio.h>
int DD,MM,YY;
int leap[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int normal[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool f(int x,int y,int z){
    if(y>12||y==0)return 0;
    if(z%4==0){
        if(x==0||x>leap[y-1])return 0;
    }
    else{
        if(x==0||x>normal[y-1])return 0;
    }
    if(z+18>YY)return 0;
    if(z+18<YY)return 1;
    if(MM<y)return 0;
    if(MM>y)return 1;
    if(DD<x)return 0;
    return 1;
}
main(){
    int x,y,z;
    scanf("%d . %d . %d",&DD,&MM,&YY);
    scanf("%d . %d . %d",&x,&y,&z);
    if(f(x,y,z)||
       f(x,z,y)||
       f(y,x,z)||
       f(y,z,x)||
       f(z,x,y)||
       f(z,y,x))puts("YES");
    else puts("NO");
}