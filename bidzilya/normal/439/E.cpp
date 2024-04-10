#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

const int modulo = 1e9 + 7;
const int max_n = 1e5 + 100;

int n, f;

int bin_pow(int x, int pw)
{
    if (pw == 0) return 1;
    if ((pw & 1) == 1) return (1LL * x * bin_pow(x, pw - 1)) % modulo;
    return bin_pow((1LL * x * x) % modulo, pw >> 1);
}

int inv(int x)
{
    return bin_pow(x, modulo - 2);
}

int fact[max_n];

int C(int n, int k)
{
    if (k > n) return 0;
    return (1LL * fact[n] * inv((1LL * fact[k] * fact[n - k]) % modulo)) % modulo;
}

int func(int n, int f)
{
    if (f > n) return 0;
    return C((n - f) + (f - 1), f - 1);
}

bool is_prime[max_n];

vector<int> d;

inline int bit(int mask, int i) 
{
    return (mask >> i) & 1;
}

int main()
{
    for (int i = 2; i < max_n; ++i) is_prime[i] = true;
    for (int i = 2; i * i < max_n; ++i)
        if (is_prime[i])
            for (int j = i * i; j < max_n; j += i)
                is_prime[j] = false;

    fact[0] = 1;
    for (int i = 1; i < max_n; ++i)
        fact[i] = (1LL * fact[i - 1] * i) % modulo;
        
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; ++test) {
        scanf("%d%d", &n, &f);
        d.clear();
        int nn = n;
        for (int i = 2; i * i <= nn; ++i)
            if (nn % i == 0) {
                d.push_back(i);
                while (nn % i == 0) nn /= i;
            }
        if (nn > 1) {
            d.push_back(nn);
        }
        sort(d.begin(), d.end());
        int ans = 0;
        for (int mask = 0; mask < (1 << d.size()); ++mask) {
            int bits = 0;
            int mult = 1;
            for (int i = 0; i < (int) d.size(); ++i) 
                if (bit(mask, i)) {
                    ++bits;
                    mult *= d[i];
                }
            if ((bits & 1) == 1) {
                ans -= func(n / mult, f);
                if (ans < 0) ans += modulo;
            } else {
                ans += func(n / mult, f);
                if (ans >= modulo) ans -= modulo;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}