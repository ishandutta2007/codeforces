#include<stdio.h>
bool f(int n,int x){
    return x==n/2||x-1==n/2;
}
main(){
    int N,x,y;
    scanf("%d%d%d",&N,&x,&y);
    if(f(N,x)&&f(N,y))puts("NO");
    else puts("YES");
}