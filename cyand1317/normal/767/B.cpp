#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXN = 100004;

int64 ts, tf, t;
int n;
int64 p[MAXN];

int main()
{
    scanf("%I64d%I64d%I64d", &ts, &tf, &t);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%I64d", &p[i]);

    tf -= ts;
    for (int i = 0; i < n; ++i) p[i] -= ts;

    int64 next_free = 0;
    std::pair<int64, int64> best = std::make_pair(1LL << 61, 0);
    // Come before the i-th visitor
    for (int i = 0; i < n; ++i) {
        int64 accepted = std::max(next_free, p[i] - 1);
        if (accepted >= tf) break;
        best = std::min(best, std::make_pair(accepted - (p[i] - 1), p[i] - 1));
        next_free = std::max(next_free + t, p[i] + t);
    }
    // Come after everyone has been served
    if (next_free + t <= tf) best = std::min(best, std::make_pair(0LL, next_free));

    printf("%I64d\n", best.second + ts);
    return 0;
}