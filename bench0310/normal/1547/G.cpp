#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> v[n+1];
        vector<int> vr[n+1];
        vector<array<int,2>> edges(m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            vr[b].push_back(a);
            edges[i]={a,b};
        }
        vector<int> ord;
        vector<bool> vis(n+1,0);
        function<void(int)> dfs1=[&](int a)
        {
            vis[a]=1;
            for(int to:v[a]) if(vis[to]==0) dfs1(to);
            ord.push_back(a);
        };
        for(int i=1;i<=n;i++) if(vis[i]==0) dfs1(i);
        reverse(ord.begin(),ord.end());
        vector<int> g[n+1];
        vector<int> scc(n+1,0);
        int id=0;
        function<void(int)> dfs2=[&](int a)
        {
            scc[a]=id;
            for(int to:vr[a]) if(scc[to]==0) dfs2(to);
        };
        for(int a:ord)
        {
            if(scc[a]!=0) continue;
            id++;
            dfs2(a);
        }
        vector<int> in(id+1,0);
        vector<bool> self_loop(id+1,0);
        for(auto [a,b]:edges)
        {
            if(scc[a]!=scc[b])
            {
                g[scc[a]].push_back(scc[b]);
                in[scc[b]]++;
            }
            if(a==b) self_loop[scc[a]]=1;
        }
        vector<int> cnt(id+1,0);
        for(int i=1;i<=n;i++) cnt[scc[i]]++;
        queue<int> q;
        for(int i=1;i<=id;i++) if(in[i]==0) q.push(i);
        vector<int> res(id+1,0);
        int one=scc[1];
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            int &r=res[a];
            if(a==one) r=1;
            if((cnt[a]>1||self_loop[a]==1)&&r!=0) r=-1;
            for(int to:g[a])
            {
                if(r==-1||res[to]==-1) res[to]=-1;
                else res[to]=min(2,res[to]+res[a]);
                if((--in[to])==0) q.push(to);
            }
        }
        for(int i=1;i<=n;i++) cout << res[scc[i]] << " \n"[i==n];
    }
    return 0;
}