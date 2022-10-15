#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 7;
const ll OO = (ll) 1e18;
int n;
string s;
int a[N];
ll combo[N];
ll dp[N][N];
ll trans[N][N][N][2];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        dp[i][j] = -OO;
                        for (int k = 0; k < N; k++) {
                                trans[i][j][k][0] = trans[i][j][k][1] = -OO;
                        }
                }
        }
        for (int i = 1; i < N; i++) {
                dp[i][i - 1] = 0;
                trans[i][i - 1][0][0] = trans[i][i - 1][0][1] = 0;
        }
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
                a[i] = s[i - 1] - '0';
                cin >> combo[i];
        }
        for (int i = 1; i <= n; i++) {
                dp[i][i] = combo[1];
                trans[i][i][0][0] = trans[i][i][0][1] = dp[i][i];
                trans[i][i][1][a[i]] = 0;
        }
        for (int len = 2; len <= n; len++) {
                for (int l = 1; l + len - 1 <= n; l++) {
                        int r = l + len - 1;
                        for (int cnt = 0; cnt <= len; cnt++) {
                                for (int d = 0; d <= 1; d++) {
                                        for (int k = l; k <= r; k++) {
                                                if (a[k] == d) {
                                                        trans[l][r][cnt][d] = max(trans[l][r][cnt][d], dp[l][k - 1] + trans[k + 1][r][cnt - 1][d]);
                                                }
                                        }
                                }
                                dp[l][r] = max(dp[l][r], trans[l][r][cnt][0] + combo[cnt]);
                                dp[l][r] = max(dp[l][r], trans[l][r][cnt][1] + combo[cnt]);
                        }
                        trans[l][r][0][0] = trans[l][r][0][1] = dp[l][r];
                }
        }
        cout << dp[1][n] << "\n";
        return 0;
}