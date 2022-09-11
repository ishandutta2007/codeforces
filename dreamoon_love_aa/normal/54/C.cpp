#include<stdio.h>
#include<algorithm>
using namespace std;
long long insection(long long l1,long long r1,long long l2,long long r2){
    return min(r1,r2)-max(l1,l2)+1;
}
double prob(long long L,long long R){
    long long an=0,i=1;
    while(1){
        if(i*2-1>=L) an+=insection(L,R,i,i*2-1);
        if(i>R/10)break;
        i*=10;
    }
    return 1.*an/(R-L+1);
}
double dp[1001][1001];
main(){
    int n,i,j,K;
    long long L,R;
    double p;
    scanf("%d",&n);
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        scanf("%I64d%I64d",&L,&R);
        p=prob(L,R);
        for(j=0;j<i;j++){
            dp[i][j]+=dp[i-1][j]*(1-p);
            dp[i][j+1]+=dp[i-1][j]*p;
        }
    }
    scanf("%d",&K);
    double an=0;
    for(i=(n*K+99)/100;i<=n;i++)an+=dp[n][i];
    printf("%.12lf\n",an);
}