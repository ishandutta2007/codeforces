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
#define int unsigned long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
string s;
int n, m, cnt;
struct node
{
    bool over;
    int son[3];
} a[600005];
void build(int now = 0, int h = 0)
{
    if (h == s.length())
    {
        a[now].over = true;
        return;
    }
    if (!a[now].son[s[h] - 'a'])
    {
        a[now].son[s[h] - 'a'] = ++cnt;
    }
    build(a[now].son[s[h] - 'a'], h + 1);
}
bool find(int now = 0, int h = 0, bool changed = false)
{
    if (h == s.length())
    {
        return changed && a[now].over;
    }
    if (changed)
    {
        if (a[now].son[s[h] - 'a'])
        {
            return find(a[now].son[s[h] - 'a'], h + 1, true);
        }
    }
    else
    {
        for (char i = 'a'; i <= 'c'; ++i)
        {
            if (!a[now].son[i - 'a'])
            {
                continue;
            }
            if (s[h] == i)
            {
                if (find(a[now].son[i - 'a'], h + 1, false))
                    return true;
            }
            else
            {
                if (find(a[now].son[i - 'a'], h + 1, true))
                    return true;
            }
        }
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        build();
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> s;
        cout << (find() ? "YES" : "NO") << endl;
    }
    return 0;
}