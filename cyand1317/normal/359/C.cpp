#include <cstdio>
#include <algorithm>
#include <map>
#include <numeric>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MODULUS = 1e9 + 7;
#define _  % MODULUS
#define __ %= MODULUS

int n, x;
int a[MAXN];

inline int fpow(int base, int64 exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) { if (exp & 1) (ans *= base)__; base = (int64)base * base _; }
    return (int)ans;
}
inline int inv(int x) { return fpow(x, MODULUS - 2); }

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    //for (int i = 0; i < n; ++i) a[i] = i + 987654321;

    int largest = *std::max_element(a, a + n);
    int64 deno_sum_pow = std::accumulate(a, a + n, 0LL);

    std::map<int64, int> pow_ct;
    int64 num_least_pow = -1;
    for (int i = 0; i < n; ++i) ++pow_ct[deno_sum_pow - a[i]];
    for (std::map<int64, int>::iterator i = pow_ct.begin(); i != pow_ct.end(); ++i)
        if (i->second % x == 0) {
            pow_ct[i->first + 1] += i->second / x;
            i->second = 0;
        } else { num_least_pow = i->first; break; }

    printf("%d\n", fpow(x, std::min(deno_sum_pow, num_least_pow)));
    return 0;
}