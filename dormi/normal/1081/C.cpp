#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e3+1;
lli mod=998244353;
lli dp[MAXN][MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=min(i-1,k);j++){
            dp[i][j]=((j?dp[i-1][j-1]*(m-1)%mod:(lli)0)+dp[i-1][j])%mod;
        }
    }
    printf("%lli\n",dp[n][k]*m%mod);
    return 0;
}