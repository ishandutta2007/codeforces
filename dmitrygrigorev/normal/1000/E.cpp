//{
 
#include <bits/stdc++.h>
 
#define forn(i, a, b) for (auto i = a; i <= b; i++)
#define all(x) x.begin (), x.end ()
#define rall(x) x.rbegin (), x.rend ()
#define mp make_pair
#define pii pair <int, int>
#define pb push_back
 
#define LOCAL
 
using namespace std;
 
using lli = long long;
using ld = long double;
 
mt19937 rnd (time (nullptr));
 
//}
 
int n = 0, m = 0;
vector <vector <pair <int, int>>> data;
vector <bool> used;
vector <int> tin, fup;
int timer = 0;
vector <bool> bridges;
vector <int> components;
 
int n2 = 0;
vector <vector <int>> data2;
vector <int> dist;
 
void DFS1 (int v, int p, int edge);
void DFS2 (int v, int color);
void DFS3 (int v);
int DFS4 (int v, int p);
pair <int, int> DFS5 (int v, int p);
 
inline void Solve ()
{
    cin >> n >> m;
    data.resize (n);
    used.resize (n);
    tin.resize (n);
    fup.resize (n);
    bridges.resize (m);
    components.resize (n);
    for (int i = 0; i < m; i++)
    {
        int a = 0, b = 0;
        cin >> a >> b;
        a--, b--;
        data[a].push_back ({ b, i });
        data[b].push_back ({ a, i });
    }
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            DFS1 (i, -1, -1);
        }
    }
    used.assign (n, false);
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            DFS2 (i, n2);
            n2++;
        }
    }
    data2.resize (n2);
    used.assign (n, false);
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            DFS3 (i);
        }
    }
    used.assign (n2, false);
    dist.resize (n2);
    int edges = 0, value = 0;
    for (int i = 0; i < n2; i++)
    {
        if (!used[i])
        {
            edges += DFS4 (i, -1);
            pair <int, int> tmp1 = DFS5 (i, -1);
            pair <int, int> tmp2 = DFS5 (tmp1.first, -1);
            value = max (value, tmp2.second);
        }
    }
    int result = value;
    cout << result;
}
 
void DFS1 (int v, int p, int edge)
{
    used[v] = true;
    fup[v] = tin[v] = timer++;
    for (auto it : data[v])
    {
        if ((it.first == p) && (edge == it.second))
            continue;
        if (used[it.first])
            fup[v] = min (fup[v], tin[it.first]);
        else
        {
            DFS1 (it.first, v, it.second);
            fup[v] = min (fup[v], fup[it.first]);
            if (fup[it.first] > tin[v])
            {
                bridges[it.second] = true;
            }
        }
    }
}
 
void DFS2 (int v, int color)
{
    used[v] = true;
    components[v] = color;
    for (auto it : data[v])
    {
        if ((used[it.first]) || (bridges[it.second]))
            continue;
        DFS2 (it.first, color);
    }
}
 
void DFS3 (int v)
{
    used[v] = true;
    for (auto it : data[v])
    {
        if (used[it.first])
            continue;
        int x = components[v], y = components[it.first];
        if ((bridges[it.second]) && (x != y))
        {
            data2[x].push_back (y);
            data2[y].push_back (x);
        }
        DFS3 (it.first);
    }
}
 
int DFS4 (int v, int p)
{
    used[v] = true;
    int result = 0;
    for (auto it : data2[v])
    {
        if (it == p)
            continue;
        result += (DFS4 (it, v) + 1);
    }
    return result;
}
 
pair <int, int> DFS5 (int v, int p)
{
    pair <int, int> result (v, 0);
    for (auto it : data2[v])
    {
        if (it == p)
            continue;
        pair <int, int> tmp = DFS5 (it, v);
        if (tmp.second + 1 > result.second)
        {
            result = { tmp.first, tmp.second + 1 };
        }
    }
    return result;
}
 
signed main ()
{
#ifndef LOCAL
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
#endif
    cout << fixed << setprecision (20);
    Solve ();
    return 0;
}