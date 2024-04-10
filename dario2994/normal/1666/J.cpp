#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int n;
const int maxN = 205;
ll dp[maxN][maxN];
ll outside[maxN][maxN];
ll c[maxN][maxN];
int par[maxN][maxN];
int ans[maxN];
void go(int l, int r, int p) {
    if (l > r) return;
    int c = par[l][r];
    ans[c] = p;
    go(l, c - 1, c);
    go(c + 1, r, c);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            outside[l][r] = outside[l][r - 1];
            for (int x = l; x < r; x++) {
                outside[l][r] -= c[x][r];
            }
            for (int x = r + 1; x <= n; x++) {
                outside[l][r] += c[r][x];
            }
            for (int x = 1; x < l; x++) {
                outside[l][r] += c[x][r];
            }
        }
    }
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (l == r) {
                dp[l][r] = 0;
                par[l][r] = l;
                continue;
            }
            dp[l][r] = 5e18;
            for (int t = l; t <= r; t++) {
                if (dp[l][r] > dp[l][t - 1] + dp[t + 1][r] + outside[l][t - 1] + outside[t + 1][r]) {
                    dp[l][r] = dp[l][t - 1] + dp[t + 1][r] + outside[l][t - 1] + outside[t + 1][r];
                    par[l][r] = t;
                }
            }
        }
    }
    go(1, n, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}