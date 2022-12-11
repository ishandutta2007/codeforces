#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 200003;

int n;
int x[MAXN], y[MAXN];
int a[MAXN], b[MAXN];
std::pair<int, int> pos[MAXN];
int p[MAXN];

template <typename T> int chop_blocks(T *a, int *b)
{
    int b_top = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) ++j;
        b[b_top++] = j - i;
        i = j;
    }
    return b_top;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        pos[i] = std::make_pair(x[i], y[i]);
    }
    std::sort(x, x + n);
    std::sort(y, y + n);
    std::sort(pos, pos + n);
    int a_ct = chop_blocks(x, a);
    int b_ct = chop_blocks(y, b);
    int p_ct = chop_blocks(pos, p);

    long long ans = 0;
    for (int i = 0; i < a_ct; ++i) ans += (long long)a[i] * (a[i] - 1) / 2;
    for (int i = 0; i < b_ct; ++i) ans += (long long)b[i] * (b[i] - 1) / 2;
    for (int i = 0; i < p_ct; ++i) ans -= (long long)p[i] * (p[i] - 1) / 2;
    printf("%I64d\n", ans);

    return 0;
}