#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MOD = 1e9 + 7;
const int MAXN = 50 + 3;
const int XX = MAXN * 2;

int ch[XX][XX];

int add(int x, int y) {
    x += y;
    if (x >= MOD)
        x -= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

int pw(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = 1ll * res * a % MOD;
        b >>= 1;
        a = 1ll*a*a % MOD;
    }
    return res;
}

int n, m;
int dp[MAXN][MAXN][MAXN][MAXN];
int path_dp[MAXN][MAXN];
int tt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    for (int i = 0; i < XX; i++) {
        ch[i][0] = 1;
        for (int j = 1; j <= i; j++)
            ch[i][j] = add(ch[i-1][j], ch[i-1][j-1]);
    }

    tt[0] = 1;
    for (int i = 1; i < MAXN; i++)
        tt[i] = 1ll*tt[i-1]*pw(i, MOD-2) % MOD;

    cin >> n >> m;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < MAXN; j++)
            dp[0][1][i][j] = 1;

    path_dp[1][1] = 1;

    for (int tn = 1; tn <= n; tn++) {
        for (int tm = 2; tm < MAXN; tm++)
            for (int i = tn; i; i--)
                for (int j = MAXN-1; j; j--) {
                    int new_j = j+1<MAXN? j+1: 1;
                    int new_i = j+1<MAXN? i: i+1;
                    dp[tn][tm][i][j] = dp[tn][tm][new_i][new_j];

                    if (j < tm) {
                        int X = path_dp[i][j];
                        if (!X) continue;

                        for (int t = 1; t * i <= tn && t * j <= tm-1; t++) {
                            int prod = 1;
                            for (int s = 1; s <= t; s++) {
                                prod = 1ll * prod * add(X, -(s-1)) % MOD;
                                int tmp = 1ll * prod * tt[s] % MOD;
                                tmp = 1ll * tmp * ch[t-1][s-1] % MOD;
                                dp[tn][tm][i][j] = (dp[tn][tm][i][j] + 1ll * tmp * dp[tn-t*i][tm-t*j][new_i][new_j]) % MOD;
                            }
                        }
                    }
                }

        for (int i = 0; i <= tn; i++)
            for (int tm = 1; tm < MAXN; tm++)
                for (int tm2 = 1; tm2 < MAXN; tm2++) {
                    int mn = min(tm, tm2);
                    path_dp[tn+1][mn] = (path_dp[tn+1][mn] + 1ll * dp[i][tm][1][1] * dp[tn-i][tm2][1][1]) % MOD;
                }
    }
    cout << dp[n][m][1][1] << "\n";
	return 0;
}