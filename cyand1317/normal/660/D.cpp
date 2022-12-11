// Wrote a long program involving fraction arithmetics...
// And found I misunderstood the problem... QwQ
#include <cstdio>
#include <cstdlib>
#include <map>
#include <utility>
typedef long long int64;
static const int MAXN = 2005;

int n;
int x[MAXN], y[MAXN];
typedef std::map<std::pair<int, int>, int> delta_colle;
delta_colle m;

inline std::pair<int, int> delta_pair(int dx, int dy)
{
    if (dx == 0) return std::make_pair(dx, std::abs(dy));
    else return dx < 0 ? std::make_pair(-dx, -dy) : std::make_pair(dx, dy);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            ++m[delta_pair(x[i] - x[j], y[i] - y[j])];
    int64 ans = 0;
    for (delta_colle::iterator i = m.begin(); i != m.end(); ++i)
        ans += i->second * (i->second - 1) / 2;
    printf("%I64d\n", ans / 2); // One parallelograms is counted twice
    return 0;
}