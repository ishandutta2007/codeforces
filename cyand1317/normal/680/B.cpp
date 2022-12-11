#include <cstdio>
#include <algorithm>
static const int MAXN = 106;

int n, a;
int t[MAXN];
int confirmed[MAXN];

int main()
{
    scanf("%d%d", &n, &a); --a;
    for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
    for (int i = 0; i < n; ++i) confirmed[i] = true;
    for (int i = 0; i <= std::min(a, n - a - 1); ++i) {
        if (t[a - i] + t[a + i] != 2)
            confirmed[a - i] = confirmed[a + i] = false;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += t[i] * confirmed[i];
    printf("%d\n", ans);
    return 0;
}