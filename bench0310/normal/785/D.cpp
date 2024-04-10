#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

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
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto c=[&](int a,int b)->ll
    {
        ll res=f[a];
        res=(res*finv[b])%mod;
        res=(res*finv[a-b])%mod;
        return res;
    };
    int b=0;
    for(int i=1;i<=n;i++) b+=(s[i]==')');
    int a=0;
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
        {
            a++;
            if(b>0) res=(res+c(a+b-1,a))%mod;
        }
        else b--;
    }
    cout << res << "\n";
    return 0;
}