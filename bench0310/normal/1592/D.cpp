#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[n+1];
    vector<array<int,2>> e(n,{0,0});
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        e[i]={a,b};
    }
    auto q=[&](vector<int> now)->int
    {
        set<int> s;
        for(int a:now) for(int j=0;j<2;j++) s.insert(e[a][j]);
        cout << "? " << s.size();
        for(int a:s) cout << " " << a;
        cout << "\n";
        cout.flush();
        int g;
        cin >> g;
        return g;
    };
    vector<int> edges;
    for(int i=1;i<=n-1;i++) edges.push_back(i);
    int g=q(edges);
    while(edges.size()>1)
    {
        vector<bool> active(n,0);
        for(int id:edges) active[id]=1;
        vector<int> now;
        int req=edges.size()/2;
        vector<bool> vis(n+1,0);
        function<void(int,int)> go=[&](int a,int p)
        {
            vis[a]=1;
            for(auto [to,id]:v[a])
            {
                if(to==p||!active[id]||(int)now.size()==req) continue;
                now.push_back(id);
                go(to,a);
            }
        };
        for(int i=1;i<=n;i++) if(!vis[i]) go(i,0);
        if(q(now)==g) edges=now;
        else
        {
            vector<bool> tmp(n,0);
            for(int id:now) tmp[id]=1;
            vector<int> nxt;
            for(int id:edges) if(!tmp[id]) nxt.push_back(id);
            edges=nxt;
        }
    }
    int r=edges[0];
    cout << "! " << e[r][0] << " " << e[r][1] << "\n";
    cout.flush();
    return 0;
}