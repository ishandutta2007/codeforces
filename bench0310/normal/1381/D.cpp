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
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> mx(n+1,0);
        int l=0;
        function<void(int,int,int)> dfs1=[&](int a,int p,int d)
        {
            if(a==y) l=d;
            mx[a]=0;
            for(int to:v[a])
            {
                if(to==p) continue;
                dfs1(to,a,d+1);
                mx[a]=max(mx[a],mx[to]+1);
            }
        };
        dfs1(x,0,0);
        vector<int> cnt(n+1,0);
        int root=0;
        function<void(int,int,int)> dfs2=[&](int a,int p,int u)
        {
            vector<int> ch={0};
            for(int to:v[a]) if(to!=p) ch.push_back(to);
            int m=(int)ch.size()-1;
            vector<int> pre(m+2,0);
            vector<int> suf(m+2,0);
            for(int i=1;i<=m;i++) pre[i]=max(pre[i-1],mx[ch[i]]+1);
            for(int i=m;i>=1;i--) suf[i]=max(suf[i+1],mx[ch[i]]+1);
            cnt[a]=(u>=l);
            for(int i=1;i<=m;i++)
            {
                cnt[a]+=(mx[ch[i]]+1>=l);
                dfs2(ch[i],a,max({u,pre[i-1],suf[i+1]})+1);
            }
            if(cnt[a]>=3) root=a;
        };
        dfs2(x,0,0);
        if(root==0)
        {
            cout << "NO\n";
            continue;
        }
        vector<int> depth(n+1,0);
        vector<array<int,17>> p(n+1);
        for(int i=0;i<=n;i++) p[i].fill(0);
        vector<array<int,2>> down(n+1,{0,0});
        function<void(int)> dfs3=[&](int a)
        {
            depth[a]=depth[p[a][0]]+1;
            for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
            down[a]={depth[a],a};
            for(int to:v[a])
            {
                if(to==p[a][0]) continue;
                p[to][0]=a;
                dfs3(to);
                down[a]=max(down[a],down[to]);
            }
        };
        dfs3(root);
        auto lca=[&](int a,int b)->int
        {
            if(depth[a]>depth[b]) swap(a,b);
            for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
            if(a==b) return a;
            for(int i=16;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
            return p[a][0];
        };
        auto ok=[&](int a,int b)->bool
        {
            int u=lca(a,b);
            return (a==u||b==u);
        };
        auto up=[&](int a,int d)->int
        {
            for(int i=16;i>=0;i--) if(depth[p[a][i]]>=d) a=p[a][i];
            return a;
        };
        auto kth=[&](int a,int b,int k)->int
        {
            int u=lca(a,b);
            if(depth[a]-depth[u]>k) return up(a,depth[a]-k);
            else return 0;
        };
        bool res=[&]()->bool
        {
            vector<bool> vis(n+1,0);
            if(ok(x,y)) return 1;
            while(1)
            {
                int o=down[x][1];
                if(vis[o]) return 0;
                vis[o]=1;
                int ny=kth(y,x,depth[o]-depth[x]);
                if(ny==0) return 1;
                x=o;
                y=ny;
                swap(x,y);
            }
        }();
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}