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
int n, m, a, b, ans = INF, has, sum;
vector<int> need[3005];
priority_queue<int, vector<int>, greater<int>> que;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        need[a].push_back(b);
    }
    for (int i = 1; i <= m; ++i)
    {
        sort(need[i].begin(), need[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        has = need[1].size();
        sum = 0;
        while (!que.empty())
        {
            que.pop();
        }
        for (int j = 2; j <= m; ++j)
        {
            for (int k = 0; k < max((int)need[j].size() - i + 1, 0ll); ++k)
            {
                sum += need[j][k];
                ++has;
            }
            for (int k = max((int)need[j].size() - i + 1, 0ll); k < need[j].size(); ++k)
            {
                que.push(need[j][k]);
            }
        }
        while (has < i && !que.empty())
        {
            sum += que.top();
            que.pop();
            ++has;
        }
        if (has < i)
        {
            continue;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}