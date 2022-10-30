#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll quick(ll a,ll b)
{
    ll ret=1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
const int maxn=5e3+7;
ll fac[maxn],inv[maxn];
typedef vector<int> vi;
vi mul(vi& a,vi& b)
{
    vi ret(a.size()+b.size()-1);
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
            ret[i+j]=(ret[i+j]+1LL*a[i]*b[j]%mod)%mod;
    }
    return ret;
}
ll np[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    fac[0]=1;
    np[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod;
    for(int i=0;i<maxn;i++) inv[i]=quick(fac[i],mod-2);
    vi a(n);
    ll tot=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        tot=tot*a[i]%mod;
    }
    vi pl={1};
    for(int i=0;i<n;i++)
    {
        vi cur={a[i],mod-1};
        pl=mul(pl,cur); 
    }
    //for(auto u:pl) cout<<u<<" ";
    //cout<<endl;
    ll ans=0;
    ll inf=1;
    for(int i=0;i<min(k+1,(int)pl.size());i++)
    {
        ans=(ans+pl[i]*inf%mod*quick(n,k-i)%mod)%mod;
        inf=inf*(k-i)%mod;
    }
    ans=ans*quick(quick(n,k),mod-2)%mod;
    cout<<(tot-ans+mod)%mod<<'\n';
}