#include<stdio.h>
void Go(int x,int y){
    if(x==1){
        puts("1");
        return;
    }
    printf("%d ",x);
    while(x%y&&y*y<=x)y++;
    if(x%y==0)
        Go(x/y,y);
    else
        Go(1,1);
}
main(){
    int n;
    scanf("%d",&n);
    Go(n,2);
}