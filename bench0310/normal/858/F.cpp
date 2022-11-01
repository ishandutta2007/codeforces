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
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<bool> used(m+1,0);
    vector<int> depth(n+1,0);
    vector<array<int,3>> res;
    function<void(int,int,int)> dfs=[&](int a,int p,int up)
    {
        depth[a]=depth[p]+1;
        for(auto [to,id]:v[a]) if(depth[to]==0) dfs(to,a,id);
        vector<array<int,2>> opt;
        for(auto [to,id]:v[a]) if(depth[to]>depth[a]&&used[id]==0) opt.push_back({to,id});
        if(p!=0) opt.push_back({p,up});
        int sz=opt.size();
        for(int i=0;i+1<sz;i+=2)
        {
            auto [b,x]=opt[i];
            auto [c,y]=opt[i+1];
            res.push_back({b,a,c});
            used[x]=used[y]=1;
        }
    };
    for(int i=1;i<=n;i++) if(depth[i]==0) dfs(i,0,0);
    cout << res.size() << "\n";
    for(auto [a,b,c]:res) cout << a << " " << b << " " << c << "\n";
    return 0;
}