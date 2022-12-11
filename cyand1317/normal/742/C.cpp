#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 104;
template <typename T> T gcd(const T a, const T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T> T lcm(const T a, const T b) { return a / gcd(a, b) * b; }

int n;
int crush[MAXN];
bool vis[MAXN] = { false };

int main()
{
    scanf("%d", &n);
    int crushed_ct = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &crush[i]);
        --crush[i];
        if (!vis[crush[i]]) { vis[crush[i]] = true; ++crushed_ct; }
    }
    if (crushed_ct < n) { puts("-1"); return 0; }

    memset(vis, 0, sizeof vis);
    int64 ans = 1;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        int w = i, len = 0;
        do { w = crush[w]; ++len; } while (w != i);
        if (len % 2 == 0) len /= 2;
        ans = lcm<int64>(ans, len);
    }

    printf("%I64d\n", ans);
    return 0;
}