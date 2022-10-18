#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=405;

int n,m;
int binom[maxn][maxn];
int dp[maxn][maxn];
int f0[maxn];

int main(){
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        binom[i][0]=1;
        for(int j=1;j<=i;j++)binom[i][j]=(binom[i-1][j-1]+binom[i-1][j])%m;
    }
    f0[1]=1;
    for(int i=2;i<=n;i++)f0[i]=2*f0[i-1]%m;
    for(int i=1;i<=n;i++){
        dp[i][i]=f0[i];
        for(int j=1;j<i;j++){
            int z=i-j-1;
            int cof=f0[j];
            for(int k=0;k<=z;k++){
                dp[i][k+j]=(dp[i][k+j]+dp[z][k]*(long long)binom[k+j][k]%m*cof)%m;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=n;i++)ans=(ans+dp[n][i])%m;
    cout<<ans;
    return 0;
}