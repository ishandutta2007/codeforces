#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool ok(ll lft,ll val,ll need)
{
        if(lft<need)
        {
                ll x=need-lft;
                val-=x;
        }
        return (val>=2*need);
}


int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ll n,res=0;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
        {
                cin>>v[i];
        }
        ll sol=0,lft=0;
        for(ll i=0;i<n;i++)
        {
                ll l=0;
                ll r=1e9;
                ll take=0;
                while(l<=r)
                {
                        ll m=(l+r)>>1;
                        if(ok(lft,v[i],m))
                        {
                                take=m;
                                l=m+1;
                        }
                        else
                        {
                                r=m-1;
                        }
                }
                if(lft<take)
                {
                        ll dif=take-lft;
                        lft+=dif;
                        v[i]-=dif;
                }
                lft-=take;
                v[i]-=(2*take);
                lft+=v[i];
                res+=take;
               /// cout<<take<<" ";
        }
       // cout<<"\n";
        cout<<res<<"\n";
        return 0;
}
/**

**/