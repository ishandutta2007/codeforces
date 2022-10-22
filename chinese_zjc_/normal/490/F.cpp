//This Code was made by Chinese_zjc_.
#include <iostream>
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
const int MAXSIZE = 200000;
int a[MAXSIZE + 5], n, x, y, fa[MAXSIZE + 5], siz[MAXSIZE + 5], ans, heavy[MAXSIZE + 5], cnt;
vector<int> son[MAXSIZE + 5];
map<int, int> *lis[MAXSIZE + 5];
map<int, int> *lds[MAXSIZE + 5];
map<int, int> GGG[MAXSIZE + MAXSIZE];
//first:length
//second:last number
void init(int now)
{
    siz[now] = 1;
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
        siz[now] += siz[son[now][i]];
    }
    for (int i = 0; i < (int)son[now].size(); ++i)
    {
        if (siz[son[now][heavy[now]]] < siz[son[now][i]])
        {
            heavy[now] = i;
        }
    }
    if (!son[now].size())
    {
        lis[now] = &GGG[cnt++];
        lds[now] = &GGG[cnt++];
    }
    else
    {
        swap(son[now].front(), son[now][heavy[now]]);
        heavy[now] = son[now].front();
        lis[now] = lis[heavy[now]];
        lds[now] = lds[heavy[now]];
    }
}
void dfs(int now)
{
    if (!son[now].size())
    {
        lis[now]->insert(make_pair(a[now], 1));
        lds[now]->insert(make_pair(a[now], 1));
        ans = max(ans, 1ll);
        // cout << now << endl;
        // for (map<int, int>::iterator i = lis[now]->begin(); i != lis[now]->end(); ++i)
        // {
        //     cout << '(' << i->first << "," << i->second << ')';
        // }
        // cout << endl;
        // for (map<int, int>::iterator i = lds[now]->begin(); i != lds[now]->end(); ++i)
        // {
        //     cout << '(' << i->first << "," << i->second << ')';
        // }
        // cout << endl;
        return;
    }
    dfs(heavy[now]);
    for (int i = 1; i < (int)son[now].size(); ++i)
    {
        dfs(son[now][i]);
        for (map<int, int>::iterator j = lis[son[now][i]]->begin(); j != lis[son[now][i]]->end(); ++j)
        {
            map<int, int>::iterator k = lds[now]->upper_bound(j->first);
            if (k == lds[now]->end())
            {
                continue;
            }
            ans = max(ans, j->second + k->second + (j->first < a[now] && a[now] < k->first));
        }
        for (map<int, int>::iterator j = lds[son[now][i]]->begin(); j != lds[son[now][i]]->end(); ++j)
        {
            map<int, int>::iterator k = lis[now]->lower_bound(j->first);
            if (k == lis[now]->begin())
            {
                continue;
            }
            --k;
            ans = max(ans, k->second + j->second + (k->first < a[now] && a[now] < j->first));
        }
        for (map<int, int>::iterator j = lis[son[now][i]]->begin(); j != lis[son[now][i]]->end(); ++j)
        {
            pair<map<int, int>::iterator, bool> k = lis[now]->insert(*j);
            if (k.second)
            {
                map<int, int>::iterator Tmp = k.first;
                if (Tmp != lis[now]->begin() && (--Tmp)->second >= j->second)
                {
                    lis[now]->erase(k.first);
                }
                else
                {
                    while ((++k.first) != lis[now]->end() && k.first->second <= j->second)
                    {
                        lis[now]->erase(k.first--);
                    }
                }
            }
            else
            {
                if (k.first->second < j->second)
                {
                    k.first->second = j->second;
                    while ((++k.first) != lis[now]->end() && k.first->second <= j->second)
                    {
                        lis[now]->erase(k.first--);
                    }
                }
            }
        }
        for (map<int, int>::iterator j = lds[son[now][i]]->begin(); j != lds[son[now][i]]->end(); ++j)
        {
            pair<map<int, int>::iterator, bool> k = lds[now]->insert(*j);
            if (k.second)
            {
                map<int, int>::iterator Tmp = k.first;
                if ((++Tmp) != lds[now]->end() && Tmp->second >= j->second)
                {
                    lds[now]->erase(k.first);
                }
                else
                {
                    while (k.first != lds[now]->begin() && (--k.first)->second <= j->second)
                    {
                        lds[now]->erase(k.first++);
                    }
                }
            }
            else
            {
                if (k.first->second < j->second)
                {
                    k.first->second = j->second;
                    while (k.first != lds[now]->begin() && (--k.first)->second <= j->second)
                    {
                        lds[now]->erase(k.first++);
                    }
                }
            }
        }
        lis[son[now][i]]->clear();
        lds[son[now][i]]->clear();
    }
    map<int, int>::iterator tmp = lis[now]->lower_bound(a[now]);
    if (tmp == lis[now]->begin())
    {
        if (lis[now]->begin()->first > a[now])
        {
            if (lis[now]->begin()->second == 1)
            {
                lis[now]->erase(lis[now]->begin());
            }
            lis[now]->insert({a[now], 1ll});
        }
    }
    else
    {
        --tmp;
        pair<map<int, int>::iterator, bool> g = lis[now]->insert({a[now], tmp->second + 1});
        if (g.second)
        {
            while ((++g.first) != lis[now]->end() && g.first->second <= tmp->second + 1)
            {
                lis[now]->erase(g.first--);
            }
        }
    }
    tmp = lds[now]->upper_bound(a[now]);
    if (tmp == lds[now]->end())
    {
        if (lds[now]->rbegin()->first < a[now])
        {
            if (lds[now]->rbegin()->second == 1)
            {
                lds[now]->erase((++lds[now]->rbegin()).base());
            }
            lds[now]->insert({a[now], 1ll});
        }
    }
    else
    {
        pair<map<int, int>::iterator, bool> g = lds[now]->insert({a[now], tmp->second + 1});
        if (g.second)
        {
            while (g.first != lds[now]->begin() && (--g.first)->second <= tmp->second + 1)
            {
                lds[now]->erase(g.first++);
            }
        }
    }
    // cout << now << endl;
    // for (map<int, int>::iterator i = lis[now]->begin(); i != lis[now]->end(); ++i)
    // {
    //     cout << '(' << i->first << "," << i->second << ')';
    // }
    // cout << endl;
    // for (map<int, int>::iterator i = lds[now]->begin(); i != lds[now]->end(); ++i)
    // {
    //     cout << '(' << i->first << "," << i->second << ')';
    // }
    // cout << endl;
    ans = max(ans, max(lis[now]->rbegin()->second, lds[now]->begin()->second));
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> x >> y;
        son[x].push_back(y);
        son[y].push_back(x);
    }
    init(1);
    dfs(1);
    cout << ans << endl;
    return 0;
}