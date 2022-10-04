#include <iostream>

using namespace std;

typedef long long ll;

const int mx = 120;
const ll inf = ll(1e18);
ll n, m, k, i, j, cl[mx], dp[mx][mx][mx], a, b, c[mx][mx], bea, ans;

int main()
{
    cin >> n >> m >> k;
    for (i = 0; i<n; i++) {
        cin >> cl[i];
    }
    for (i = 0; i<n; i++) {
        for (j = 1; j<=m; j++) {
            cin >> c[i][j];
        }
    }
    for (i = 0; i<n; i++) {
        for (j = 0; j<=k; j++) {
            for (a = 0; a<=m; a++) {
                dp[i][j][a] = inf;
            }
        }
    }
    if (cl[0] > 0) {
        dp[0][1][cl[0]] = 0;
    }
    else {
        for (i = 1; i<=m; i++) {
            dp[0][1][i] = c[0][i];
        }
    }
    for (i = 1; i<n; i++) {
        if (cl[i] > 0) {
            for (j = 0; j<=k; j++) {
                for (a = 1; a<=m; a++) {
                    if (cl[i] != a) bea = j+1;
                    else bea = j;
                    dp[i][bea][cl[i]] = min(dp[i][bea][cl[i]], dp[i-1][j][a]);
                }
            }
        }
        if (cl[i] == 0) {
            for (a = 1; a<=m; a++) {
                for (j = 0; j<=k; j++) {
                    for (b = 1; b<=m; b++) {
                        if (a != b) bea = j+1;
                        else bea = j;
                        dp[i][bea][a] = min(dp[i][bea][a], dp[i-1][j][b] + c[i][a]);
                    }
                }
            }
        }
    }
    ans = inf;
    for (i = 1; i<=m; i++) {
        ans = min(ans, dp[n-1][k][i]);
    }
    if (ans == inf) ans = -1;
    cout << ans;
    return 0;
}