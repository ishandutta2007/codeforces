#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int64 INF64 = (1LL << 62);
static const int MAXN = 100005;
template <typename T> inline bool update_max(T &var, const T val) {
    if (var < val) { var = val; return true; } else return false;
}

int n, u, cf, cm;
int64 m;
int a[MAXN];

std::pair<int, int> p[MAXN];
int64 sum[MAXN];

inline int64 lift_cost(int perfect, int height) {
    int lo = 0, hi = perfect, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (p[mid].first < height) lo = mid; else hi = mid;
    }
    return (int64)height * (lo + 1) - sum[lo + 1];
}

int main()
{
    scanf("%d%d%d%d%I64d", &n, &u, &cf, &cm, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) p[i] = std::make_pair(a[i], i);
    std::sort(p, p + n);

    sum[0] = 0;
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + p[i].first;

    int64 max_force = (int64)p[0].first * cm;
    for (int i = n - 1; i >= 0; --i)
        if (p[i].first == u) max_force += cf; else break;
    int lift = -1, perfect = n;
    for (int i = n; i >= 0; --i) {
        int64 remain = m - ((int64)u * (n - i) - (sum[n] - sum[i]));
        if (remain < 0) break;
        if (i == 0) {
            if (update_max(max_force, (int64)n * cf + (int64)u * cm)) {
                lift = u; perfect = 0;
            }
            break;
        }

        int lo = p[0].first, hi = u + 1, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (lift_cost(i, mid) <= remain) lo = mid;
            else hi = mid;
        }
        if (update_max(max_force, (int64)(n - i) * cf + (int64)lo * cm)) {
            lift = lo; perfect = i;
        }
    }

    for (int i = 0; i < n; ++i)
        if (p[i].first < lift) p[i].first = lift; else break;
    for (int i = perfect; i < n; ++i) p[i].first = u;
    printf("%I64d\n", max_force);
    for (int i = 0; i < n; ++i) a[p[i].second] = p[i].first;
    for (int i = 0; i < n; ++i) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}