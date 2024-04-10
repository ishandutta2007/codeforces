#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 101010
int n, m;
vector<int> gr[maxn];
int dp[maxn];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, m) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    llong ans = 0;
    rep1(u, n) {
        dp[u] = 1;
        for (auto v: gr[u]) 
            if (v < u) 
                dp[u] = max(dp[u], dp[v] + 1);
        ans = max(ans, 1ll * dp[u] * len(gr[u]));
    }
    cout << ans;

    return 0;
}