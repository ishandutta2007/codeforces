#include <cstdio>
#include <algorithm>
static const int MAXN = 47;
static const int MAXK = 48;

int n, k, m;
int t[MAXK], task;

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < k; ++i) scanf("%d", &t[i]);
    std::sort(t, t + k);

    task = 0;
    for (int i = 0; i < k; ++i) task += t[i];

    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int m = ::m - task * i; // won't overflow
        if (m < 0) break;
        int cur = i * (k + 1);
        for (int j = 0; j < k; ++j) {
            int ct = std::min(n - i, m / t[j]);
            m -= ct * t[j];
            cur += ct;
        }
        ans = std::max(ans, cur);
    }

    printf("%d\n", ans);
    return 0;
}