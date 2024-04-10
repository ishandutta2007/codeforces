#include <cstdio>
static const int INF = 0x7fffffff;

int n, a;

int main()
{
    int min = INF, max = -INF, min_ct = 0, max_ct = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (min > a) { min = a; min_ct = 0; }
        if (min == a) ++min_ct;
        if (max < a) { max = a; max_ct = 0; }
        if (max == a) ++max_ct;
    }
    printf("%d\n", n - (min == max ? min_ct : (min_ct + max_ct)));
    return 0;
}