#include <cstdio>
static const int MAXN = 200004;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n;
int a[MAXN], s[MAXN];
int f[MAXN], max_val;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    s[0] = a[0]; for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];

    f[n - 1] = 0; max_val = s[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        f[i] = max_val;
        max_val = max(max_val, s[i] - f[i]);
    }

    printf("%d\n", f[0]);
    return 0;
}