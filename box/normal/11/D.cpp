#pragma GCC optimize("O3,Ofast")
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

ll dp[1<<19][19];
bool exi[19][19];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        exi[u][v] = exi[v][u] = 1;
    }
    rep(i, n) dp[1<<i][i] = 1;
    rep(i, n) iter(j, i+1, n) if(exi[i][j]) dp[(1<<i)|(1<<j)][j] = 1;
    ll ans = 0;
    iter(mask, 1, 1<<n) {
        int i = 0, pc = __builtin_popcount(mask);
        while(!(mask & (1<<i))) i++;
        if(pc <= 2) continue;
        rep(j, n) if(mask & (1<<j)) {
            int v = mask^(1<<j);
            rep(k, n)
                if((v & (1<<k)) && k != i && exi[j][k]) dp[mask][j] += dp[v][k];
            if(exi[i][j]) ans += dp[mask][j];
        }
    }
    cout << ans/2 << endl;
}