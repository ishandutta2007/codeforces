#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> v[N];
multiset<ll> ds[N];
multiset<ll> us[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll sum=0;
    for(int i=1;i<=n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        sum+=c;
    }
    vector<ll> d(n+1,0);
    vector<ll> u(n+1,0);
    auto ins=[&](multiset<ll> &s,ll x){s.insert(x);};
    auto ers=[&](multiset<ll> &s,ll x){s.erase(s.find(x));};
    auto sumcnt=[&](multiset<ll> &s,int c)
    {
        ll x=0;
        auto it=s.rbegin();
        while(c--)
        {
            if(it!=s.rend())
            {
                x+=(*it);
                it++;
            }
        }
        return x;
    };
    auto upd=[&](int a)
    {
        d[a]=max(sumcnt(ds[a],1),sumcnt(us[a],2));
        u[a]=sumcnt(us[a],1);
    };
    auto dfs=[&](auto &&self,int a,int p)->void
    {
        for(auto [to,c]:v[a])
        {
            if(to==p) continue;
            self(self,to,a);
            ins(ds[a],d[to]);
            ins(us[a],u[to]+c);
        }
        upd(a);
    };
    dfs(dfs,1,0);
    ll res=(n>1?(1ll<<60):0);
    auto reroot=[&](int a,int b,int c)
    {
        ers(ds[a],d[b]);
        ers(us[a],u[b]+c);
        upd(a);
        res=min(res,2*(sum-c)-d[a]-d[b]);
        ins(ds[b],d[a]);
        ins(us[b],u[a]+c);
        upd(b);
    };
    auto go=[&](auto &&self,int a,int p)->void
    {
        res=min(res,2*sum-sumcnt(us[a],4));
        for(auto [to,c]:v[a])
        {
            if(to==p) continue;
            reroot(a,to,c);
            self(self,to,a);
            reroot(to,a,c);
        }
    };
    go(go,1,0);
    cout << res << "\n";
    return 0;
}