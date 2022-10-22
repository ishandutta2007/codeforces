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
int n, a[500005];
std::set<int> app;
std::map<int, int> tag, cnt;
std::vector<int> ans, sta;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        std::map<int, int>::iterator iter = tag.find(a[i]);
        if (iter != tag.end())
        {
            ans.push_back(iter->second);
            ans.push_back(a[i]);
            ans.push_back(iter->second);
            ans.push_back(a[i]);
            app.clear();
            tag.clear();
            sta.clear();
            cnt.clear();
            continue;
        }
        if (app.find(a[i]) != app.end())
        {
            while (sta.back() != a[i])
            {
                tag[sta.back()] = a[i];
                sta.pop_back();
            }
        }
        app.insert(a[i]);
        sta.push_back(a[i]);
        if (++cnt[a[i]] == 4)
        {
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            ans.push_back(a[i]);
            app.clear();
            tag.clear();
            sta.clear();
            cnt.clear();
        }
    }
    std::cout << ans.size() << std::endl;
    for (auto i : ans)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}