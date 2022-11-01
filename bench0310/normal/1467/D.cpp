#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    int n,k,q;
    cin >> n >> k >> q;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<ll> c(n+1,0);
    vector<vector<ll>> to(n+1,vector<ll>(k+1,0));
    for(int j=1;j<=n;j++) to[j][0]=1;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int z:{-1,1})
            {
                if(1<=j+z&&j+z<=n)
                {
                    to[j+z][i]=add(to[j+z][i],to[j][i-1]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            c[i]=add(c[i],mul(to[i][j],to[i][k-j]));
        }
    }
    ll res=0;
    for(int i=1;i<=n;i++) res=add(res,mul(a[i],c[i]));
    while(q--)
    {
        int i;
        ll x;
        cin >> i >> x;
        res=sub(res,mul(a[i],c[i]));
        a[i]=x;
        res=add(res,mul(a[i],c[i]));
        cout << res << "\n";
    }
    return 0;
}