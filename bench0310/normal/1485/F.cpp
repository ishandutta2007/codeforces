#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (((a-b)%mod)+mod)%mod;};
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll d=0;
        map<ll,ll> m;
        ll sum=1;
        m[0]=1;
        for(int i=1;i<=n;i++)
        {
            ll b;
            cin >> b;
            ll dp=sub(sum,m[-d]);
            d+=b;
            m[b-d]=add(m[b-d],dp);
            sum=add(sum,dp);
        }
        ll res=0;
        for(auto [x,y]:m) res=add(res,y);
        cout << res << "\n";
    }
    return 0;
}