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

#define maxn 55
int n;
string board[maxn];
int col_pref_sum[maxn][maxn], row_pref_sum[maxn][maxn];

llong dp_mem[maxn][maxn][maxn][maxn];
llong dp(int r1, int c1, int r2, int c2) {
    if (r1 >= r2 or c1 >= c2) return 0;
    llong& ans = dp_mem[r1][c1][r2][c2];
    if (ans != -1) return ans;

    ans = max(r2 - r1, c2 - c1);

    for (int i = r1; i < r2; ++i) {
        if (row_pref_sum[i][c2] - row_pref_sum[i][c1] != 0) continue;
        ans = min(ans, dp(r1, c1, i, c2) + dp(i + 1, c1, r2, c2));
    }

    for (int i = c1; i < c2; ++i) {
        if (col_pref_sum[i][r2] - col_pref_sum[i][r1] != 0) continue;
        ans = min(ans, dp(r1, c1, r2, i) + dp(r1, i + 1, r2, c2));
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    rep(i, n) cin >> ws >> board[i];

    memset(col_pref_sum, 0, sizeof(col_pref_sum));
    memset(row_pref_sum, 0, sizeof(row_pref_sum));

    rep(i, n) rep(f, n) {
        row_pref_sum[i][f + 1] = row_pref_sum[i][f] + (board[i][f] == '#');
        col_pref_sum[f][i + 1] = col_pref_sum[f][i] + (board[i][f] == '#');
    }

    memset(dp_mem, -1, sizeof(dp_mem));
    cout << dp(0, 0, n, n);

    return 0;
}