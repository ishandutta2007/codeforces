#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;
const long long mdn=998244353;
const int cst[16]={0,1,1,1,0,0,2,0,0,2,0,0,1,1,1,0};

long long dp[maxn][maxn<<1][4];

int n,k;

int main(){
    cin>>n>>k;
    dp[1][1][0]=1;
    dp[1][2][1]=1;
    dp[1][2][2]=1;
    dp[1][1][3]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            for(int a=0;a<4;a++){
                for(int b=0;b<4;b++){
                    if(j-cst[(b<<2)+a]>0)dp[i][j][a]=(dp[i][j][a]+dp[i-1][j-cst[(b<<2)+a]][b])%mdn;
                }
            }
        }
    }
    cout<<(dp[n][k][0]+dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mdn;
    return 0;
}//EI jk ioi