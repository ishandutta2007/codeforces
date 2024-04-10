#include<stdio.h>
int n;
int a[100010];
main(){
    int i,sum=0,ma=0,now=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=1;i<=n;i++){
        now+=a[i];
        if(now>ma)ma=now;
        if(now<0)now=0;
    }
    printf("%d\n",ma*2-sum);
}