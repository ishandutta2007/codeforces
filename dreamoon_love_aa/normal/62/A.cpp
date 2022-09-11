#include<stdio.h>
int abs(int x){return x<0?-x:x;}
bool f(int x,int y){
    return x<=y+1&&2*(x+1)>=y;
}
main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(f(b,c)||f(a,d))puts("YES");
    else puts("NO");
}