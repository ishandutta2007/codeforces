#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=100003;
lli dp[2][320][320];
lli mod=1e9+7;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,x;
    cin>>n>>m>>x;
    if(n>m){
        printf("0\n");
        return 0;
    }
    int cur=1,oth=0;
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<=j;k++) {
                dp[cur][j][k]=0;
                if (i == x) {
                    if(j&&k)dp[cur][j][k] = (dp[cur][j][k] + dp[oth][j - 1][k-1]) % mod;
                    if(j&&k)dp[cur][j][k] = (dp[cur][j][k] + dp[oth][j-1][k]) % mod;
                } else {
                    dp[cur][j][k]=dp[oth][j][k];
                    dp[cur][j][k] = (dp[cur][j][k] + dp[oth][j][k+1]) % mod;
                    if (j&&k)dp[cur][j][k] = (dp[cur][j][k] + dp[oth][j - 1][k-1]) % mod;
                    if(j&&k)dp[cur][j][k] = (dp[cur][j][k] + dp[oth][j-1][k]) % mod;
                }
            }
        }
        swap(oth,cur);
    }
    lli ans=(dp[oth][n][0]+dp[oth][n][1])%mod;
    for(lli i=1;i<=n;i++){
        ans=ans*i%mod;
    }
    printf("%lli\n",ans);
    return 0;
}