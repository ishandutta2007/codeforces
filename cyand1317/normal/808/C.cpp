#include <cstdio>
#include <algorithm>
static const int MAXN = 104;

int n, w;
struct cup { int id, vol, cnt; } c[MAXN];
inline bool operator < (const cup &lhs, const cup &rhs) { return lhs.vol < rhs.vol; }

int ans[MAXN];

int main()
{
    scanf("%d%d", &n, &w);

    for (int i = 0; i < n; ++i) {
        c[i].id = i;
        scanf("%d", &c[i].vol);
        c[i].cnt = (c[i].vol + 1) / 2;
        w -= c[i].cnt;
    }
    if (w < 0) { puts("-1"); return 0; }

    std::sort(c, c + n);
    for (int i = n - 1; w > 0 && i >= 0; --i) {
        int inc = std::min(w, c[i].vol - c[i].cnt);
        c[i].cnt += inc; w -= inc;
    }

    for (int i = 0; i < n; ++i) ans[c[i].id] = c[i].cnt;
    for (int i = 0; i < n; ++i) printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');

    return 0;
}