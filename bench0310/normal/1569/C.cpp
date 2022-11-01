#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const ll mod=998244353;
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        int m=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            m=max(m,a[i]);
        }
        int mx=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            mx+=(a[i]==m);
            cnt+=(a[i]==m-1);
        }
        vector<ll> f(n+1,1);
        vector<ll> inv(n+1,1);
        for(int i=2;i<=n;i++)
        {
            f[i]=mul(f[i-1],i);
            inv[i]=mod-mul(mod/i,inv[mod%i]);
        }
        if(mx>1) cout << f[n] << "\n";
        else cout << mul(f[n],mul(cnt,inv[cnt+1])) << "\n";
    }
    return 0;
}