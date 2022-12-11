#include <cstdio>
#include <cstdlib>
typedef long long int64;
static const int MAXN = 100006;

int n, q;
int a[MAXN];

int64 subarray_max_sum(int l, int r)
{
    if (l > r) return 0;
    int *a = ::a + l;
    int n = r - l + 1;
    //for (int i = 0; i < n; ++i)
    //    printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    static int s[MAXN], top, exp_l[MAXN], exp_r[MAXN];

    s[0] = 0; top = 1;
    exp_l[0] = 0;
    for (int i = 1; i < n; ++i) {
        while (top > 0 && a[s[top - 1]] <= a[i]) --top;
        exp_l[i] = (top == 0 ? 0 : s[top - 1] + 1);
        s[top++] = i;
    }
    s[0] = n - 1; top = 1;
    exp_r[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        while (top > 0 && a[s[top - 1]] < a[i]) --top;
        exp_r[i] = (top == 0 ? n - 1 : s[top - 1] - 1);
        s[top++] = i;
    }

    int64 ans = 0;
    //for (int i = 0; i < n; ++i)
    //    printf(" (%d) %d %d\n", a[i], exp_l[i], exp_r[i]);
    for (int i = 0; i < n; ++i)
        ans += (int64)a[i] * (exp_r[i] - i + 1) * (i - exp_l[i] + 1);
    return ans;
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = n - 1; i > 0; --i)
        a[i] = std::abs(a[i] - a[i - 1]);

    int l, r;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &l, &r);
        printf("%I64d\n", subarray_max_sum(l, r - 1));
    }

    return 0;
}