#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int edges=m;
    vector<int> one(2*m-1,0);
    vector<int> two(2*m-1,0);
    vector<int> dir(2*m-1,0);
    vector<int> l(2*m-1,-1);
    vector<int> r(2*m-1,-1);
    vector<bool> used(2*m-1,0);
    vector<array<int,2>> v[n+1][3];
    auto fix_one=[&](int a,int t)
    {
        while(!v[a][t].empty()&&used[v[a][t].back()[1]]) v[a][t].pop_back();
    };
    auto fix=[&](int a,int t)
    {
        fix_one(a,t);
        if(v[a][t].empty()) return;
        array<int,2> tmp=v[a][t].back();
        v[a][t].pop_back();
        fix_one(a,t);
        v[a][t].push_back(tmp);
    };
    queue<int> q;
    auto add=[&](int a,int b,int t,int e)
    {
        v[a][t].push_back({b,e});
        v[b][t].push_back({a,e});
        q.push(a);
        q.push(b);
    };
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        cin >> a >> b >> t;
        one[i]=a;
        two[i]=b;
        add(a,b,t,i);
    }
    int res=0;
    for(int i=1;i<=n;i++) res+=(v[i][1].size()&1);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int t=1;t<=2;t++)
        {
            while(1)
            {
                fix(a,t);
                if(v[a][t].size()>=2)
                {
                    auto [b,e]=v[a][t].back();
                    v[a][t].pop_back();
                    auto [c,f]=v[a][t].back();
                    v[a][t].pop_back();
                    l[edges]=e;
                    r[edges]=f;
                    one[edges]=b;
                    two[edges]=c;
                    if(b!=c) add(b,c,t,edges);
                    edges++;
                    used[e]=used[f]=1;
                }
                else break;
            }
        }
    }
    vector<array<int,2>> g[n+1];
    for(int a=1;a<=n;a++)
    {
        for(int t=1;t<=2;t++)
        {
            fix(a,t);
            if(!v[a][t].empty())
            {
                auto [b,e]=v[a][t].back();
                g[a].push_back({b,e});
            }
        }
    }
    vector<bool> vis(2*m-1,0);
    function<void(int)> dfs=[&](int a)
    {
        for(auto [to,e]:g[a])
        {
            if(vis[e]) continue;
            dir[e]=(one[e]==a);
            vis[e]=1;
            dfs(to);
        }
    };
    for(int i=1;i<=n;i++) if(g[i].size()==1) dfs(i);
    for(int i=1;i<=n;i++) dfs(i);
    for(int e=edges-1;e>=m;e--)
    {
        if(dir[e]==1)
        {
            dir[l[e]]=(one[l[e]]==one[e]);
            dir[r[e]]=(two[r[e]]==two[e]);
        }
        else
        {
            dir[l[e]]=(two[l[e]]==one[e]);
            dir[r[e]]=(one[r[e]]==two[e]);
        }
    }
    cout << res << "\n";
    for(int i=0;i<m;i++) cout << (dir[i]==1?1:2);
    cout << "\n";
    return 0;
}