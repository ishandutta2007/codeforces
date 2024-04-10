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
const int MOD = 7340033;
int T, d, n, k;
std::vector<int> dp[32];
template <class T>
void print(const T &x)
{
    for (auto i : x)
        std::cout << i << ' ';
    std::cout << std::endl;
}
std::vector<int> operator*(const std::vector<int> &A, const std::vector<int> &B)
{
    std::vector<int> res(k + 1);
    for (int i = 0; i != (int)A.size(); ++i)
        for (int j = 0; j != (int)B.size(); ++j)
            if (i + j <= k)
                res[i + j] = (res[i + j] + A[i] * B[j]) % MOD;
    return res;
}
std::vector<int> work(std::vector<int> x)
{
    x = x * x;
    x = x * x;
    x.insert(x.begin(), 1);
    return x;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    k = 1000;
    dp[0].assign(k + 1, 0);
    dp[0][0] = 1;
    for (int i = 1; i <= 31; ++i)
        dp[i] = work(dp[i - 1]);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> k;
        d = 0;
        while (n % 2 && n != 1)
            ++d, n /= 2;
        std::cout << dp[d][k] << std::endl;
    }
    return 0;
}