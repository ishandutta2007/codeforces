#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<queue>
#include<bitset>
#include<string>
#include<stdlib.h>
#define pb push_back
using namespace std;
long long dp[4001][4001],d[2][2];
#define MOD 1000000007
int main(){
    int T,i,j,n,m,cs=0;
    for(i=0;i<=4000;i++)
        for(j=1;j<=4000;j++)
            dp[i][j]=__gcd(i,j)-1;
    for(i=0;i<=4000;i++)
        for(j=0;j<=4000;j++)if(j)dp[i][j]+=dp[i][j-1];
    for(i=0;i<=4000;i++)
        for(j=0;j<=4000;j++)if(i)dp[i][j]+=dp[i-1][j];
    while(scanf("%d%d",&n,&m)==2&&n+m){
        long long r=(n+1)*(m+1);
        long long r1=r,r2=r-1,r3=r-2;
        if(r1%2==0)r1/=2;
        else r2/=2;
        if(r1%3==0)r1/=3;
        else if(r2%3==0)r2/=3;
        else r3/=3;
        long long an=r1%MOD*r2%MOD*r3%MOD,de=0;
        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++){
                de+=dp[n-i][m-j];
                de+=dp[m-j][i];
                de+=dp[i][j];
                de+=dp[j][n-i];
            };
        an-=de>>1;
        an%=MOD;
        if(an<0)an+=MOD;
        an*=6;
        d[0][0]=n/2+1;
        d[0][1]=n+1-d[0][0];
        d[1][0]=m/2+1;
        d[1][1]=m+1-d[1][0];
        int h1,h2,h3,h4,h5,h6;
        for(h1=0;h1<2;h1++)
            for(h2=0;h2<2;h2++)
                for(h3=0;h3<2;h3++)
                    for(h4=0;h4<2;h4++)
                        for(h5=0;h5<2;h5++)
                            for(h6=0;h6<2;h6++){
                                if((h1&h4)^(h3&h6)^(h5&h2)^(h1&h6)^(h3&h2)^(h5&h4)){
                                    an-=d[0][h1]*d[0][h3]*d[0][h5]%MOD*d[1][h2]*d[1][h4]*d[1][h6]%MOD;
                                }
                            }
        an%=MOD;
        if(an<0)an+=MOD;
        cout<<an%MOD<<endl;
    }
    return 0;
}