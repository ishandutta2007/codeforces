#include <cstdio>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
typedef long long int64;
static const int MAXN = 300005;

int n;
int64 limak;
std::pair<int64, int64> t[MAXN];
std::priority_queue<
    int64, std::vector<int64>, std::greater<int64>
> floats;

inline bool team_cmp(const std::pair<int64, int64> &lhs, const std::pair<int64, int64> &rhs) {
    return lhs.first > rhs.first;
}

int main()
{
    scanf("%d", &n); --n;
    scanf("%I64d%*I64d", &limak);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &t[i].first, &t[i].second);
        t[i].second -= (t[i].first - 1);
    }
    std::sort(t, t + n, team_cmp);

    int p;
    for (p = 0; p < n && t[p].first > limak; ++p) floats.push(t[p].second);
    int best = p, cur = p;
    while (!floats.empty()) {
        int64 r = floats.top(); floats.pop();
        if (limak < r) break;
        limak -= r;
        --cur;
        for (; p < n && t[p].first > limak; ++p) floats.push(t[p].second), ++cur;
        if (best > cur) best = cur;
    }

    printf("%d\n", best + 1);
    return 0;
}