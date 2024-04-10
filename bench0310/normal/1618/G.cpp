#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    vector<array<int,2>> v(n+m+1,{0,0});
    for(int i=1;i<=n+m;i++)
    {
        int a;
        cin >> a;
        v[i]={a,(i<=n)};
    }
    ranges::sort(v);
    vector<ll> sum(n+m+1,0);
    for(int i=1;i<=n+m;i++) sum[i]=sum[i-1]+v[i][0];
    vector<int> c(n+m+1,0);
    vector<int> l(n+m+1,0);
    vector<int> r(n+m+1,0);
    for(int i=1;i<=n+m;i++)
    {
        c[i]=v[i][1];
        l[i]=r[i]=i;
    }
    vector<array<int,2>> u;
    for(int i=1;i<=n+m-1;i++) u.push_back({v[i+1][0]-v[i][0],i});
    ranges::sort(u);
    int idx=0;
    auto e=[&](int i)->ll{return (sum[i]-sum[i-c[i]]);};
    ll s=0;
    for(int i=1;i<=n+m;i++) s+=e(i);
    vector<array<int,2>> queries;
    for(int i=1;i<=q;i++)
    {
        int k;
        cin >> k;
        queries.push_back({k,i});
    }
    ranges::sort(queries);
    vector<ll> res(q+1,0);
    for(auto [k,id]:queries)
    {
        while(idx<n+m-1&&u[idx][0]<=k)
        {
            int x=u[idx][1];
            idx++;
            int nl=l[x];
            int nr=r[x+1];
            s-=(e(x)+e(nr));
            c[nl]=c[nr]=(c[x]+c[x+1]);
            l[nl]=l[nr]=nl;
            r[nl]=r[nr]=nr;
            s+=e(nr);
        }
        res[id]=s;
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}