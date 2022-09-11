#include<stdio.h>
int d[110];
main(){
    int n,k,i,j,x,an=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        d[x]++;
    }
    while(d[k]!=n){
        an++;
        for(i=k-1;i>=0;i--)
            if(d[i]){
                d[i+1]++;
                d[i]--;
            }
    }
    printf("%d\n",an);
}