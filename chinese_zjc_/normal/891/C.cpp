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
int n, m, q, a[500005], b[500005], c[500005];
bool ans[500005];
std::map<int, std::vector<int>> map;
std::map<int, std::map<int, std::vector<int>>> que;
struct backDSU
{
    int fa[500005], siz[500005];
    std::vector<int> history;
    backDSU()
    {
        for (int i = 1; i <= 500000; ++i)
            fa[i] = i, siz[i] = 1;
    }
    int find(int now) const { return fa[now] == now ? now : find(fa[now]); }
    void connect(int from, int to)
    {
        history.push_back(from);
        siz[fa[from] = to] += siz[from];
    }
    void roll_back()
    {
        int now = history.back();
        history.pop_back();
        siz[fa[now]] -= siz[now];
        fa[now] = now;
    }
    void merge(int A, int B)
    {
        A = find(A);
        B = find(B);
        if (siz[A] < siz[B])
            connect(A, B);
        else
            connect(B, A);
    }
} dsu;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> a[i] >> b[i] >> c[i];
        map[c[i]].push_back(i);
    }
    std::cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        static int k;
        ans[i] = true;
        std::cin >> k;
        while (k--)
        {
            static int x;
            std::cin >> x;
            que[c[x]][i].push_back(x);
        }
    }
    for (auto i : map) //i.first -> edge value
    {
        for (auto j : que[i.first]) //j.first -> query number
        {
            int tim = 0;
            for (auto k : j.second)
                if (dsu.find(a[k]) == dsu.find(b[k]))
                    ans[j.first] = false;
                else
                    dsu.merge(a[k], b[k]), ++tim;
            while (tim--)
                dsu.roll_back();
        }
        for (auto j : i.second)
            if (dsu.find(a[j]) != dsu.find(b[j]))
                dsu.merge(a[j], b[j]);
    }
    for (int i = 1; i <= q; ++i)
        std::cout << (ans[i] ? "YES" : "NO") << '\n';
    return 0;
}