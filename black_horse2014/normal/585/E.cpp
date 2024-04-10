#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef unsigned int uint;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;
typedef long double LD;

#define pb push_back
#define mset(a, b) (memset(a, b, sizeof a))
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define X first
#define Y second

template <typename T, typename U>
inline void chkmax(T& x, U y) {
    if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
    if (y < x) x = y;
}

const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int MX = 1e7 + 5;

int b[N], p[MX], c[MX], g[MX], sgn[MX], d[10005], q[100005];
int main() {

    int n;
    scanf("%d", &n);

    b[0] = 1;
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] * 2 % M;

    for (int i = 1; i < MX; i++) p[i] = i;
    for (int i = 2; i * i < MX; i++) if (p[i] == i) {
        for (int j = i * i; j < MX; j += i) p[j] = i;
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int dn = 0;
        while (x > 1) {
            d[dn++] = p[x];
            x /= p[x];
        }
        sort(d, d + dn);
        dn = unique(d, d + dn) - d;
        q[0] = 1, sgn[1] = 1;
        for (int j = 1; j < bit(dn); j++) {
            q[j] = q[j ^ (j & -j)] * d[__builtin_ctz(j)];
            c[q[j]]++;
            if (__builtin_popcount(j) % 2 == 1) sgn[q[j]] = -1;
            else sgn[q[j]] = 1;
        }
    }

    c[1] = n;
    int cnt = 0;
    for (int i = 1; i < MX; i++) if (c[i]) {
        int cur = (b[c[i]] - 1 + M) % M;
        g[i] = 1LL * c[i] * (b[c[i] - 1] - 1 + M) % M;
        if (sgn[i] == 1) cnt = (cnt + cur) % M;
        else cnt = (cnt - cur + M) % M;
    }

    int ans = 1LL * n * (b[n - 1] - 1) % M, tot = 0;
    for (int i = 2; i < MX; i++) if (c[i]) {
        if (sgn[i] == 1) ans = (ans + g[i]) % M;
        else ans = (ans - g[i] + M) % M;
    }

    ans = (2LL * ans - 1LL * cnt * n % M + M) % M;
    printf("%d\n", ans);

    return 0;
}