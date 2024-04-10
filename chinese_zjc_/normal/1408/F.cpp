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
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n;
vector<pair<int, int>> ans;
struct cmp
{
    bool operator()(const set<int> &A, const set<int> &B)
    {
        return A.size() < B.size();
    }
};
multiset<pair<int, set<int>>> g;
set<int> biggest;
void Merge(multiset<pair<int, set<int>>>::iterator A, multiset<pair<int, set<int>>>::iterator B)
{
    set<int> nxt;
    for (set<int>::iterator i = A->second.begin(), j = B->second.begin(); i != A->second.end() && j != B->second.end(); ++i, ++j)
    {
        nxt.insert({*i, *j});
        ans.push_back({*i, *j});
    }
    g.insert({nxt.size(), nxt});
    g.erase(A);
    g.erase(B);
}
void up(multiset<pair<int, set<int>>>::iterator A)
{
    set<int> nxt;
    for (set<int>::iterator i = A->second.begin(); i != A->second.end(); ++i)
    {
        nxt.insert({*i, *biggest.begin()});
        ans.push_back({*i, *biggest.begin()});
        biggest.erase(biggest.begin());
    }
    g.erase(A);
    g.insert({nxt.size(), nxt});
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        g.insert({1, set<int>({i})});
    }
    for (multiset<pair<int, set<int>>>::iterator i = g.begin(); i != g.end();)
    {
        if (i == g.begin())
        {
            ++i;
        }
        multiset<pair<int, set<int>>>::iterator j = i;
        --j;
        if (i->first == j->first)
        {
            Merge(i++, j);
        }
        else
        {
            ++i;
        }
    }
    biggest = g.rbegin()->second;
    g.erase(g.find({biggest.size(), biggest}));
    while (g.size() > 1)
    {
        up(g.begin());
        while (g.size() > 1 && g.begin()->first == (++g.begin())->first)
        {
            Merge(g.begin(), ++g.begin());
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}