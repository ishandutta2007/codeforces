#include <cstdio>
#include <algorithm>

int r, d;
int n, x, y, u;

inline int sqr(int x) { return x * x; }

int main()
{
    scanf("%d%d", &r, &d);
    scanf("%d", &n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &u);
        int dsq = x * x + y * y;
        if (u * 2 <= d && dsq >= sqr((r - d) + u) && dsq <= sqr(r - u)) {
            ++ans;
        }
    }

    printf("%d\n", ans);
    return 0;
}