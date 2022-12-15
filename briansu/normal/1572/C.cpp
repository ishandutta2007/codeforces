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

int a[3005];
int dp[3005][3005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            dp[i][i] = 0;
        for (int l = n; l >= 1; l--) {
            vector<int> same;
            for (int r = l + 1; r <= n; r++) {
                if (a[l] == a[r])
                    same.pb(r);
                dp[l][r] = dp[l + 1][r] + (a[l] != a[l + 1]);
                for (int x : same)
                    if (x != l + 1)
                        dp[l][r] = min(dp[l][r], dp[l + 1][x - 1] + (a[l] != a[l + 1]) + dp[x][r]);
            }
        }
        cout << dp[1][n] << "\n";
    }
}