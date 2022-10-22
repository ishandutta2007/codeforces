//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, MOD, fdown[505], ans;
std::vector<int> f;
int d(int, int, int, int *, int *);
int u(int l, int r, int sta, int *sum1, int *sum2)
{
    if (r < 0)
        return d(-r, -l, sta + (r - l), sum1, sum2);
    if (l < 0)
        return u(l, -1, sta, sum1, sum2) + u(0, r, sta + (0 - l), sum1, sum2);
    if (l == 0)
        return sum1[r] * (sta + (r + 1)) - sum2[r];
    return u(0, r, sta - l, sum1, sum2) - u(0, l - 1, sta - l, sum1, sum2);
}
int d(int l, int r, int sta, int *sum1, int *sum2)
{
    if (r < 0)
        return u(-r, -l, sta - (r - l), sum1, sum2);
    if (l < 0)
        return d(l, -1, sta, sum1, sum2) + d(0, r, sta - (0 - l), sum1, sum2);
    if (l == 0)
        return sum1[r] * (sta - (r + 1)) + sum2[r];
    return d(0, r, sta + l, sum1, sum2) - d(0, l - 1, sta + l, sum1, sum2);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> MOD;
    fdown[0] = 1;
    for (int i = 0; i != n; ++i)
        fdown[i + 1] = fdown[i] * (n - i) % MOD;
    f.push_back(1);
    if (n <= 2)
        return std::cout << 0 << std::endl, 0;
    for (int i = 2; i != n; ++i)
    {
        f.resize(f.size() + (i - 1));
        int sum1[f.size() + i], sum2[f.size() + i];
        for (int j = 0; j != (int)f.size() + i; ++j)
            sum1[j] = (j ? sum1[j - 1] : 0) + (j < (int)f.size() ? f[j] : 0);
        for (int j = 0; j != (int)f.size() + i; ++j)
            sum2[j] = (j ? sum2[j - 1] : 0) + sum1[j];
        for (int j = 0; j != (int)f.size(); ++j)
            f[j] = (u(j - i, j - 1, 0, sum1, sum2) + d(j, j + i, i, sum1, sum2)) % MOD;
        // for (auto j : f)
        //     std::cout << j << ' ';
        // std::cout << std::endl;
        int suf[f.size() + 1];
        suf[f.size()] = 0;
        for (int i = f.size(); i--;)
            suf[i] = (suf[i + 1] + f[i]) % MOD;
        for (int j = 1; j <= i; ++j)
        {
            int tim = i + 1 - j;
            // std::cout << tim << std::endl;
            ans = (ans + suf[std::min((int)f.size(), j + 1)] * fdown[n - i - 1] % MOD * tim) % MOD;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}