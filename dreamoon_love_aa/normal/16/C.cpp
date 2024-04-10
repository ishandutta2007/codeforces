#include<stdio.h>
int gcd(int x,int y){
    while((x%=y)&&(y%=x));
    return x+y;
}
main(){
    int a,b,x,y,g;
    scanf("%d%d%d%d",&a,&b,&x,&y);
    g=gcd(x,y);
    x/=g;
    y/=g;
    if(a/x<b/y)g=a/x;
    else g=b/y;
    printf("%d %d\n",g*x,g*y);
}