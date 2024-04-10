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
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int Map[8][55], n, k;
vector<pair<int, pair<int, int>>> ans;
pair<int, int> E, nxt[8][55];
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> Map[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        nxt[2][i] = {2, i - 1};
        if (Map[1][i] && Map[1][i] == Map[2][i])
        {
            ans.push_back({Map[1][i], {1, i}});
            Map[2][i] = 0;
        }
        nxt[3][i] = {3, i + 1};
        if (Map[4][i] && Map[4][i] == Map[3][i])
        {
            ans.push_back({Map[4][i], {4, i}});
            Map[3][i] = 0;
        }
        if (Map[2][i] == 0)
        {
            E = {2, i};
        }
        if (Map[3][i] == 0)
        {
            E = {3, i};
        }
    }
    nxt[2][1] = {3, 1};
    nxt[3][n] = {2, n};
    if (E == pair<int, int>{0, 0})
    {
        cout << -1 << endl;
        return 0;
    }
    while (clock() < 2800)
    {
        if (Map[nxt[E.first][E.second].first][nxt[E.first][E.second].second])
        {
            ans.push_back({Map[nxt[E.first][E.second].first][nxt[E.first][E.second].second], E});
            Map[E.first][E.second] = Map[nxt[E.first][E.second].first][nxt[E.first][E.second].second];
            Map[nxt[E.first][E.second].first][nxt[E.first][E.second].second] = 0;
        }
        if (E.first == 2 && Map[1][E.second] && Map[1][E.second] == Map[2][E.second])
        {
            ans.push_back({Map[1][E.second], {1, E.second}});
            Map[2][E.second] = 0;
        }
        if (E.first == 3 && Map[4][E.second] && Map[4][E.second] == Map[3][E.second])
        {
            ans.push_back({Map[4][E.second], {4, E.second}});
            Map[3][E.second] = 0;
        }
        E = nxt[E.first][E.second];
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
    }
    return 0;
}