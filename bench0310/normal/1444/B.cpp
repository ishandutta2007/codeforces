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
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    ll f=1;
    for(ll i=1;i<=n;i++) f=(f*i)%mod;
    ll t=fpow(f,mod-2);
    ll res=(t*t)%mod;
    for(ll i=n+1;i<=2*n;i++) f=(f*i)%mod;
    res=(res*f)%mod;
    ll sum=0;
    for(int i=0;i<2*n;i++)
    {
        if(i<n) sum=(sum-v[i])%mod;
        else sum=(sum+v[i])%mod;
    }
    if(sum<0) sum+=mod;
    res=(res*sum)%mod;
    cout << res << "\n";
    return 0;
}