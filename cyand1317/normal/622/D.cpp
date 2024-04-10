#include <cstdio>
static const int MAXN = 500004;

int n;
int a[MAXN * 2] = { 0 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
        if (i % 2 == 0) {
            a[i / 2] = a[n - 1 - i / 2] = i + 1;
        } else {
            a[n + i / 2] = a[n + n - 2 - i / 2] = i + 1;
        }
    for (int i = 0; i < n + n; ++i)
        printf("%d%c", a[i] == 0 ? n : a[i], i == n + n - 1 ? '\n' : ' ');

    return 0;
}