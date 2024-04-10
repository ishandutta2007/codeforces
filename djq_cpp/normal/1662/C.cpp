#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, k;
struct matrix {
    int a[210][210];
    int* operator [] (int x) { return a[x]; }
    const int* operator [] (int x) const { return a[x]; }
    matrix() {
        memset(a, 0, sizeof a);
    }
} res, ans, G, D, I;
matrix operator * (const matrix &a, const matrix &b) {
    matrix ans;
    for (int i = 1; i <= 2 * n; i++)
        for (int k = 1; k <= 2 * n; k++)
            for (int j = 1; j <= 2 * n; j++) {
                ans[i][k] = (ans[i][k] + 1ll * a[i][j] * b[j][k]) % mod;
            }
    return ans;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) I[i][i] = 1;
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        D[u][u]++;
        D[v][v]++;
        G[u][v]++;
        G[v][u]++;
    }
    for (int i = 1; i <= n; i++) {
        ans[i][i] = ans[i + n][i + n] = 1;
        res[i][i + n] = 1;
        res[i + n][i] = mod + 1 - D[i][i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) res[i][j] = G[i][j];
    k--;
    for (; k; k >>= 1, res = res * res) if (k & 1) ans = ans * res;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) res[i][j] = ans[i][j + n];
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++) cerr << ans[i][j] << " \n"[j == n];
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++) cerr << res[i][j] << " \n"[j == n];
    res = res * D;
    ans = ans * G;
    int sum = 0;
    for (int i = 1; i <= n; i++) sum = (0ll + sum + ans[i][i] + mod - res[i][i]) % mod;
    cout << sum << endl;
}