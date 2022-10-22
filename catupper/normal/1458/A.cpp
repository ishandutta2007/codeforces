#include <algorithm>
#include <cstdio>

using namespace std;
typedef long long Int;

Int gcd(Int a, Int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

Int n, m, a[220000], b;

int main()
{
    scanf("%lld%lld", &n, &m);
    for (Int i = 0; i < n; i++)
        scanf("%lld", a + i);

    Int g = 0;
    for (Int i = n - 1; i > 0; i--) {
        g = gcd(g, abs(a[i] - a[i - 1]));
    }
    for (int i = 0; i < m; i++) {
        if (i)
            putchar(' ');
        scanf("%lld", &b);
        printf("%lld", gcd(b + a[0], g));
    }
    puts("");
    return 0;
}