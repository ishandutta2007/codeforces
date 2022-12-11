#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 100006;

int n, d;
std::pair<int, int> f[MAXN];

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) scanf("%d%d", &f[i].first, &f[i].second);
    std::sort(f, f + n);

    long long ans = 0, cur_ans = 0;
    int head = 0, tail = 0;
    while (head < n && f[head].first < f[tail].first + d) cur_ans += f[head++].second;
    ans = cur_ans;
    while (head < n) {
        cur_ans -= f[tail++].second;
        while (head < n && f[head].first < f[tail].first + d) cur_ans += f[head++].second;
        if (ans < cur_ans) ans = cur_ans;
    }
    printf("%I64d\n", ans);
    return 0;
}