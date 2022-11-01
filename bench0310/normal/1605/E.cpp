#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ifloor(ll a,ll b)
{
    int s=((a<0)^(b<0));
    a=abs(a); b=abs(b);
    if(s==0) return (a/b);
    else return -((a+b-1)/b);
}

struct obj
{
    ll k,n;
    obj(){k=n=0;}
    obj(ll a,ll b){k=a;n=b;}
    friend obj operator+(const obj &a,const obj &b){return obj(a.k+b.k,a.n+b.n);}
    friend obj operator-(const obj &a,const obj &b){return obj(a.k-b.k,a.n-b.n);}
    ll e(ll x){return (k*x+n);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<obj> a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i].n;
    vector<obj> b(n+1);
    cin >> b[1].k;
    b[1].k=1;
    for(int i=2;i<=n;i++) cin >> b[i].n;
    vector<pair<ll,obj>> e;
    obj o;
    auto add=[&](obj f)
    {
        if(f.k==0) o.n+=abs(f.n);
        else
        {
            if(f.k>0) f=obj()-f;
            o=o+f;
            e.push_back({ifloor(-f.n,f.k),f});
        }
    };
    for(int i=1;i<=n;i++)
    {
        obj t=b[i]-a[i];
        add(t);
        for(int j=i;j<=n;j+=i) a[j]=a[j]+t;
    }
    ranges::sort(e,[&](const pair<int,obj> &x,const pair<int,obj> &y){return (x.first<y.first);});
    int q;
    cin >> q;
    vector<array<int,2>> queries(q);
    for(int i=0;i<q;i++)
    {
        auto &[x,j]=queries[i];
        cin >> x;
        j=i;
    }
    ranges::sort(queries);
    int l=0;
    vector<ll> res(q,0);
    for(auto [x,j]:queries)
    {
        while(l<(int)e.size()&&e[l].first<x)
        {
            obj f=e[l].second;
            o=o-f-f;
            l++;
        }
        res[j]=o.e(x);
    }
    for(int i=0;i<q;i++) cout << res[i] << "\n";
    return 0;
}