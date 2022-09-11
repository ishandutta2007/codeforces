#include<stdio.h>
int a[1010];
main(){
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        if(a[i]!=i)break;
    if(i>n){
        puts("0 0");
    }
    else{
        for(k=0;k<=a[i]-i;k++)
            if(a[i+k]!=a[i]-k)break;
        if(k<=a[i]-i)puts("0 0");
        else{
            for(j=a[i]+1;j<=n;j++)
                if(a[j]!=j)break;
            if(j<=n)puts("0 0");
            else printf("%d %d\n",i,a[i]);
        }
    }
}