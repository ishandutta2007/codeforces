#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    vector<int> vr[n+1];
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++)
    {
        auto &[a,b,l]=edges[i];
        cin >> a >> b >> l;
        v[a].push_back({b,l});
        vr[b].push_back(a);
    }
    vector<bool> vis(n+1,0);
    vector<int> ord;
    function<void(int)> dfs1=[&](int a)
    {
        vis[a]=1;
        for(int to:vr[a]) if(vis[to]==0) dfs1(to);
        ord.push_back(a);
    };
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs1(i);
    reverse(ord.begin(),ord.end());
    vector<int> c(n+1,0);
    vector<ll> d(n+1,-1);
    int col=0;
    function<void(int)> dfs2=[&](int a)
    {
        c[a]=col;
        for(auto [to,l]:v[a])
        {
            if(c[to]==0)
            {
                d[to]=d[a]+l;
                dfs2(to);
            }
        }
    };
    for(int a:ord)
    {
        if(c[a]==0)
        {
            d[a]=0;
            col++;
            dfs2(a);
        }
    }
    vector<ll> g(col+1,0);
    for(auto [a,b,l]:edges) if(c[a]==c[b]) g[c[a]]=gcd(g[c[a]],d[a]+l-d[b]);
    int q;
    cin >> q;
    while(q--)    
    {
        int a,s,t;
        cin >> a >> s >> t;
        s=t-s;
        if((s%gcd(g[c[a]],t))==0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}