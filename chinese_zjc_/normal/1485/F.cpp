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
const int MOD = 1000000007;
int T, n, a[200005], ans;
std::map<int, int> dp;
void add(int &A, int B) { A = (A + B) % MOD; }
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];
        dp.clear();
        ans = dp[0] = 1;
        for (int i = 1, pre = 0; i <= n; ++i)
        {
            int t = (ans - dp[pre] + MOD) % MOD;
            add(dp[pre], t);
            add(ans, t);
            pre += a[i];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}