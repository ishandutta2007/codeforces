#include <algorithm>
#include <math.h>
#include<vector>
#include<set>
#include<map>
#include <iostream>


using namespace std;

/*
@author mitterr (2017.02.28 22:42)
*/
vector<vector<pair<long long , long long > > > g;
vector<vector<long long>> ans;

void dfs(long long v, long long prev = -1, long long day = -1)
{
    int cur = 0;
    for (auto e : g[v])
    {
        if (e.first != prev)
        {
            if (day == cur)
            {
                ++cur;
            }
            ans[cur].push_back(e.second);
            dfs(e.first, v, cur);
            ++cur;
        }
    }
}

int main()
{

  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n;
    cin >> n;
    
    g.resize(n);
    ans.resize(n);
    
    for (int i = 1; i <= n - 1; ++i)
    {
         long long u, v;
        cin  >> u >> v;
        --u, --v;
        g[v].push_back(make_pair(u, i));
        g[u].push_back(make_pair(v, i));
    }
    
    dfs(0);
    
    int cnt = 0;
    for (auto cur : ans) {
        if (cur.empty()) {
            break;
        }
        ++cnt;
    }
    cout << cnt << endl;
    
    for (auto cur : ans)
    {
        if (cur.empty())
        {
            break;
        }
        cout << cur.size() << ' ';
        for (auto x : cur)
        {
            cout << x << ' ';
        }
        cout << endl;
    }
}