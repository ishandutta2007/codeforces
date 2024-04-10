#include<stdio.h>
main(){
    int i,n,x,odd=0,even=0,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        sum^=x;
        if(x&1)odd++;
        else even++;
    }
    printf("%d\n",(sum&1)?odd:even);
}