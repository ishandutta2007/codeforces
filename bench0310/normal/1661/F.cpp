#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    ll lim;
    cin >> lim;
    auto f=[&](ll d,ll c)->ll
    {
        ll o=(d/c);
        ll r=(d%c);
        return (o*o*(c-r)+(o+1)*(o+1)*r);
    };
    auto g=[&](ll d,ll m)->array<ll,2>
    {
        ll l=1,r=d+1;
        while(l<r-1)
        {
            ll t=(l+r)/2;
            if(f(d,t-1)-f(d,t)>=m) l=t;
            else r=t;
        }
        return {f(d,l),l-1};
    };
    ll l=1,r=(1ll<<60);
    while(l<r-1)
    {
        ll m=(l+r)/2;
        ll cost=0;
        for(int i=0;i<n;i++) cost+=g(a[i+1]-a[i],m)[0];
        if(cost<=lim) l=m;
        else r=m;
    }
    ll cost=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        auto [x,y]=g(a[i+1]-a[i],l);
        cost+=x;
        cnt+=y;
    }
    cout << cnt-(lim-cost)/l << "\n";
    return 0;
}