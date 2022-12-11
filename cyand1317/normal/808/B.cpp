#include <cstdio>
#include <algorithm>
static const int MAXN = 2e5 + 4;

int n, k;
int a[MAXN];

double sum = 0;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    if (n >= k * 2) {
        for (int i = 0; i < n; ++i)
            sum += (double)a[i] * std::min(std::min(k, i + 1), n - i);
    } else {
        for (int i = 0; i < n - k; ++i) {
            sum += (double)a[i] * (i + 1);
            sum += (double)a[n - i - 1] * (i + 1);
        }
        for (int i = n - k; i < k; ++i)
            sum += (double)a[i] * (n - k + 1);
    }
    sum /= (n - k + 1);
    printf("%.8lf\n", sum);

    return 0;
}