#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sv;
ll test(ll x)
{
    ll p2=1;
    ll ret=0;
    while(p2*x<=sv)
    {
        ll h=min(sv,p2*(x+1)-1);
        ret+=h-p2*x+1;
        p2*=2;
    }
    return ret;
}
ll calc(ll x)
{
    if(x%2==0) return test(x)+test(x+1);
    return test(x);
}
int main()
{
    ll n,k;
    cin>>n>>k;
    sv=n;
    ll ans=1;
    while(n)
    {
        for(ll i=0;i<10;i++)
        {
            if(i>=n) continue;
            if(calc(n-i)>=k)
                ans=max(ans,n-i);
        }
        n/=2;
    }
    cout<<ans<<endl;
}