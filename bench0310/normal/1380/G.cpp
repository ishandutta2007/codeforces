#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1,a.end(),greater<ll>());
    for(int i=n-1;i>=1;i--) a[i]+=a[i+1];
    ll inv=fpow(n,mod-2);
    for(int i=1;i<=n;i++)
    {
        ll res=0;
        for(int j=i+1;j<=n;j+=i) res=(res+a[j])%mod;
        res=(res*inv)%mod;
        cout << res << " \n"[i==n];
    }
    return 0;
}