#include<algorithm>
#include<stdio.h>
using namespace std;
int d[1010];
main(){
    int n,m,k,i,j,r;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)d[i]=100000000;
    for(r=1;r<=n;r++){
        scanf("%d%d",&i,&j);
        d[i]=min(d[i],j);
    }
    j=0;
    for(i=1;i<=m;i++)j+=d[i];
    printf("%d\n",min(j,k));
}