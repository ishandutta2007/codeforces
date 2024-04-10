#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> s(n,0);
    vector<int> pos(n+1,-1);
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        pos[s[i]]=i;
    }
    int forced=0;
    for(int i=0;i<n-1;i++) forced+=(pos[s[i]+1]>pos[s[i+1]+1]);
    const ll mod=998244353;
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(n+k+1,1);
    vector<ll> inv(n+k+1,1);
    vector<ll> finv(n+k+1,1);
    for(int i=2;i<=n+k;i++)
    {
        f[i]=mul(f[i-1],i);
        inv[i]=mod-mul(mod/i,inv[mod%i]);
        finv[i]=mul(finv[i-1],inv[i]);
    }
    auto c=[&](int a,int b)->ll
    {
        if(a<0||b<0||a<b) return 0;
        return mul(f[a],mul(finv[b],finv[a-b]));
    };
    cout << c(n+k-1-forced,k-1-forced) << "\n";
    return 0;
}