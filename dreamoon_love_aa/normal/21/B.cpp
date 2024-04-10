#include<stdio.h>
main(){
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if((a==0&&b==0&&c!=0)||(d==0&&e==0&&f!=0))puts("0");
    else if(a*e==b*d){
        if(a*f==d*c)puts("-1");
        else puts("0");
    }
    else puts("1");
}