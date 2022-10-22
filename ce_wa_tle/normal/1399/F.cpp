#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6333,inf=1e9,mod=1e9+7;typedef ll aN[N];
ll tag[N<<2],val[N<<2];ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,l,r,p;int dp[N][N];ll cnt=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;};
void calc(int cases){
    ll n=readll();cnt=0;ll cnt=0;rep(i,1,n)p[++cnt]=l[i]=readll(),p[++cnt]=r[i]=readll()+1;
    std::sort(p+1,p+cnt+1),cnt=std::unique(p+1,p+cnt+1)-p-1;rep(i,1,n)
    l[i]=std::lower_bound(p+1,p+cnt+1,l[i])-p,r[i]=std::lower_bound(p+1,p+cnt+1,r[i])-p,
    add(l[i],r[i]),add(r[i],l[i]);
    rep(len,1,cnt)rep(l,1,cnt-len){
        ll r=l+len,flag=0;dp[l][r]=std::max(dp[l+1][r],dp[l][r-1]);
//        printf("dp[%lld][%lld]=%lld %lld\n",l,r,dp[l][r],flag);
        rfor(ll i=head[l];i;i=next[i])if(to[i]>l&&to[i]<=r){
            if(to[i]==r)flag++;else dp[l][r]=std::max(dp[l][r],dp[l][to[i]]+dp[to[i]][r]);
        }
        rfor(ll i=head[r];i;i=next[i])if(to[i]<r&&to[i]>=l){
            if(to[i]==l)flag++;else dp[l][r]=std::max(dp[l][r],dp[l][to[i]]+dp[to[i]][r]);
        }
        dp[l][r]+=flag>>1;
//        printf("dp[%lld][%lld]=%lld %lld\n",l,r,dp[l][r],flag);
    }printf("%lld\n",(ll)dp[1][cnt]);rep(i,1,cnt)head[i]=0;(void)cases;
}
int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}