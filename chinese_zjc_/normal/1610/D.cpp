// This code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int MOD = 1000000007;
int n, ans, pow2[200005];
std::vector<int> a;
void erase()
{
    std::vector<int> res;
    for (auto i : a)
        if (i % 2 == 0)
            res.push_back(i / 2);
    a.swap(res);
    n = a.size();
}
void add(int &A, int B) { A = (A + B) % MOD; }
void sub(int &A, int B) { A = (A + MOD - B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    pow2[0] = 1;
    for (int i = 1; i <= n; ++i)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    a.assign(n, 0);
    for (int i = 0; i != n; ++i)
        std::cin >> a[i];
    add(ans, pow2[n] - 1);
    erase();
    sub(ans, pow2[n] - 1);
    while (n)
    {
        int tmp = n;
        erase();
        tmp -= n;
        if (tmp > 1)
            add(ans, (pow2[tmp - 1] - 1ll) * pow2[n] % MOD);
    }
    std::cout << ans << std::endl;
    return 0;
}