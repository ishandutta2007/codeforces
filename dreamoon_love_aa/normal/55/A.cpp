#include<stdio.h>
bool used[1010];
main(){
    int n,x,i;
    scanf("%d",&n);
    x=0;
    for(i=0;i<=n+n;i++){
        x=(x+i)%n;
        used[x]=1;
    }
    for(i=0;i<n;i++)
        if(!used[i])break;
    if(i==n)puts("YES");
    else puts("NO");
}