#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        const ll mod=1000000007;
        auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
        auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
        vector<ll> p(n+1,1);
        for(int i=1;i<=n;i++) p[i]=mul(p[i-1],2);
        vector<ll> pw(k+1,1);
        for(int i=1;i<=k;i++) pw[i]=mul(pw[i-1],p[n]);
        ll res=0;
        ll opt=1;
        for(int i=1;i<=k;i++)
        {
            if((n%2)==0) res=add(res,mul(opt,pw[k-i]));
            ll now=p[n-1]-((n%2)==0)+(n&1);
            opt=mul(opt,now);
        }
        res=add(res,opt);
        cout << res << "\n";
    }
    return 0;
}