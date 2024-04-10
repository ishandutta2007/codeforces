#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
typedef long long int64;
static const int MAXN = 1e5 + 4;

int n, m, q;
int a[MAXN], b[MAXN];
std::set<int64> b_vals;

inline int64 min_diff(int64 a_val)
{
    std::set<int64>::iterator
        p = b_vals.lower_bound(a_val),
        q = b_vals.upper_bound(a_val);
    int64 ans = 1LL << 61;
    if (p != b_vals.end()) ans = std::min(ans, std::abs(*p - a_val));
    if (q != b_vals.begin()) ans = std::min(ans, std::abs(*(--q) - a_val));
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

    int64 a_val = 0, b_val = 0;
    for (int i = 0; i < n; ++i) a_val += (a[i] * (i % 2 == 0 ? +1 : -1));
    for (int i = 0; i < n; ++i) b_val += (b[i] * (i % 2 == 0 ? -1 : +1));
    for (int i = 0; i <= m - n; ++i) {
        b_vals.insert(-b_val);
        b_val = -(b_val + b[i]) + b[i + n] * ((n - 1) % 2 == 0 ? -1 : +1);
    }

    printf("%I64d\n", min_diff(a_val));
    for (int i = 0, l, r, x; i < q; ++i) {
        scanf("%d%d%d", &l, &r, &x); --l, --r;
        if (l % 2 == r % 2)
            a_val += x * (l % 2 == 0 ? +1 : -1);
        printf("%I64d\n", min_diff(a_val));
    }

    return 0;
}