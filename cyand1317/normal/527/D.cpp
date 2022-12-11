#include <cstdio>
#include <algorithm>
static const int MAXN = 200003;
static const int INF = 1e9 + 233;

struct point { int x, w; };
inline bool operator < (point a, point b)
{ return a.x + a.w < b.x + b.w; }

int main()
{
    point p[MAXN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].w);
    std::sort(p, p + n);

    int ans = 0, last = -INF;
    for (int i = 0; i < n; ++i)
        if (p[i].x - p[i].w >= last) {
            ++ans;
            last = p[i].x + p[i].w;
        }
    printf("%d\n", ans);
    return 0;
}