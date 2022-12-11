#include <cstdio>
#include <cmath>
typedef long long int64;

inline int gcd(const int a, const int b) { return b == 0 ? a : gcd(b, a % b); }

int n, a, b;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        int x = (int)floorl(cbrtl((long double)a * b));
        int g = gcd(a, b);
        puts((int64)x * x * x == (int64)a * b && (int64)g * g % a == 0 && (int64)g * g % b == 0 ? "Yes" : "No");
    }

    return 0;
}