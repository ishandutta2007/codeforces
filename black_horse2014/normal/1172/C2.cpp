#include <bits/stdc++.h>
using namespace std;

const int N = 220000;
const int M = 3300;
const int P = 998244353;

int dp[M][M], C[M][M];
int pos[M];
int pos1[M];
int neg[M];
int neg1[M];
int r[M * 2];
int a[N], w[N];

int modExp(int a, int n, int p) {
    a = (a % p + p) % p;
    int ret = 1;
    for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i <= m; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
        }
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    int S = 0, T = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            S += w[i];
        } else {
            T += w[i];
        }
    }
    for (int i = 0; i <= m + m; i++) r[i] = modExp(S + T - m + i, P - 2, P);
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i && j <= T; j++) {
            if (dp[i-1][j]) {
                int cur = S + i - 1 - j + T - j;
                dp[i][j] = (dp[i][j] + dp[i-1][j] * 1LL * r[cur - (S + T - m)]) % P;
                if (j+1 <= T) dp[i][j+1] = (dp[i][j+1] + dp[i-1][j] * 1LL * r[cur - (S + T - m)]) % P;
            }
        }
    }
    for (int i = 0; i <= m; i++) pos1[i] = i == 0 ? 1 : pos1[i - 1] * 1LL * (S + i - 1) % P;
    for (int i = 0; i <= m; i++) pos[i] = i == 0 ? 1 : pos[i - 1] * 1LL * (S + i) % P;
    for (int i = 0; i <= m; i++) neg[i] = i == 0 ? 1 : neg[i - 1] * 1LL * (T - i) % P;
    for (int i = 0; i <= m; i++) neg1[i] = i == 0 ? 1 : neg1[i - 1] * 1LL * (T - i + 1) % P;
    int sum[2] = {0};
    for (int i = 0; i <= m && i <= T; i++) {
        sum[0] = (sum[0] + dp[m][i] * 1LL * pos1[m - i] % P * neg[i]) % P;
        sum[1] = (sum[1] + dp[m][i] * 1LL * pos[m - i] % P * neg1[i]) % P;
    }
    for (int i = 1; i <= n; i++) {
        cout << 1LL * sum[a[i]] * w[i] % P << endl;
    }
    return 0;
}