#include<stdio.h>
int len[300000];
double p[18][18],an[18],dp[300000];
int f(int x){return x*(x-1)/2;}
main(){
    int n,i,j,k,nn;
    scanf("%d",&n);
    nn=n;
    for(i=1;i<(1<<n);i++)len[i]=len[i>>1]+(i&1);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)scanf("%lf",&p[i][j]);
    dp[(1<<n)-1]=1;
    for(i=(1<<n)-1;i>0;i--){
        if(len[i]==1){
            an[--nn]=dp[i];
            continue;
        }
        for(j=0;(1<<j)<=i;j++){
            if(!((1<<j)&i))continue;
            for(k=j+1;(1<<k)<=i;k++){
                if(!((1<<k)&i))continue;
                dp[i-(1<<j)]+=dp[i]*p[k][j]/f(len[i]);
                dp[i-(1<<k)]+=dp[i]*p[j][k]/f(len[i]);
            }
        }
    }
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%.6lf",an[i]);
    }
    puts("");
}