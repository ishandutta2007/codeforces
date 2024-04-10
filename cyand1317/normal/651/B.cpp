#include <cstdio>
#include <algorithm>
static const int MAXN = 1004;

int n;
int a[MAXN], b[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);

    int b_top = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && a[j] == a[i]) ++j;
        b[b_top++] = j - i;
        i = j;
    }
    int ans = 0;
    int p = 0, q;
    --n; --b[0];
    while (n--) {
        q = p;
        do q = (q + 1) % b_top; while (b[q] == 0);
        --b[q];
        if (q > p) ++ans;
        p = q;
    }
    printf("%d\n", ans);

    return 0;
}