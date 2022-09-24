#include <iostream>
#include <set>
#include <string>
#include <time.h>
#include <cmath>
#include<bitset>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = (int) 1e9 + 7;
int n;
set<int>g[505];
vector<int> cl(505);
vector<int> p(505);
int cycle_st = -1, cycle_end;

bool dfs (int v)
{
    cl[v] = 1;
    for (auto u : g[v])
    {
        int to = u;
        if (cl[to] == 0) {
            p[to] = v;
            if (dfs (to))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(8);
    int  m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
    }
    for (int i=0; i<n; ++i)
        if (dfs (i))
            break;
    if (cycle_st == -1)
    {
        cout << "YES" << "\n";
        return 0;
    }
    bool flag = 0;
    vector<int> cycle;
    vector<pair<int, int>> t(500);
        cycle.push_back (cycle_st);
        for (int v=cycle_end; v!=cycle_st; v=p[v])
            cycle.push_back (v);
        cycle.push_back (cycle_st);
        reverse (cycle.begin(), cycle.end());
    for(int i = 0; i < cycle.size() - 1; i++)
    {
        if(cycle[i] != cycle[i + 1])
        {
            t[i].first = cycle[i];
            t[i].second = cycle[i + 1];
        }
     }
    int cnt = cycle.size() - 1;
 
    for(int i = 0; i < cnt; i++)
    {
        g[t[i].first].erase(t[i].second);
        cycle.clear();
        p.assign (500, -1);
        cl.assign (500, 0);
        cycle_st = -1;
        cycle_end = -1;
        for(int i = 0; i < n; i++)
        {
            if(dfs(i)) break;
        }
          if (cycle_st == -1)
          {
              cout << "YES";
              return 0;
          }
        g[t[i].first].insert(t[i].second);
    }
    cout << "NO" << "\n";
    return 0;
}