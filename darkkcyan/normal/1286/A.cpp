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

#define maxn 111
#define inf 2000000
int n;
int p[maxn];
int dp[maxn][maxn][maxn][2];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    int cnt[2] = {n / 2, (n + 1) / 2};
    rep(i, n) {
        cin >> p[i];
        if (p[i] != 0) {
            cnt[p[i] & 1] --;
        }
    }

    rep(i, maxn) rep(f, maxn) rep(g, maxn) rep(t, 2) dp[i][f][g][t] = inf;
    // clog << cnt[0] << ' ' << cnt[1] << endl; 

    if (p[0] > 0) {
        dp[1][cnt[0]][cnt[1]][p[0] & 1] = 0;
    } else {
        if (cnt[0] > 0) dp[1][cnt[0] - 1][cnt[1]][0] = 0;
        if (cnt[1] > 0) dp[1][cnt[0]][cnt[1] - 1][1] = 0;
    }

    for (int i = 2; i <= n; ++i) {
        for (int c0 = 0; c0 <= n; ++c0)
        for (int c1 = 0; c1 <= n; ++c1)
        rep(last, 2) {
            if (p[i - 1] != 0) {
                int cur = p[i - 1] &  1;
                dp[i][c0][c1][cur] = min(dp[i][c0][c1][cur], dp[i - 1][c0][c1][last] + (cur != last));
                continue;
            }

            rep(pick, 2) {
                dp[i][c0][c1][pick] = min(dp[i][c0][c1][pick], dp[i - 1][c0 + (pick == 0)][c1 + (pick == 1)][last] + (last != pick));
            }
        }
    }

    // rep1(i, n) 
        // rep(c0, maxn) rep(c1, maxn) rep(l, 2) 
        // if (dp[i][c0][c1][l] < inf) 
            // clog << i << ' ' << c0 << ' ' << c1 << ' ' << l << ' ' << dp[i][c0][c1][l] << endl; 
    cout << min(dp[n][0][0][1], dp[n][0][0][0]);

    return 0;
}