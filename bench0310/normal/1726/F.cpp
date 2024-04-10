#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    vector<int> g(n+1,0);
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> g[i] >> c[i];
    ll res=0;
    vector<int> o(n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        cin >> o[i];
        res+=o[i];
    }
    set<array<ll,4>> e; //r,l,x,d
    e.insert({t-1,0,0,0});
    int s=0; //a is at a+s
    auto split=[&](int p) //splits p-1 and p
    {
        if(p==0||p==t) return;
        auto it=e.lower_bound({p,0,0,0});
        auto [r,l,x,d]=(*it);
        if(l<=p-1)
        {
            e.erase(it);
            e.insert({p-1,l,x,d});
            e.insert({r,p,x+(p-l)*d,d});
        }
    };
    auto clean=[&](int l,int r)
    {
        split(l);
        split(r+1);
        while(1)
        {
            auto it=e.lower_bound({l,0,0,0});
            if(it!=e.end()&&(*it)[0]<=r) e.erase(it);
            else break;
        }
    };
    auto upd=[&](int l,int r,ll x,ll d)
    {
        l=(l+s)%t;
        r=(r+s)%t;
        if(l<=r)
        {
            clean(l,r);
            e.insert({r,l,x,d});
        }
        else
        {
            clean(l,t-1);
            e.insert({t-1,l,x,d});
            clean(0,r);
            e.insert({r,0,x+(t-l)*d,d});
        }
    };
    auto qry=[&](int p)->ll
    {
        p=(p+s)%t;
        auto [r,l,x,d]=*e.lower_bound({p,0,0,0});
        return (x+(p-l)*d);
    };
    for(int i=n;i>=1;i--)
    {
        if(i<n) s=(ll(s)+o[i]+c[i+1]-c[i]+t)%t;
        ll x=qry(0);
        upd(g[i],t-1,x+t-g[i],-1);
    }
    ll opt=(1ll<<60);
    for(auto [r,l,x,d]:e) opt=min(opt,x+(r-l)*d);
    cout << res+opt << "\n";
    return 0;
}