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
const int MOD = 998244353;
int k, lim[20], cnt[20][2][2][1024], sum[20][2][2][1024], pop[1024], pow10[20];
void dfs(int left, bool pre, bool inlim, int used)
{
    if (left == 0)
        cnt[left][pre][inlim][used] = 1, sum[left][pre][inlim][used] = 0;
    if (~cnt[left][pre][inlim][used] || ~sum[left][pre][inlim][used])
        return;
    int &CNT = cnt[left][pre][inlim][used] = 0, &SUM = sum[left][pre][inlim][used] = 0;
    if (pre)
    {
        dfs(left - 1, true, 0 == lim[left] && inlim, 0);
        CNT += cnt[left - 1][true][0 == lim[left] && inlim][0];
        SUM += sum[left - 1][true][0 == lim[left] && inlim][0];
    }
    for (int i = pre ? 1 : 0; i < (inlim ? lim[left] : 10); ++i)
    {
        if (pop[used | 1 << i] <= k)
        {
            dfs(left - 1, false, false, used | 1 << i);
            CNT += cnt[left - 1][false][false][used | 1 << i];
            SUM += sum[left - 1][false][false][used | 1 << i] +
                   cnt[left - 1][false][false][used | 1 << i] * i * pow10[left - 1] % MOD;
        }
    }
    if (inlim && (lim[left] || !pre) && pop[used | 1 << lim[left]] <= k)
    {
        dfs(left - 1, false, true, used | 1 << lim[left]);
        CNT += cnt[left - 1][false][true][used | 1 << lim[left]];
        SUM += sum[left - 1][false][true][used | 1 << lim[left]] +
               cnt[left - 1][false][true][used | 1 << lim[left]] * lim[left] * pow10[left - 1] % MOD;
    }
    CNT %= MOD;
    SUM %= MOD;
    // std::cout << left << ' ' << pre << ' ' << inlim << ' ' << used << std::endl;
    // std::cout << CNT << ' ' << SUM << std::endl;
}
int work(int LIM)
{
    for (int i = 1; i <= 19; ++i, LIM /= 10)
        lim[i] = LIM % 10;
    // for (int j = 19; j >= 0; --j)
    //     std::cout << lim[j] << " \n"[j == 0];
    memset(cnt, -1, sizeof(cnt));
    memset(sum, -1, sizeof(sum));
    dfs(19, true, true, 0);
    return sum[19][true][true][0];
}
signed main()
{
    int l, r;
    for (int i = 1; i != 1024; ++i)
        pop[i] = pop[i & (i - 1)] + 1;
    pow10[0] = 1;
    for (int i = 1; i != 18; ++i)
        pow10[i] = pow10[i - 1] * 10 % MOD;
    std::ios::sync_with_stdio(false);
    std::cin >> l >> r >> k;
    std::cout << (work(r) - work(l - 1) + MOD) % MOD << std::endl;
    return 0;
}