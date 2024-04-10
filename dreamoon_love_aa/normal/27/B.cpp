#include<stdio.h>
int d[51],e[51],g[2];
main(){
    int n,m,x,y,i;
    scanf("%d",&n);
    m=n*(n-1)/2-1;
    while(m--){
        scanf("%d%d",&x,&y);
        d[x]++;
        e[y]++;
    }
    for(i=1;;i++)
        if(d[i]+e[i]<n-1){
            g[0]=i;
            break;
        }
    for(i++;;i++)
        if(d[i]+e[i]<n-1){
            g[1]=i;
            break;
        }
    if(d[g[0]]>=d[g[1]])printf("%d %d\n",g[0],g[1]);
    else printf("%d %d\n",g[1],g[0]);
}