#include<stdio.h>
int a[100001];
main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
    for(i=1;i<n;i++)
        if(a[i]>a[n]-a[i+1])break;
    printf("%d %d\n",i,n-i);
    scanf(" ");
}