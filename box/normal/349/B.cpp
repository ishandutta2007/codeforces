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
const int MOD = 1000000007;

int dp[1000006];
int be[1000006];
int v[10];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep1(i, 9) cin >> v[i];
    rep(i, n+1) {
        dp[i] = 0, be[i] = 0;
        rep1(d,9) if(v[d] <= i && dp[i] <= dp[i-v[d]]+1) {
            dp[i] = dp[i-v[d]]+1;
            be[i] = d;
        }
    }
    if(!dp[n]) cout << -1 << endl;
    int at = n;
    while(dp[at]) {
        cout << be[at];
        at = at-v[be[at]];
    }
    cout << endl;
}