#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=300000;

ll len,x,y;
ll n,v[N+5];
string a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>len>>x>>y;
    cin>>a;
    v[1]=a[0]-'0';
    n=1;
    for(ll i=1;i<len;i++)
    {
        ll x=a[i]-'0';
        if(x!=v[n])
            v[++n]=x;
    }
    if(n==1 && v[1]==1)
    {
        cout<<"0\n";
        return 0;
    }
    ll cnt=0;
    for(ll i=1;i<=n;i++)
        if(v[i]==0)
            cnt++;
    ll ans=(1LL<<60);
    for(ll a=0;a+1<=cnt;a++)
    {
        ans=min(ans,x*a+(cnt-1-a)*y);
    }
    cout<<ans+y<<"\n";
    return 0;
}
/**

**/