#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long int64;
template <typename T> inline T gcd(const T a, const T b) { return (b == 0) ? a : gcd(b, a % b); }

int64 x, y;
std::vector<int64> xf;

int main()
{
    scanf("%I64d%I64d", &x, &y);
    int64 g = gcd(x, y);

    for (int i = 1; (int64)i * i <= x; ++i) if (x % i == 0) {
        if (i >= g) xf.push_back(i);
        if ((int64)i * i != x && x / i >= g) xf.push_back(x / i);
    }
    std::sort(xf.begin(), xf.end());

    int64 ans = 0;
    for (int i = 0; i < xf.size() && y != 0; ) {
        int64 next = 0;
        for (int j = i + 1; j < xf.size(); ++j)
            if ((y - (y / xf[j]) * xf[j]) % xf[i] == 0)
                next = std::max(next, (y / xf[j]) * xf[j]);
        ans += (y - next) / xf[i];
        y = next;
        g = gcd(x, y);
        while (i < xf.size() && xf[i] != g) ++i;
    }

    printf("%I64d\n", ans);
    return 0;
}