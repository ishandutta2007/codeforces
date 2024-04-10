#include <cstdio>
#include <cstring>
#include <utility>
typedef long long int64;
static const int64 INF64 = (1LL << 62);
static const int MAXN = 100005;
template <typename T> inline void update_max(T &var, const T val) {
    if (var < val) var = val;
}

int n, q;
int c[MAXN], v[MAXN];
int64 f[MAXN];
std::pair<int64, int> m1, m2, t;

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
    for (int i = 0; i < n; ++i) { scanf("%d", &c[i]); --c[i]; }

    int a, b;
    int64 diff_max, cur, ans;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &a, &b);
        memset(f, 0x80, sizeof f);
        m1 = m2 = std::make_pair(0LL, -1);
        for (int j = 0; j < n; ++j) {
            cur = f[c[j]];
            diff_max = (m1.second != c[j] ? m1.first : m2.first);
            update_max(cur, f[c[j]] + (int64)v[j] * a);
            update_max(cur, diff_max + (int64)v[j] * b);
            f[c[j]] = cur;
            t = std::make_pair(cur, c[j]);
            if (m1.second == t.second) { m1 = m2; m2 = std::make_pair(0LL, -1); }
            if (m2.second == t.second) { m2 = std::make_pair(0LL, -1); }
            if (t > m1) { m2 = m1; m1 = t; }
            else if (t > m2) m2 = t;
        }
        ans = 0;
        for (int i = 0; i < n; ++i) update_max(ans, f[i]);
        printf("%I64d\n", ans);
    }

    return 0;
}