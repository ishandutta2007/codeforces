#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> g[2*m],gr[2*m];
    auto add=[&](int a,int b)
    {
        g[a^1].push_back(b);
        gr[b].push_back(a^1);
        g[b^1].push_back(a);
        gr[a].push_back(b^1);
    };
    vector<int> p(n+1,0);
    vector<int> depth(n+1,0);
    function<void(int)> dfs1=[&](int a)
    {
        depth[a]=depth[p[a]]+1;
        for(int to:v[a])
        {
            if(depth[to]!=0) continue;
            p[to]=a;
            dfs1(to);
        }
    };
    dfs1(1);
    vector<pair<int,string>> opt[n+1];
    vector<string> q(m);
    vector<int> paths[m];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        vector<int> &path=paths[i];
        if(depth[a]>depth[b]) swap(a,b);
        while(depth[b]>depth[a])
        {
            path.push_back(b);
            b=p[b];
        }
        vector<int> tmp;
        while(a!=b)
        {
            path.push_back(b);
            tmp.push_back(a);
            a=p[a]; b=p[b];
        }
        path.push_back(b);
        ranges::reverse(tmp);
        for(int x:tmp) path.push_back(x);
        string &s=q[i];
        cin >> s;
        int len=s.size();
        for(int j=0;j<len;j++)
        {
            opt[path[j]].push_back({2*i,string(1,s[j])+s[len-1-j]});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+1<(int)opt[i].size();j++)
        {
            auto [a,s]=opt[i][j];
            auto [b,t]=opt[i][j+1];
            for(int x=0;x<2;x++)
            {
                for(int y=0;y<2;y++)
                {
                    if(s[x]!=t[y]) add(a^x^1,b^y^1);
                }
            }
        }
    }
    vector<bool> vis(2*m,0);
    vector<int> ord;
    function<void(int)> dfs2=[&](int a)
    {
        vis[a]=1;
        for(int to:g[a]) if(!vis[to]) dfs2(to);
        ord.push_back(a);
    };
    for(int i=0;i<2*m;i++) if(!vis[i]) dfs2(i);
    vector<int> scc(2*m,0);
    int id=0;
    function<void(int)> dfs3=[&](int a)
    {
        scc[a]=id;
        for(int to:gr[a]) if(scc[to]==0) dfs3(to);
    };
    ranges::reverse(ord);
    for(int a:ord)
    {
        if(scc[a]==0)
        {
            id++;
            dfs3(a);
        }
    }
    string res(n+1,'a');
    bool ok=1;
    for(int i=0;i<m;i++)
    {
        ok&=(scc[2*i]!=scc[2*i+1]);
        if(scc[2*i]<scc[2*i+1]) ranges::reverse(paths[i]);
        for(int j=0;j<(int)paths[i].size();j++) res[paths[i][j]]=q[i][j];
    }
    if(ok)
    {
        cout << "YES\n";
        cout << res.substr(1) << "\n";
    }
    else cout << "NO\n";
    return 0;
}