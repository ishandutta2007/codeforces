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
const int MOD = 998244353;
//0: no connect
//1: haven't connected
//2: have connected
int n, fa[300005], a, b, dp[300005][3];
vector<int> son[300005];
void init(int now)
{
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (fa[now] == son[now][i])
        {
            swap(son[now][i], son[now].back());
            son[now].pop_back();
            --i;
            continue;
        }
        fa[son[now][i]] = now;
        init(son[now][i]);
    }
}
void dfs(int now)
{
    dp[now][0] = 1;
    for (auto i : son[now])
    {
        dfs(i);
    }
    for (auto i : son[now])
    {
        dp[now][2] = dp[now][0] * (dp[i][0] + dp[i][1]) + dp[now][1] * (dp[i][0] + dp[i][1]) + dp[now][2] * (dp[i][0] + dp[i][2] * 2);
        dp[now][1] = dp[now][0] * dp[i][2] + dp[now][1] * (dp[i][0] + dp[i][2] * 2);
        dp[now][0] = dp[now][0] * (dp[i][0] + dp[i][2]);
        dp[now][0] %= MOD;
        dp[now][1] %= MOD;
        dp[now][2] %= MOD;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        son[a].push_back(b);
        son[b].push_back(a);
    }
    init(1);
    dfs(1);
    cout << (dp[1][0] + dp[1][2]) % MOD << endl;
    return 0;
}