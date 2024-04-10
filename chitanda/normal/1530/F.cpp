#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 31607;

int n;

int p[21][21], ip[21][21], pp[21][21], ipp[21][21];
int inv[M];
int h[21], c[21];
int X, Y;
int bh[1 << 21];

int f[2][2];
int tans;

inline int lowbit(int x) { return x & -x; }

void dfs(int i, int mask, int sum) {
    if (i == n) {
        int cur = 0;
        f[cur][0] = 1, f[cur][1] = 0;
        for (int j = 0; j < n; ++j) {
            f[cur ^ 1][0] = (f[cur][0] + f[cur][1] * c[j]) % M;
            f[cur ^ 1][1] = (f[cur][1] + f[cur][0] * c[j]) % M;
            cur ^= 1;
        }
        if (mask & 1) {
            tans = (tans - sum * (f[cur][1] - f[cur][0])) % M;
        } else {
            tans = (tans + sum * (f[cur][1] - f[cur][0])) % M;
        }
        return;
    }
    dfs(i + 1, mask, sum);
    for (int j = 0; j < n; ++j) c[j] = c[j] * ip[i][j] % M;
    dfs(i + 1, mask + 1, sum * h[i] % M);
    for (int j = 0; j < n; ++j) c[j] = c[j] * p[i][j] % M;
}

int solve(bool dx, bool dy) {
    int base = 1;
    if (dx) base = base * X % M;
    if (dy) base = base * Y % M;
    if (dx && dy && (n & 1)) base = base * ip[n / 2][n / 2] % M;

    memcpy(pp, p, sizeof(pp));
    memcpy(ipp, ip, sizeof(ipp));
    for (int i = 0; i < n; ++i) {
        if (dx) p[i][i] = ip[i][i] = 1;
        if (dy) p[i][n - i - 1] = ip[i][n - i - 1] = 1;
        h[i] = c[i] = 1;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            h[i] = h[i] * p[i][j] % M;
            c[j] = c[j] * p[i][j] % M;
        }
    tans = 0;
    dfs(0, 0, 1);

    memcpy(p, pp, sizeof(pp));
    memcpy(ip, ipp, sizeof(ipp));

    // printf("%d, %d\n", base, tans);
    return tans * base % M;
}

int main() {
    scanf("%d", &n);
    inv[0] = inv[1] = 1;
    for (int i = 2; i < M; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
    for (int i = 0; i < n; ++i) h[i] = c[i] = 1;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int x = 0;
            scanf("%d", &x);
            p[i][j] = x * inv[10000] % M;
            ip[i][j] = inv[p[i][j]];
        }
    X = 1, Y = 1;
    for (int i = 0; i < n; ++i) {
        X = X * p[i][i] % M;
        Y = Y * p[i][n - i - 1] % M;
    }

    int ans = ((solve(0, 0) - solve(0, 1) - solve(1, 0) + solve(1, 1)) % M + M) % M;
    ans = (ans + 1) % M;
    printf("%d\n", ans);
    return 0;
}

/*----------------------------------------------------------------
11544
23172
747
18715
19405
6308
838
0
1, -25688
3686
8480
20450
0
26162
0
0
0
31133, 19799
11112
26010
5574
0
15936
0
0
0
17858, -26806
12997
2377
0
0
2124
0
0
0
11968, -8496
16491
*/