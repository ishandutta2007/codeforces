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
const int xx[] = {0, -1}, yy[] = {-1, 0};
int n, k, dp[2005][2005], from[2005][2005], Max, val[2005][2005];
char a[2005][2005];
string ans = "{";
vector<pair<int, int>> best;
struct L
{
    pair<int, int> val;
    pair<int, int> pos;
    bool operator<(const L &__Val) const
    {
        return val < __Val.val;
    }
};
vector<L> Tmp;
signed main()
{
    ios::sync_with_stdio(false);
    memset(a, 'z' + 1, sizeof(a));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    if (2 * n - 1 <= k)
    {
        cout << string(2 * n - 1, 'a') << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[0][i] = -INF;
        dp[i][0] = -INF;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                if (dp[i + xx[k]][j + yy[k]] >= dp[i][j])
                {
                    dp[i][j] = dp[i + xx[k]][j + yy[k]];
                    from[i][j] = k;
                }
            }
            dp[i][j] += a[i][j] == 'a';
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] + k >= 2 * n - 1)
            {
                cout << string(2 * n - 1, 'a') << endl;
                return 0;
            }
            if ((i + j - 1 - dp[i][j]) - k == 0)
            {
                if ((i + j - 1) > Max)
                {
                    best.clear();
                    Max = i + j - 1;
                }
                if ((i + j - 1) == Max)
                {
                    best.push_back({i, j});
                }
            }
        }
    }
    if (best.empty())
    {
        best.push_back({1, 1});
    }
    memset(val, 0x3f, sizeof(val));
    for (int i = 2 * n - 1; i >= 0; --i)
    {
        Tmp.clear();
        for (int j = min(i + 1, n); j >= 1; --j)
        {
            Tmp.push_back({{a[j][i - j + 1], min(val[j + 1][i - j + 1], val[j][i - j + 2])}, {j, i - j + 1}});
        }
        sort(Tmp.begin(), Tmp.end());
        for (int j = 0; j < (int)Tmp.size(); ++j)
        {
            val[Tmp[j].pos.first][Tmp[j].pos.second] = j;
        }
    }
    for (int i = 0; i < best.size(); ++i)
    {
        string tmp = "";
        pair<int, int> now = best[i];
        while (now != make_pair(n, n))
        {
            int nxt = 0;
            for (int k = 0; k < 2; ++k)
            {
                if (val[now.first - xx[k]][now.second - yy[k]] < val[now.first - xx[nxt]][now.second - yy[nxt]])
                {
                    nxt = k;
                }
            }
            now = {now.first - xx[nxt], now.second - yy[nxt]};
            tmp += a[now.first][now.second];
        }
        ans = min(ans, tmp);
    }
    if (k == 0)
    {
        cout << a[1][1] << ans << endl;
        return 0;
    }
    cout << string(Max, 'a') << ans << endl;
    return 0;
}