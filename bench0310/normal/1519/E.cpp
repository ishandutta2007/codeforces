#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<array<ll,2>,int>> h;
    auto incx=[](ll a,ll b,ll c,ll d)->array<ll,2>
    {
        a+=b;
        ll x=(b*c);
        ll y=(a*d);
        ll g=gcd(x,y);
        return {x/g,y/g};
    };
    auto incy=[](ll a,ll b,ll c,ll d)->array<ll,2>
    {
        c+=d;
        ll x=(b*c);
        ll y=(a*d);
        ll g=gcd(x,y);
        return {x/g,y/g};
    };
    for(int i=1;i<=n;i++)
    {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        h.push_back({incx(a,b,c,d),i});
        h.push_back({incy(a,b,c,d),i});
    }
    sort(h.begin(),h.end(),
    [](const pair<array<ll,2>,int> &a,const pair<array<ll,2>,int> &b)->bool
    {
        auto [x1,y1]=a.first;
        auto [x2,y2]=b.first;
        return (x1*y2<x2*y1);
    }
    );
    int l=0;
    int m=0;
    vector<int> one(n+1,0);
    vector<int> two(n+1,0);
    while(l<2*n)
    {
        vector<int> v={h[l].second};
        while(l+1<2*n&&h[l].first==h[l+1].first)
        {
            l++;
            v.push_back(h[l].second);
        }
        l++;
        m++;
        for(int a:v)
        {
            if(one[a]==0) one[a]=m;
            else two[a]=m;
        }
    }
    vector<array<int,2>> v[m+1];
    for(int i=1;i<=n;i++)
    {
        v[one[i]].push_back({two[i],i});
        v[two[i]].push_back({one[i],i});
    }
    vector<int> depth(m+1,0);
    vector<bool> used(n+1,0);
    vector<array<int,2>> res;
    function<void(int,int,int)> dfs=[&](int a,int p,int up)
    {
        depth[a]=depth[p]+1;
        for(auto [to,id]:v[a]) if(depth[to]==0) dfs(to,a,id);
        vector<int> opt;
        for(auto [to,id]:v[a]) if(depth[to]>depth[a]&&used[id]==0) opt.push_back(id);
        if(p!=0) opt.push_back(up);
        int sz=opt.size();
        for(int i=0;i+1<sz;i+=2)
        {
            int b=opt[i];
            int c=opt[i+1];
            res.push_back({b,c});
            used[b]=used[c]=1;
        }
    };
    for(int i=1;i<=m;i++) if(depth[i]==0) dfs(i,0,0);
    cout << res.size() << "\n";
    for(auto [a,b]:res) cout << a << " " << b << "\n";
    return 0;
}