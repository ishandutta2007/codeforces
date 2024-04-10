#include<stdio.h>
int f(int n,int x,int y){
    if(x==0)return y;
    if(y==n)return n+x;
    if(x==n)return n+n+n-y;
    return n+n+n+n-x;
}
main(){
    int n,x1,y1,x2,y2,a,b;
    scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
    a=f(n,x1,y1);
    b=f(n,x2,y2);
    if(a<b)a=b-a;
    else a=a-b;
    if(a>2*n)a=4*n-a;
    printf("%d\n",a);
}