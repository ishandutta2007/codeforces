#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int INF = 1e8;
int a[3005], dp[3005][3005], sub[3005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                dp[i][j] = INF;
        dp[n][n + 1] = 0;
        for (int i = n - 1; i >= 1; i--) {
            fill_n(sub, n + 1, 0);
            int tt = 0;
            for (int j = i + 1; j <= i + a[i]; j++) {
                dp[i][j] = min(dp[i][j], dp[j][i + a[i] + 1] + tt);
                tt++;
                sub[j + a[j]]++;
                tt -= sub[j];
            }
            for (int j = n; j >= 1; j--)
                dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
        cout << dp[1][1] << "\n";
    }
}