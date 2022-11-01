#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(auto &[c,a,b]:edges) cin >> a >> b >> c;
    ranges::sort(edges);
    vector<int> ch={0};
    for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) ch.push_back((edges[i][0]+edges[j][0]+2)/2);
    ranges::sort(ch);
    vector<vector<int>> opt;
    vector<vector<ll>> sum;
    for(int x:ch)
    {
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        function<int(int)> find_set=[&](int a)
        {
            if(p[a]==a) return a;
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
        ranges::sort(edges,[&](const auto &a,const auto &b){return (abs(a[0]-x)<abs(b[0]-x));});
        vector<int> now;
        for(auto [c,a,b]:edges) if(merge_sets(a,b)) now.push_back(c);
        ranges::sort(now);
        vector<ll> s(n-1);
        for(int i=0;i<n-1;i++) s[i]=(i>0?s[i-1]:0)+now[i];
        opt.push_back(now);
        sum.push_back(s);
    }
    int p,k,a,b,c;
    cin >> p >> k >> a >> b >> c;
    ll res=0;
    int q=0;
    for(int i=1;i<=k;i++)
    {
        if(i<=p) cin >> q;
        else q=(ll(q)*a+b)%c;
        int id=(ranges::upper_bound(ch,q)-ch.begin())-1;
        vector<int> &e=opt[id];
        vector<ll> &s=sum[id];
        int l=(ranges::upper_bound(e,q)-e.begin());
        int r=(n-1-l);
        ll now=(ll(l)*q-(l>0?s[l-1]:0))+(s[n-2]-(l>0?s[l-1]:0)-ll(r)*q);
        res^=now;
    }
    cout << res << "\n";
    return 0;
}