#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(3*n+1,1);
    vector<ll> inv(3*n+1,1);
    vector<ll> finv(3*n+1,1);
    for(int i=2;i<=3*n;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    auto ch=[&](int a,int b)->ll{return (a>=b?mul(f[a],mul(finv[b],finv[a-b])):0);};
    vector<array<ll,3>> dp(3*n+1,{0,0,0});
    dp[0]={n,n,n};
    for(int i=1;i<=3*n;i++)
    {
        auto &[a,b,c]=dp[i];
        auto [xa,xb,xc]=dp[i-1];
        a=mul(sub(sub(ch(3*n,i+1),mul(2,xa)),xb),inv[3]);
        b=add(a,xa);
        c=sub(ch(3*n,i+1),add(a,b));
    }
    while(q--)
    {
        int x;
        cin >> x;
        cout << add(dp[x][0],ch(3*n,x)) << "\n";
    }
    return 0;
}