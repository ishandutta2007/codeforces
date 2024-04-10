#include<stdio.h>
long long f(long long x,long long y){
    long long an=0;
    if(x&1){
        an^=x;
        x++;
        y--;
        if(!y)return an;
    }
    if(y&1){
        an^=x+y-1;
        y--;
    }
    if(y%4==0)return an;
    else return an^1;
}
main(){
    int n;
    long long x,y,an=0;
    scanf("%d",&n);
    while(n--){
        scanf("%I64d%I64d",&x,&y);
        an^=f(x,y);
    }
    if(an)puts("tolik");
    else puts("bolik");
}