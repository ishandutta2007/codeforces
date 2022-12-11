#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 100004;

int n, a, b;
std::pair<int, int> t[MAXN];
int f[MAXN];

inline bool pair_cmp_1(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first < rhs.first);
}
inline bool pair_cmp_2(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
    return (lhs.first == rhs.first) ? (lhs.second < rhs.second) : (lhs.first > rhs.first);
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i].first);
        t[i].second = i;
    }
    if (a != b) std::sort(t, t + n, a > b ? pair_cmp_1 : pair_cmp_2);

    for (int i = 0; i < a; ++i) f[t[i].second] = 1;
    for (int i = a; i < n; ++i) f[t[i].second] = 2;

    for (int i = 0; i < n; ++i) printf("%d%c", f[i], i == n - 1 ? '\n' : ' ');
    return 0;
}