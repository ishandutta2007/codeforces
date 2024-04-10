#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7,mod2=mod*mod,e7=1e7;typedef ll aN[N],ae7[e7+7];aN lim,d;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ae7 p,mu,mn,cnt;ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}struct yz{ll l[258],t,val;yz(){l[t=0]=1;}
void set(ll x){
    val=x,t=0;while(x!=1)x/=l[1<<t>>1]!=mn[x]?l[1<<t++]=mn[x]:mn[x];ref(i,0,(1<<t))l[i]=l[i&-i]*l[i&~-i];
    t=1<<t;per(i,t,1)l[i]=l[i-1];
}}a[N];
void getd(ll n){
    rep(i,1,n)if(!lim[i]){d[i]=0;rep(j,1,a[i].t)cnt[a[i].l[j]]++;}
    rep(i,1,n)if(!lim[i])rep(j,1,a[i].t)d[i]+=mu[a[i].l[j]]*cnt[a[i].l[j]];
    rep(i,1,n)if(!lim[i])rep(j,1,a[i].t)cnt[a[i].l[j]]=0;
}int check(ll mid,ll k){getd(mid);rep(i,1,mid)if(!lim[i])k-=!!d[i];return k<=3;}
int main(){
    ll n=readll(),k=readll();ll top=0,t=0,f=0;mu[1]=1;
    rep(i,2,e7){if(!p[i])mu[mn[p[++top]=i]=i]=-1;rfor(ll j=1,x;j<=top&&(x=i*p[j])<=e7;j++)
    {mn[x]=p[j],p[x]=1,mu[x]=-mu[i];if(i%p[j]==0){mu[x]=0;break;}}}rep(i,1,n)a[i].set(readll());getd(n);//if(n==5000)exit(0);
    rep(i,1,n)if(d[i]>=2)f=i;else if(!d[i])t++;if(t>=k){rep(i,1,n)if(!d[i]&&k-->0)printf("%lld ",i);return 0;}
    if(!f){rep(i,1,n){ll s=0;rep(j,1,a[i].t)s+=mu[a[i].l[j]]*cnt[a[i].l[j]]++;if(!s&&k-->0)printf("%lld ",i);}return 0;}
    ll lp=f;top=0,lim[f]=1;rep(i,1,n)if(gcd(a[i].val,a[f].val)==1&&++top<=2)lim[lp=i]=1;getd(n);//if(n==499)
    t=0;rep(i,1,n)if(!d[i])t++,lim[i]=-1;if(t>=k){rep(i,1,n)if(!d[i]&&k-->0)printf("%lld ",i);return 0;}
    ll l=0,r=n;while(l<=r){ll mid=(l+r)>>1;if(check(mid,k))r=mid-1;else l=mid+1;}const ll p=r+1;k-=3;
    ll lst=0;getd(p);rep(i,1,p)if(!lim[i]&&d[i])k--,lim[i]=1;rep(i,1,p)if(gcd(a[p].val,a[i].val)==1&&k++<0)lim[lst=i]=0;
    if(p&&k<=0)lim[lst]=1,lim[lp]=0;rep(i,1,n)if(lim[i]==1)printf("%lld ",i);return 0;
}