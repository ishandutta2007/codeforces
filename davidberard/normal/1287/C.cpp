#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int N = 110;
const int INF = 0x3f3f3f3f;

int dp[N][N][2];
int a[N];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int ro = (n+1)/2;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (a[i]%2) {
            --ro;
        }
    }
    memset(dp, INF, sizeof dp);
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;

    for (int i=1; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            if (a[i]) {
                if (a[i]%2 == 0) {
                    dp[i][j][1] = INF;
                    dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]+1);
                } else {
                    dp[i][j][0] = INF;
                    dp[i][j][1] = min(dp[i-1][j][1], dp[i-1][j][0]+1);
                }
            } else {
                dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]+1);
                dp[i][j+1][1] = min(dp[i-1][j][1], dp[i-1][j][0]+1);
            }
        }
    }
    cout << min(dp[n][ro][0], dp[n][ro][1]) << "\n";
    return 0;
}