#include <cstdio>
typedef long long int64;
int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }
int64 lcm(int64 a, int64 b) { return a / gcd(a, b) * b; }

int n, k, ci;

int main()
{
    scanf("%d%d", &n, &k);
    int64 g = 1;
    do {
        scanf("%d", &ci);
        g = gcd(k, lcm(g, ci));
    } while (--n);
    puts(g == k ? "Yes" : "No");
    return 0;
}