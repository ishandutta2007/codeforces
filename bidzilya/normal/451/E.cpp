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

int bin_pow(int x, int pw)
{
    if (pw == 0) return 1;
    if ((pw & 1) == 1)
        return (1LL * x * bin_pow(x, pw - 1)) % modulo;
    return bin_pow((1LL * x * x) % modulo, pw >> 1);
}

int inv(int x)
{
    return bin_pow(x, modulo - 2);
}

const int max_n = 222;

int pre_calc_inv[max_n];

int C(ll n, int k)
{
    if (k > n) return 0;
    int res = 1;
    for (ll i = n - k + 1; i <= n; ++i)
        res = (1LL * (i % modulo) * res) % modulo;
    for (int i = 2; i <= k; ++i)
        res = (1LL * res * pre_calc_inv[i]) % modulo;
    return res;
}

int n;
ll f[max_n];
ll s;

inline int bit(int mask, int i)
{
    return (mask >> i) & 1;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    for (int i = 1; i < max_n; ++i)
        pre_calc_inv[i] = inv(i);

    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> f[i];

    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int bits = 0;
        for (int i = 0; i < n; ++i) 
            bits += bit(mask, i);
        ll os = s;
        for (int i = 0; i < n; ++i)
            if (bit(mask, i)) 
                os -= (f[i] + 1);
        if (os < 0) continue;
        int res = C(os + n - 1, n - 1);
        if ((bits & 1) == 1) {
            ans -= res;
            if (ans < 0) ans += modulo;
        } else {
            ans += res;
            if (ans >= modulo) ans -= modulo;
        }
    }
    
    cout << ans << endl;

    return 0;
}