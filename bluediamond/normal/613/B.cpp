#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=(ll)1e5+7;

ll n;
ll A;
ll cf;
ll cm;
ll m;

ll v[N];
ll s[N];

ll id[N];

bool cmp(ll f,ll s)
{
        return v[f]<v[s];
}
ll kek[N];

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        ///freopen("aaaaa","r",stdin);
        ///freopen("bbbbb","w",stdout);
        cin>>n>>A>>cf>>cm>>m;
        ll m2=m;
        for(ll i=1;i<=n;i++)
        {
                id[i]=i;
                cin>>v[i];
        }
        sort(id+1,id+n+1,cmp);
        sort(v+1,v+n+1);
        for(ll i=1;i<=n;i++)
        {
                s[i]=s[i-1]+v[i];
        }
        ll take=n;
        ll answer=0;
        for(ll cnt=0;cnt<=n;cnt++)
        {
                if(cnt!=0)
                {
                        m-=(A-v[take]);
                        take--;
                }
                if(m<0) break;
                ll lo=0;
                ll hi=A;
                ll currr=0;
                while(lo<=hi)
                {
                        ll mid=(lo+hi)>>1;
                        ll l2=1;
                        ll r2=take;
                        ll res=0;
                        while(l2<=r2)
                        {
                                ll mid2=(l2+r2)>>1;
                                if(v[mid2]<mid)
                                {
                                        res=mid2;
                                        l2=mid2+1;
                                }
                                else
                                {
                                        r2=mid2-1;
                                }
                        }
                        ll co=res*mid-s[res];
                        if(co<=m)
                        {
                                currr=mid;
                                lo=mid+1;
                        }
                        else
                        {
                                hi=mid-1;
                        }
                }
                answer=max(answer,cf*cnt+cm*currr);
        }
        take=n;
        m=m2;
        for(ll cnt=0;cnt<=n;cnt++)
        {
                if(cnt!=0)
                {
                        m-=(A-v[take]);
                        take--;
                }
                if(m<0) break;
                ll lo=0;
                ll hi=A;
                ll currr=0;
                while(lo<=hi)
                {
                        ll mid=(lo+hi)>>1;
                        ll l2=1;
                        ll r2=take;
                        ll res=0;
                        while(l2<=r2)
                        {
                                ll mid2=(l2+r2)>>1;
                                if(v[mid2]<mid)
                                {
                                        res=mid2;
                                        l2=mid2+1;
                                }
                                else
                                {
                                        r2=mid2-1;
                                }
                        }
                        ll co=res*mid-s[res];
                        if(co<=m)
                        {
                                currr=mid;
                                lo=mid+1;
                        }
                        else
                        {
                                hi=mid-1;
                        }
                }
                if(answer==cf*cnt+cm*currr)
                {
                        cout<<answer<<"\n";
                        for(ll i=1;i<=take;i++)
                        {
                                kek[id[i]]=max(v[i],currr);
                        }
                        for(ll i=take+1;i<=n;i++)
                        {
                                kek[id[i]]=A;
                        }
                        for(ll i=1;i<=n;i++)
                        {
                                kek[i]=min(kek[i],A);
                                cout<<kek[i]<<" ";
                        }
                        cout<<"\n";
                        return 0;
                }
        }
        return 0;
}
/**

**/