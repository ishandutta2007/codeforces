#include<stdio.h>
main(){
    int i,now=0,n;
    scanf("%d",&n);
    if(n<0)n=-n;
    if(n==0)puts("0");
    else{
        for(i=1;;i++){
            now+=i;
            if(now>=n&&(now-n)%2==0)break;
        }
        printf("%d\n",i);
    }
}