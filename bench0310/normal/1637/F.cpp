#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n+1,0);
    array<int,2> mx={0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> h[i];
        mx=max(mx,{h[i],i});
    }
    int root=mx[1];
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> x(n+1,0);
    vector<int> c(n+1,0);
    ll res=2*mx[0];
    function<void(int,int)> dfs=[&](int a,int p)
    {
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            x[a]=max(x[a],x[to]);
        }
        c[a]=max(0,h[a]-x[a]);
        x[a]=max(x[a],h[a]);
        if(a!=root) res+=c[a];
    };
    dfs(root,0);
    vector<ll> sum(n+1,0);
    vector<ll> opt(n+1,0);
    vector<ll> t;
    function<void(int,int)> go=[&](int a,int p)
    {
        if(a!=root) sum[a]=sum[p]+c[a];
        opt[a]=sum[a];
        for(int to:v[a])
        {
            if(to==p) continue;
            go(to,a);
            if(a!=root) opt[a]=max(opt[a],opt[to]);
            else t.push_back(opt[to]);
        }
    };
    go(root,0);
    ranges::sort(t,greater<>());
    if(v[root].size()==1) res-=t[0];
    else res-=(t[0]+t[1]);
    cout << res << "\n";
    return 0;
}