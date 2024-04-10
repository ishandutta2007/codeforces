#include<stdio.h>
main(){
    int sum=0,mi=1000,i,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        sum+=x;
        if(x%2==1&&x<mi)mi=x;
    }
    if(sum&1)printf("%d\n",sum);
    else{
        if(mi==1000)puts("0");
        else printf("%d\n",sum-mi);
    }
}