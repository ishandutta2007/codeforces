#include <cstdio>
#include <algorithm>
static const int MAXN = 200004;

int n;
int a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i] -= (n - i);
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        a[i] += (n - i);
        if (a[i] < 0 || (i > 0 && a[i] < a[i - 1])) {
            puts(":("); return 0;
        }
    }
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}