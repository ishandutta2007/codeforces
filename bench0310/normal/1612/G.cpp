#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> m;
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto sub=[&](ll a,ll b)->ll{return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> f(m+1,1);
    for(int i=1;i<=m;i++) f[i]=mul(f[i-1],i);
    auto s=[&](ll a)->ll{return mul(mul(a%mod,(a+1)%mod),(mod+1)/2);};
    auto t=[&](ll a,ll b)->ll{return sub(s(b),s(a-1));};
    const int N=1000000;
    vector<int> d(2*N+1,0);
    for(int i=1;i<=m;i++)
    {
        int c;
        cin >> c;
        d[-c+1+N]++;
        if(c+1<=N) d[c+1+N]--;
    }
    ll p=1;
    ll sum=0;
    ll cnt=1;
    for(int i=-N+1;i<=N-1;i++)
    {
        if(i>=-N+2) d[i+N]+=d[i-2+N];
        int x=d[i+N];
        sum=add(sum,mul(i+mod,t(p,p+x-1)));
        p+=x;
        cnt=mul(cnt,f[x]);
    }
    cout << sum << " " << cnt << "\n";
    return 0;
}