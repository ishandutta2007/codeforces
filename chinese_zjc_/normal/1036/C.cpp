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
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int dp[2][4][20];
string Lim;
int dfs(bool Max, int has, int w)
{
    if (has > 3)
    {
        return 0;
    }
    if (w == Lim.length())
    {
        return 1;
    }
    if (dp[Max][has][w])
    {
        return dp[Max][has][w];
    }
    if (Max)
    {
        for (int i = 0; i <= Lim[w] - '0'; ++i)
        {
            dp[Max][has][w] += dfs(i + '0' == Lim[w], has + (i > 0), w + 1);
        }
    }
    else
    {
        for (int i = 0; i <= 9; ++i)
        {
            dp[Max][has][w] += dfs(false, has + (i > 0), w + 1);
        }
    }
    return dp[Max][has][w];
}
int work(int now)
{
    Lim = to_string(now);
    memset(dp, 0, sizeof(dp));
    return dfs(true, 0, 0);
}
int T, l, r;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> l >> r;
        --l;
        cout << work(r) - work(l) << endl;
    }
    return 0;
}