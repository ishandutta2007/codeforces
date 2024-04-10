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

#define maxn 201010
#define rem ((llong) 998244353 )

llong fac[maxn];

int n;
vector<int> gr[maxn];
llong dp[maxn];

void dfs(int u, int p) {
    dp[u] = 1;
    for (auto v: gr[u]) {
        if (v == p) continue;
        dfs(v, u);
        (dp[u] *= dp[v]) %= rem;
    }

    (dp[u] *= fac[len(gr[u])]) %= rem;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fac[0] = 1;
    rep(i, maxn - 1)
        fac[i + 1] = fac[i] * (i + 1) % rem;

    cin >> n;
    rep(i, n - 1) {
        int u, v; cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    dfs(1, 1);
    llong ans = (n * fac[len(gr[1])]) % rem;
    for (auto i: gr[1]) (ans *= dp[i]) %= rem;

    cout << ans;

    return 0;
}