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

#define maxn 100
#define maxm 101010
#define inf 1010101
int n, m;
pair<int, int> anten[maxn];
int dp[2][maxm];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >>m;
    rep(i, n) cin >> anten[i].xx >> anten[i].yy;
    sort(anten, anten + n);

    rep1(i, m) dp[1][i] = inf;
    dp[1][0] = 0;

    rep(i, n) {
        int cur = i & 1;
        memcpy(dp[cur], dp[!cur], sizeof(dp[cur]));
        rep(range, m + 1) {
            int dis = anten[i].xx + anten[i].yy + range;
            int prev = anten[i].xx - anten[i].yy - range - 1;
            dis = min(dis, m);
            dp[cur][dis] = min(dp[cur][dis], (prev < 0 ? 0 : dp[!cur][prev]) + range);
        }

        for (int f = m; f--; ) dp[cur][f] = min(dp[cur][f], dp[cur][f + 1]);
        // rep(f, m + 1) clog << f << ':' << dp[cur][f] << ' ';
        // clog << endl;
    }
    cout << dp[~n & 1][m];

    return 0;
}