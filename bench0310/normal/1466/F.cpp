#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin >> k;
        if(k==1)
        {
            int a;
            cin >> a;
            edges.push_back({i,a,0});
        }
        else if(k==2)
        {
            int a,b;
            cin >> a >> b;
            edges.push_back({i,a,b});
        }
    }
    sort(edges.begin(),edges.end());
    vector<int> p(m+1,0);
    vector<int> sz(m+1,1);
    for(int i=0;i<=m;i++) p[i]=i;
    function<int(int)> find_set=[&](int a)
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    };
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return 1;
    };
    vector<int> res;
    for(auto [i,a,b]:edges)
    {
        if(merge_sets(a,b)==1) res.push_back(i);
    }
    const ll mod=1000000007;
    vector<ll> pw(m+1,1);
    for(int i=1;i<=m;i++) pw[i]=(pw[i-1]*2)%mod;
    ll cnt=1;
    vector<bool> vis(m+1,0);
    for(int i=0;i<=m;i++)
    {
        int now=find_set(i);
        if(vis[now]) continue;
        vis[now]=1;
        cnt=(cnt*pw[sz[now]-1])%mod;
    }
    cout << cnt << " " << res.size() << "\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}