#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=3116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN s,p,out;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int cmp(ll a,ll b){return s[a]<s[b];}
int main(){//IO(1380E);
    ll n=readll(),h=readll(),m=readll(),k=m/2-readll();rep(i,1,n)readll(),s[i]=readll()%(m/2);rep(i,1,n)s[i+n]=s[i]+m/2;
    rep(i,1,n)p[i]=i;std::sort(p+1,p+n+1,cmp);rep(i,1,n)p[i+n]=p[i]+n;ll r=1,ans=1,t=s[p[1]];
//    rep(i,1,n*2)printf("s=%lld\n",s[p[i]]);printf("%lld\n",k);
    rep(l,1,n)while(r<2*n&&s[p[r+1]]-s[p[l]]<=k&&r+1-l+1<=n)if(++r-l+1>=ans)ans=r-l+1,t=s[p[l]];
    printf("%lld %lld\n",n-ans,t);rep(i,1,n)if(s[p[i]]<t&&s[p[i]+n]>t+k||s[p[i]]>t+k)out[++cnt]=p[i];
    std::sort(out+1,out+cnt+1);if(n-ans==-80444)printf("%lld:",cnt);rep(i,1,cnt)printf("%lld ",out[i]);(void)h;return 0;
}