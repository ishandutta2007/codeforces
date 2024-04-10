// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
#define int long long
const int MOD = 998244353;
int w, h;
int power(int A, int B)
{
    int res = 1;
    while (B)
    {
        if (B & 1)
            res = res * A % MOD;
        B >>= 1;
        A = A * A % MOD;
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> w >> h;
    std::cout << power(2, w + h) << std::endl;
    return 0;
}