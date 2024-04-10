#include <iostream>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 150005;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> comp;
vector< pair<int,int>>  p;
void dfs (int v) {
    used[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}

bool find_comps() {
    for (int i=1; i<=n; ++i)
        used[i] = false;
    for (int i=1; i<=n; ++i)
        if (! used[i]) {
            comp.clear();
            dfs (i);
            
            for(int u = 0; u < comp.size(); u++)
            {
                if(g[comp[u]].size() != comp.size()-1)
                    return 0;
            }
        }
    return 1;
}
int main()
{
    //freopen("p.in", "r", stdin);
    //freopen("p.out", "w", stdout);
    long long int m;
    cin >> n >> m;
    for(int i =0; i < m ; i++)
    {
        int x,y;
        cin >> x >> y;
        p.push_back({x,y});
        
    }
    sort(p.begin(), p.end());
    for(int i = 1; i < p.size(); i ++)
    {
        if(p[i] == p[i-1]) p[i-1] = {-1,-1};
    }
    for(int i = 0; i < m; i++)
    {
        if(p[i].first !=  -1)
        {
            g[p[i].first].push_back(p[i].second);
            g[p[i].second].push_back(p[i].first);
        }
    }
    int b  = find_comps();
    if(b)
        cout << "YES";
    else
        cout << "NO";
    //freopen("p.in","r", stdin);
    //freopen("p.out","w", stdout);
    return 0;
}