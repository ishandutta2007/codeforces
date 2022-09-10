#include<stdio.h>
main(){
    int a,b,mod,i;
    scanf("%d%d%d",&a,&b,&mod);
    for(i=1;i<=mod&&i<=a;i++){
        long long x=((i*1000000000ll-1)/mod+1)*mod;
        if(x-i*1000000000ll>b)break;
    }
    if(i>mod||i>a)puts("2");
    else{
        printf("1 %09d\n",i);
    }
}