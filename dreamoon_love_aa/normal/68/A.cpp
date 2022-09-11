#include<stdio.h>
main(){
    int mi=10000000,x,a,b,i;
    for(i=0;i<4;i++){
        scanf("%d",&x);
        if(mi>x)mi=x;
    }
    scanf("%d%d",&a,&b);
    if(mi>b+1)mi=b+1;
    if(mi<=a)puts("0");
    else printf("%d\n",mi-a);
}