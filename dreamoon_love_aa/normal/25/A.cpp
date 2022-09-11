#include<stdio.h>
int d[110],a[110];
main(){
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[x%2]=i+1;
        d[x%2]++;
    }
    if(d[0]==1)printf("%d\n",a[0]);
    else printf("%d\n",a[1]);
}