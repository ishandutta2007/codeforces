#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        vector<int> g[n+1];
        while(m--)
        {
            int s;
            cin >> s;
            int p=0;
            while(s--)
            {
                int a;
                cin >> a;
                if(p!=0)
                {
                    g[a].push_back(p);
                    g[p].push_back(a);
                }
                p=a;
            }
        }
        vector<int> par(n+1,0);
        vector<int> depth(n+1,0);
        vector<bool> bad(n+1,0);
        function<void(int)> dfs=[&](int a)
        {
            depth[a]=depth[par[a]]+1;
            for(int to:g[a])
            {
                if(depth[to]==0)
                {
                    par[to]=a;
                    dfs(to);
                }
                else if(to!=par[a]&&depth[to]<depth[a])
                {
                    int b=a;
                    while(b!=to)
                    {
                        bad[b]=1;
                        b=par[b];
                    }
                }
            }
        };
        dfs(1);
        vector<int> v[n+1];
        for(int i=2;i<=n;i++)
        {
            if(!bad[i])
            {
                v[i].push_back(par[i]);
                v[par[i]].push_back(i);
            }
        }
        const int inf=(1<<30);
        vector<array<int,2>> dp(n+1,{inf,inf});
        vector<int> connect(n+1,-1);
        vector<array<int,2>> best[n+1][2];
        vector<array<int,2>> from[n+1][2];
        auto upd=[&](int a,int x,int val,int con,vector<array<int,2>> edges,vector<array<int,2>> ext)
        {
            if(val<dp[a][x])
            {
                dp[a][x]=val;
                best[a][x]=edges;
                from[a][x]=ext;
                if(x==1) connect[a]=con;
            }
        };
        function<void(int,int)> go=[&](int a,int p)
        {
            vector<int> tmp;
            vector<array<int,2>> edges,ext;
            int cnt=0;
            //connect all children
            for(int to:v[a])
            {
                if(to==p) continue;
                go(to,a);
                tmp.push_back(dp[to][0]<=dp[to][1]?to:connect[to]);
                cnt+=min(dp[to][0],dp[to][1]);
                ext.push_back({to,(dp[to][1]<dp[to][0])});
            }
            bool added=(tmp.size()&1);
            if(tmp.size()&1) tmp.push_back(a);
            for(int i=0;i<(int)tmp.size();i+=2) edges.push_back({tmp[i],tmp[i+1]});
            upd(a,0,cnt+edges.size(),-1,edges,ext);
            //connect all except one child
            if(added) tmp.pop_back();
            if((tmp.size()%2)==0) tmp.push_back(a);
            edges.clear();
            for(int i=0;i+1<(int)tmp.size();i+=2) edges.push_back({tmp[i],tmp[i+1]});
            upd(a,1,cnt+edges.size(),tmp.back(),edges,ext);
            //leave one uncovered edge
            tmp.clear();
            edges.clear();
            ext.clear();
            array<int,2> rm={inf,-1};
            for(int to:v[a]) if(to!=p) rm=min(rm,{dp[to][0]-min(dp[to][0],dp[to][1]),to});
            if(rm[1]==-1) return;
            cnt+=rm[0];
            for(int to:v[a])
            {
                if(to==p) continue;
                if(to!=rm[1])
                {
                    tmp.push_back(dp[to][0]<=dp[to][1]?to:connect[to]);
                    ext.push_back({to,(dp[to][1]<dp[to][0])});
                }
                else ext.push_back({to,0});
            }
            if(p!=0)
            {
                if((tmp.size()%2)==0) tmp.push_back(a);
                for(int i=0;i+1<(int)tmp.size();i+=2) edges.push_back({tmp[i],tmp[i+1]});
                upd(a,1,cnt+edges.size(),tmp.back(),edges,ext);
            }
            else
            {
                if(tmp.size()&1) tmp.push_back(a);
                for(int i=0;i<(int)tmp.size();i+=2) edges.push_back({tmp[i],tmp[i+1]});
                upd(a,0,cnt+edges.size(),-1,edges,ext);
            }
        };
        vector<array<int,2>> res;
        function<void(int,int)> retrieve=[&](int a,int x)
        {
            for(auto edge:best[a][x]) res.push_back(edge);
            for(auto [to,y]:from[a][x]) retrieve(to,y);
        };
        for(int i=1;i<=n;i++)
        {
            if(dp[i][0]!=inf) continue;
            go(i,0);
            retrieve(i,0);
        }
        cout << res.size() << "\n";
        for(auto [a,b]:res) cout << a << " " << b << "\n";
    }
    return 0;
}