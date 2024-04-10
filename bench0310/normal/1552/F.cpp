#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<int> s(n);
    for(int i=0;i<n;i++) cin >> x[i] >> y[i] >> s[i];
    vector<ll> c(n);
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    vector<ll> sum(n,0);
    ll res=(x[n-1]+1)%mod;
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(x.begin(),x.end(),y[i]);
        if(i>0) sum[i]=sum[i-1];
        int t=(it-x.begin());
        c[i]=sum[i];
        if(t>0) c[i]=sub(c[i],sum[t-1]);
        c[i]=add(c[i],x[i]-y[i]);
        sum[i]=add(sum[i],c[i]);
        if(s[i]==1) res=add(res,c[i]);
    }
    cout << res << "\n";
    return 0;
}