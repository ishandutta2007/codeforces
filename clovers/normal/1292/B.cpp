#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define mk make_pair
const int N=300010;
const ll T=(ll)1e16;
ll _abs(ll x){return x<0 ? -x : x;}

ll dis(pii p,pii q)
{
    return _abs(p.first-q.first)+_abs(p.second-q.second);
}

ll n=0,xs,ys,t,ax,ay,bx,by,ans=0;
pii a[N];
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld",&a[0].first,&a[0].second,&ax,&ay,&bx,&by);
    scanf("%lld%lld%lld",&xs,&ys,&t);
    while(a[n].first<=2*T&&a[n].second<=2*T)
    {
        a[n+1].first=a[n].first*ax+bx; 
        a[n+1].second=a[n].second*ay+by;
        n++;
    }
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ll sum=0,tmp=0;
        sum+=dis(a[i],mk(xs,ys));
        if(sum<=t) tmp++; 
        for(int j=i;j>0;j--) 
        {
            sum+=dis(a[j-1],a[j]);
            if(sum>t) break;
            tmp++;
        }
        sum+=dis(a[0],a[i]);
        for(int j=i;j<n;j++)
        {
            sum+=dis(a[j],a[j+1]);
            if(sum>t) break;
            tmp++;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}