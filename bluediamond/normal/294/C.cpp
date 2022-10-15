#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000+5;
const ll MOD=1000000007;

ll fact(ll x)
{
    ll ans=1,i;
    for(i=1;i<=x;i++)
        ans=(ll)ans*i%MOD;
    return ans;
}

ll expow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=(ll)ans*a%MOD;
        a=(ll)a*a%MOD;
        b/=2;
    }
    return ans;
}

int n,cnt;
int v[N];
int d[N],y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>cnt;
    for(int i=1;i<=cnt;i++)
        cin>>v[i];
    sort(v+1,v+cnt+1);
    d[++y]=v[1]-1;
    for(int i=1;i<cnt;i++)
        d[++y]=v[i+1]-v[i]-1;
    d[++y]=n-v[cnt];
    ll ans=fact(n-cnt);
    for(int i=1;i<=y;i++)
    {
        ll x=expow(fact(d[i]),MOD-2);
        ans=(ll)ans*x%MOD;
    }
    for(int i=2;i<y;i++)
    {
        if(d[i]==0) continue;
        ll x=expow(2,d[i]-1);
        ans=(ll)ans*x%MOD;
    }
    cout<<ans<<"\n";
    return 0;
}