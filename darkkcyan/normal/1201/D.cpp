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

#define maxn 201010
#define inf ((llong)maxn * (llong)maxn * 100ll)
int n, m, k, q;
pair<llong, llong> ranges[maxn];
llong safe_cols[maxn];

llong find_dis(llong c1, llong c2) {
    if (c1 > c2) swap(c1, c2);
    auto s1 = upper_bound(safe_cols, safe_cols + q, c1) - 1;
    auto s2 = lower_bound(safe_cols, safe_cols + q, c2);
    if (s2 - (s1 + 1) > 0) return c2 - c1;
    return min(
            s1 >= safe_cols ? 1ll * c1 + c2 - 2 * *s1 : inf,
            s2 < safe_cols + q ?  2ll * *s2 - c1 - c2 : inf
    );
}

llong dp[maxn][2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> q;
    
    llong max_row = 1;

    rep1(i, n) ranges[i] = {inf, -inf};

    rep(i, k) {
        llong r, c; cin >> r >> c;
        max_row = max(max_row, r);
        ranges[r].xx = min(ranges[r].xx, c);
        ranges[r].yy = max(ranges[r].yy, c);
    }

    rep(i, q) cin >> safe_cols[i];
    sort(safe_cols, safe_cols + q);

    ranges[0] = {1, 1};
    dp[0][0] = dp[0][1] = 0;
    int last_active = 0;

    if (ranges[1].xx <= ranges[1].yy) {
        dp[1][1] = ranges[1].yy - 1;
        dp[1][0] = ranges[1].yy - 1 + ranges[1].yy - ranges[1].xx;
        last_active = 1;
    }

    llong ans = max_row - 1;
    for (int i = 2; i <= max_row; ++i) {
        if (ranges[i].xx > ranges[i].yy) continue;
        llong temp_dp[2] = {inf, inf};

        int cur_u = -1;
        for (auto u: {ranges[i].xx, ranges[i].yy}) {
            ++cur_u;
            temp_dp[cur_u] = min(
                find_dis(u, ranges[last_active].xx) + dp[last_active][0],
                find_dis(u, ranges[last_active].yy) + dp[last_active][1]
            );
        }
 
        dp[i][0] = temp_dp[1] + ranges[i].yy - ranges[i].xx;
        dp[i][1] = temp_dp[0] + ranges[i].yy - ranges[i].xx;
        last_active = i;
        // clog << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    }

    ans += min(dp[last_active][0], dp[last_active][1]);
    cout << ans;


    return 0;
}