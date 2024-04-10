#include <cstdio>
#include <algorithm>
static const int MAXSZ = 100005;

int n, m, k;
int a[MAXSZ];
int tail[MAXSZ];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &a[j * n + i]);
    std::swap(m, n);
    //for (int i = 0; i < n; ++i)
    //    for (int j = 0; j < m; ++j) printf("%d%c", a[i * m + j], j == m - 1 ? '\n' : ' ');
    scanf("%d", &k);
    if (m == 1) {   // originally n = 1
        for (int i = 0; i < k; ++i) puts("Yes"); return 0;
    }

    for (int i = 0; i < n; ++i) {
        int cur = 1;
        for (int j = 0; j < m; ) {
            while (cur < m && a[i * m + cur - 1] <= a[i * m + cur]) ++cur;
            for (; j < cur; ++j) tail[i * m + j] = cur;
            ++cur;
        }
    }
    //for (int i = 0; i < n; ++i)
    //    for (int j = 0; j < m; ++j) printf("%d%c", tail[i * m + j], j == m - 1 ? '\n' : ' ');
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < m; ++j) tail[j] = std::max(tail[j], tail[i * m + j]);

    int l, r;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &l, &r); --l, --r;
        puts(tail[l] > r ? "Yes" : "No");
    }

    return 0;
}