#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 2e5 + 4;

int n;
int a[MAXN];
std::pair<int, int> b[MAXN];
int c[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) { scanf("%d", &b[i].first); b[i].second = i; }

    std::sort(a, a + n);
    std::reverse(a, a + n);
    std::sort(b, b + n);
    for (int i = 0; i < n; ++i) c[b[i].second] = a[i];
    for (int i = 0; i < n; ++i) printf("%d%c", c[i], i == n - 1 ? '\n' : ' ');

    return 0;
}