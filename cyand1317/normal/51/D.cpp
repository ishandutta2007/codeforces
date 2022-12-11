#include <cstdio>
typedef long long int64;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T min(const T a, const T b, const T c) { return min(a, min(b, c)); }
static const int MAXN = 1e5 + 6;

int n;
int a[MAXN];

int check(int a0, int a1, int p, bool skipped)
{
    for (; p < n; ++p) {
        if (!(a0 == 0 && a1 != 0) && !(a1 == 0 && a[p] != 0) && (int64)a[p] * a0 == (int64)a1 * a1) {
            a0 = a1; a1 = a[p];
        } else if (!skipped) {
            skipped = true;
        } else return 2;
    }
    return (skipped ? 1 : 0);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n <= 2) { puts((n == 2 && a[0] == 0 && a[1] != 0) ? "1" : "0"); return 0; }
    printf("%d\n", min(
        check(a[0], a[1], 2, false),
        check(a[0], a[2], 3, true),
        check(a[1], a[2], 3, true)
    ));
    return 0;
}