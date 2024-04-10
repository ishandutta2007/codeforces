#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))
#define cnt1(x) (__builtin_popcount(x))

template<class T>
inline void chkmax(T& x, T y) {
    if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
    if (y < x) x = y;
}

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef long long LL;
const int MX = 200005;
const int M = 1000000007;
LL inv[MX], f[MX], g[MX];

void init() {
    int i;
    
    inv[1] = 1;
    for (i = 2; i < MX; i++) inv[i] = inv[M % i] * (M - M / i) % M;
    
    f[0] = g[0] = 1;
    for (i = 1; i < MX; i++) {
        f[i] = f[i - 1] * i % M;
        g[i] = g[i - 1] * inv[i] % M;
    }
}

LL C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return f[n] * g[k] % M * g[n - k] % M;
}

const int MN = 2005;
int h, w, n;
PII p[MN];
int dp[MN];

int main() {
    
    int i, j, x, y, u, v;
    LL val;
    
    init();
    
    scanf("%d%d%d", &h, &w, &n);
    for (i = 0; i < n; i++) scanf("%d%d", &p[i].fi, &p[i].se);
    
    sort(p, p + n);
    p[n] = PII(h, w);
    for (i = 0; i <= n; i++) {
        x = p[i].fi, y = p[i].se;
        val = C(x + y - 2, x - 1);
        for (j = 0; j < i; j++) {
            u = p[j].fi, v = p[j].se;
            val -= dp[j] * C(x + y - u - v, x - u) % M;
        }
        dp[i] = (val % M + M) % M;
    }
    printf("%d\n", dp[n]);
    return 0;
}