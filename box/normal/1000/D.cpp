// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;
 
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 998244353;

ll choo[1005][1005];
int dp[1005];
int ar[1005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    choo[0][0] = 1;
    rep1(i, 1000) {
        choo[i][0] = 1;
        rep1(j, i) choo[i][j] = (choo[i-1][j-1] + choo[i-1][j]) % MOD; 
    }
    int n; cin >> n;
    rep1(i, n) cin >> ar[i];
    int ans = 0;
    for(int i=n; i>=1; i--) {
        if(ar[i] <= 0 || n < i+ar[i]) dp[i] = 0;
        else {
            dp[i] = choo[n-i][ar[i]];
            for(int j=i+ar[i]+1; j<=n; j++) dp[i] = (dp[i] + choo[j-i-1][ar[i]] * dp[j]) % MOD;
        }
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << endl;
}