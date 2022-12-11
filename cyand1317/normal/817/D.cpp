#include <cstdio>
typedef long long int64;
static const int MAXN = 1e6 + 4;

int n, a[MAXN];
int l[MAXN], r[MAXN];

void stretch()
{
    static int s[MAXN], top;
    top = 1; s[0] = 0; l[0] = -1;
    for (int i = 1; i < n; ++i) {
        while (top > 0 && a[s[top - 1]] <= a[i]) --top;
        l[i] = (top == 0 ? -1 : s[top - 1]);
        s[top++] = i;
    }
    top = 1; s[0] = n - 1; r[n - 1] = n;
    for (int i = n - 2; i >= 0; --i) {
        while (top > 0 && a[s[top - 1]] < a[i]) --top;
        r[i] = (top == 0 ? n : s[top - 1]);
        s[top++] = i;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int64 ans = 0;
    stretch();
    for (int i = 0; i < n; ++i)
        ans += (int64)a[i] * (r[i] - i) * (i - l[i]);
    for (int i = 0; i < n; ++i) a[i] = -a[i];
    stretch();
    for (int i = 0; i < n; ++i)
        ans += (int64)a[i] * (r[i] - i) * (i - l[i]);
    printf("%I64d\n", ans);

    return 0;
}