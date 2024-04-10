#include <cstdio>
#include <map>
#include <utility>
template <typename T> inline T gcd(const T a, const T b) { return b == 0 ? a : gcd(b, a % b); }
typedef std::pair<int, int> fraction;
#define num   first
#define deno  second
inline fraction simplify(const int n, const int d) {
    int g = gcd(n, d);
    return fraction(n / g, d / g);
}
inline fraction simplify(const fraction &x) {
    int g = gcd(x.num, x.deno);
    return fraction(x.num / g, x.deno / g);
}
inline fraction inverse(const fraction &x) {
    return fraction(x.deno, x.num);
}
static const int MAXX = 1e5 + 4;
typedef long long int64;

int maxx, maxy, w;
int rev[MAXX];
fraction ratio[MAXX];
std::multimap<fraction, int> indexer;

namespace fwk {
    int f[MAXX] = { 0 };
    inline void add(int pos, int inc = +1) {
        for (; pos < MAXX; pos += (pos & -pos)) f[pos] += inc;
    }
    inline int64 sum(int rg) {
        int64 ans = 0;
        for (; rg; rg -= (rg & -rg)) ans += f[rg];
        return ans;
    }
}

int main()
{
    scanf("%d%d%d", &maxx, &maxy, &w);

    for (int i = 1; i < MAXX; ++i) {
        int j = i; rev[i] = 0;
        while (j) { rev[i] = rev[i] * 10 + (j % 10); j /= 10; }
        ratio[i] = simplify(i, rev[i]);
    }
    for (int i = 1; i <= maxy; ++i) indexer.insert(std::make_pair(ratio[i], i));

    std::pair<int, int> ans = std::make_pair(MAXX, MAXX);
    std::multimap<fraction, int>::iterator p, q;
    for (int i = 1; i <= maxx; ++i) {
        fraction r = inverse(ratio[i]);
        p = indexer.lower_bound(r);
        q = indexer.upper_bound(r);
        for (; p != q; ++p) fwk::add(p->second, +1);
        int lo = 0, hi = maxy + 1, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (fwk::sum(mid) >= w) hi = mid; else lo = mid;
        }
        // (i, hi)
        if (hi <= maxy && (int64)i * hi <= (int64)ans.first * ans.second)
            ans = std::make_pair(i, hi);
    }

    if (ans.first == MAXX) puts("-1");
    else printf("%d %d\n", ans.first, ans.second);
    return 0;
}