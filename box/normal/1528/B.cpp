// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 998244353;

int dp[1000005];
int div__[2000005];
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=i)div__[j]++;
    dp[0]=1;
    int ps=0;
    rep1(i,n){
        dp[i]=(div__[i]+ps)%MOD;
        ps=(ps+dp[i])%MOD;
        // for(int j=i-1;j>=1;j--)dp[i]=(dp[i]+dp[j])%MOD;
        // if(i==2)dp[i]=1;
    }
    cout<<dp[n]<<endl;
}