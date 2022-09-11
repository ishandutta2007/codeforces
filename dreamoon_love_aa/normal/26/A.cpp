#include<stdio.h>
int d[3001];
main(){
    int i,j;
    for(i=2;i<=3000;i++)
        if(d[i]==0)
            for(j=i;j<=3000;j+=i)d[j]++;
    for(i=1;i<=3000;i++){
        if(d[i]==2)d[i]=1;
        else d[i]=0;
        d[i]+=d[i-1];
    }
    scanf("%d",&i);
    printf("%d\n",d[i]);
}