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
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxm 20
int n, m;
string s;
int cnt[maxm][maxm] = {0};
llong adding_cost[maxm][1 << maxm];
llong dp[1 << maxm];

llong cal_adding_cost(int u, int mask) {
    if (adding_cost[u][mask] != LLONG_MAX) return adding_cost[u][mask];
    if (mask == 0) {
        adding_cost[u][0] = 0;
        rep(i, m) if (i != u)
            adding_cost[u][0] -= cnt[i][u];
        return adding_cost[u][0];
    }

    rep(i, m) {
        if ((~mask >> i) & 1) continue;
        adding_cost[u][mask] = cal_adding_cost(u, mask ^ (1 << i)) + 2 * cnt[i][u];
        break;
    }
    assert(adding_cost[u][mask] != LLONG_MAX);
    // clog << u << ' ' << mask << ' ' << adding_cost[u][mask] << endl;
    return adding_cost[u][mask];
}

llong cal(int mask) {
    if (dp[mask] != -1) return dp[mask];
    if (mask == 0) return 0;
    dp[mask] = LLONG_MAX;
    rep(i, m) {
        if ((~mask >> i) & 1) continue;
        int new_mask = mask ^ (1 << i);
        dp[mask] = min(dp[mask], cal(new_mask) + cal_adding_cost(i, new_mask) * __builtin_popcount(new_mask));
    }
    return dp[mask];
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    rep1(i, n - 1) {
        int u = s[i - 1] - 'a', v = s[i] - 'a';
        ++cnt[u][v];
        ++cnt[v][u];
    }

    memset(dp, -1, sizeof(dp));
    rep(i, m) rep(f, (1 << m)) adding_cost[i][f] = LLONG_MAX;
    cout << cal((1 << m) - 1);

    return 0;
}