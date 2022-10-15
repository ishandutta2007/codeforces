#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=500+5;
const ll MOD=998244353;

int n;
ll v[N];

map<ll,int>f;

ll rad(ll x)
{
    ll r=sqrt(x);
    if(r*r==x)
    {
        return r;
    }
    else
    {
        return -1;
    }
}

ll mul(ll x,ll y)
{
    if(x==-1 || y==-1)
    {
        return -1;
    }
    ll a=x*y;
    if(a%x==0 && a%y==0 && a/x==y && a/y==x)
    {
        return a;
    }
    else
    {
        return -1;
    }
}

bool ns[N];

map<ll,int>ncs;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
   /// cout<<"\t\t";
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        ll r=rad(v[i]);
        if(r==-1) /// 4 divi
        {
            ll r=0LL;
            ll pas=(1LL<<30);
            while(pas)
            {
                ll x=r+pas;
                ll val=mul(x,mul(x,x));
                if(val!=-1 && val<=v[i])
                {
                    r+=pas;
                }
                pas/=2;
            }
            if(mul(r,mul(r,r))==v[i]) /// a*a*a
            {
                f[r]+=3;
            }
            else /// a*b
            {
                ns[i]=1;
            }
        }
        else
        {
            ll r2=rad(r);
            if(r2==-1) /// 3 divi
            {
                f[r]+=2;
            }
            else /// 5 divi
            {
                f[r2]+=4;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ns[i])
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                ll g=__gcd(v[i],v[j]);
                if(g!=1 && g!=v[i])
                {
                    f[g]++;
                    f[v[i]/g]++;
                    ns[i]=0;
                    break;
                }
            }
        }
    }
    ll ans=1LL;
    for(int i=1;i<=n;i++)
    {
        if(ns[i])
        {
            ncs[v[i]]++;
        }
    }
    for(auto &it:ncs)
    {
        ans*=(it.second+1); ans%=MOD;
        ans*=(it.second+1); ans%=MOD;
    }
    for(auto &it:f)
    {
        ans*=(it.second+1LL);
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}