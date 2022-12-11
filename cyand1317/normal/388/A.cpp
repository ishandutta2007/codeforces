#include <cstdio>
#include <algorithm>
static const int MAXN = 128;

int n;
int x[MAXN];

bool feasible(int p)
{
    for (int i = 0; i < n; ++i)
        if (x[i] < i / p) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
    std::sort(x, x + n);

    int lo = 0, hi = n, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (feasible(mid)) hi = mid;
        else lo = mid;
    }
    printf("%d\n", hi);

    return 0;
}