#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    auto solve=[&](vector<ll> a)->ll
    {
        vector<ll> sum(n+1,0);
        vector<int> czero(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum[i]=sum[i-1]+a[i];
            czero[i]=czero[i-1]+(a[i]==0);
        }
        auto opt=[&](int l,int r)->array<ll,2>
        {
            ll s=sum[r]-sum[l];
            int c=czero[r]-czero[l];
            return {s-c*k,s+c*k};
        };
        auto [tl,tr]=opt(0,n);
        if(tr<0||tl>0) return -1;
        ll res=0;
        for(int i=0;i<=n;i++) //mn
        {
            for(int j=i;j<=n;j++) //mx
            {
                auto [al,ar]=opt(0,i);
                auto [bl,br]=opt(i,j);
                auto [cl,cr]=opt(j,n);
                ar=min(ar,ll(0));
                if(al>0) continue;
                al=max(al,-br);
                if(al>ar) continue;
                ll t=max({ll(0),al+br+cl,-(al+br+cr)});
                res=max(res,-al+(al+br)+1-t);
            }
        }
        return res;
    };
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll res=solve(a);
    for(int i=1;i<=n;i++) a[i]=-a[i];
    cout << max(res,solve(a)) << "\n";
    return 0;
}