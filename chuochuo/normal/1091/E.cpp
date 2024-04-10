#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],dummy[MAXN];
ll C(ll x)
{
    if(x>=n+1) return 1;
    for(ll i=1;i<=n;i++) dummy[i]=a[i];
    dummy[n+1]=x;
    sort(dummy+1,dummy+n+2,greater<int>());
    ll sum=0,ss=0;
    ll pos=n+1;
    for(ll i=1;i<=n+1;i++)
    {
        sum+=dummy[i];
        while(pos>i&&dummy[pos]<=i) ss+=dummy[pos],pos--;
        if(pos<i) ss-=dummy[i];
        if(sum>1LL*i*(i-1)+ss+1LL*max(0LL,pos-i)*i)
        {
            return dummy[i]>x?0:1; 
        }
    }
    return 2;
}
int main()
{
    scanf("%lld",&n);
    ll parity=0;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) if(a[i]&1) parity^=1;
    ll l=0,r=n/2,rec1=-1,rec2=-1;
    while(r>=l)
    {
        ll mid=(l+r)/2;
        ll ans=C(mid*2+parity);
        if(ans==2) 
        {
            r=mid-1;
            rec1=mid;
        }
        else if(ans==0) l=mid+1;
        else r=mid-1;
    }
    if(rec1==-1) {puts("-1"); return 0;}
    l=rec1; r=n/2;
    while(r>=l)
    {
        ll mid=(l+r)/2;
        ll ans=C(mid*2+parity);
        if(ans==2)
        {
            l=mid+1;
            rec2=mid;
        }
        else r=mid-1;
    }
    for(ll i=rec1;i<=rec2;i++) printf("%lld ",i*2+parity);
    return 0;
}