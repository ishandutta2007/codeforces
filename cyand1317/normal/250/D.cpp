#include <cstdio>
#include <cmath>
typedef long long int64;
static const int MAXN = 1e5 + 7;

int n, m, a, b;
int ly[MAXN], ry[MAXN], rlen[MAXN];
double dist[MAXN];
int selc[MAXN];

inline double straight(int lbank, int rbank)
{
    return sqrt((int64)a * a + (int64)ly[lbank] * ly[lbank]) +
        sqrt((int64)(b - a) * (b - a) + (int64)(ry[rbank] - ly[lbank]) * (ry[rbank] - ly[lbank]));
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    for (int i = 0; i < n; ++i) scanf("%d", &ly[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &ry[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &rlen[i]);

    // Can be optimized to be linear but let's hope O(n log n) will be fast enough
    for (int i = 0; i < m; ++i) {
        selc[i] = -1;
        double intersection = (double)ry[i] / b * a;
        int lo = 0, hi = n, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (ly[mid] > intersection) hi = mid; else lo = mid;
        }
        double s1 = straight(lo, i), s2 = 1e18;
        if (lo + 1 < n)  s2 = straight(lo + 1, i);
        if (s1 < s2) { selc[i] = lo; dist[i] = s1; }
        else { selc[i] = lo + 1; dist[i] = s2; }
    }

    double best = 1e18;
    int rselc = -1;
    for (int i = 0; i < m; ++i) if (best > dist[i] + rlen[i]) {
        best = dist[i] + rlen[i];
        rselc = i;
    }

    printf("%d %d\n", selc[rselc] + 1, rselc + 1);
    return 0;
}