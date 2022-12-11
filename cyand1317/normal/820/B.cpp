#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
typedef long long int64;
static const int MAXN = 1e5 + 4;

struct fraction {
    int num, deno;
    fraction(int n = 0, int d = 1) : num(n), deno(d) { }
    inline bool operator < (const fraction &other) const {
        return (int64)num * other.deno < (int64)deno * other.num;
    }
    inline fraction operator - (const fraction &other) const {
        return fraction(num * other.deno - deno * other.num, deno * other.deno);
    }
    inline fraction abs() const {
        return fraction(std::abs(num), deno);
    }
};

int n, a;
fraction _a;

typedef std::pair<int, int> triangle;
typedef std::pair<fraction, triangle> result;

int main()
{
    scanf("%d%d", &n, &a);
    _a = fraction(a, 180);

    result ans(fraction(300, 1), triangle(-1, -1));
    for (int i = 1; i < n - 1; ++i) {
        ans = std::min(ans, result((_a - fraction(i, n)).abs(), triangle(i + 1, i)));
    }

    printf("1 %d %d\n", ans.second.first + 1, ans.second.second + 1);
    return 0;
}