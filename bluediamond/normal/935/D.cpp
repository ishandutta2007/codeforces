#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nmax=1e5,mod=1e9+7;
ll n,m,v1[nmax+5],v2[nmax+5];
ll nr1[nmax+5],nr2[nmax+5];
ll i,j;
ll nr_bune,nr_total,XY;
ll expow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
void cl()
{
    nr_bune%=mod;
}
int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>v1[i];
    for(i=1;i<=n;i++)
        cin>>v2[i];
    for(i=n;i>=1;i--)
    {
        nr1[i]=nr1[i+1];
        nr2[i]=nr2[i+1];
        if(v1[i]==0)
            nr1[i]++;
        if(v2[i]==0)
            nr2[i]++;
    }
    nr_total=expow(m,nr1[1]+nr2[1]);
    for(i=1;i<=n;i++)
    {
        ll val=expow(m,nr1[i+1]+nr2[i+1]+XY);
        if(v1[i] and v2[i])
        {
            if(v1[i]==v2[i])
                continue;
            if(v1[i]>v2[i])
                nr_bune+=val;
            cl();
            break;
        }
        if(v1[i]==0 and v2[i]==0)
        {
            ll X=m*(m-1)/2;
            X%=mod;
            nr_bune+=X*val;
            XY++;
        }
        if(v1[i]==0 and v2[i])
            nr_bune+=(m-v2[i])*val;
        if(v1[i] and v2[i]==0)
            nr_bune+=(v1[i]-1)*val;
        cl();
    }
    ll ans;
    ans=nr_bune*expow(nr_total,mod-2)%mod;
    cout<<ans;
    return 0;
}
/**
**/