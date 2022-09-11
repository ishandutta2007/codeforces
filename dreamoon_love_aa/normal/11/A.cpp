#include<stdio.h>
int n,d,a[2010],i,an,tmp;
main(){
    an=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        if(a[i]<=a[i-1]){
            tmp=(a[i-1]-a[i]+d)/d;
            a[i]+=d*tmp;
            an+=tmp;
        }
    }
    printf("%d\n",an);
}