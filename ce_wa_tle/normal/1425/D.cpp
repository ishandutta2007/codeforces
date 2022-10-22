#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2333,inf=1e9,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='.',int r='X'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct qj{ll l,r;};qj operator&(const qj&a,const qj&b){return(qj){std::max(a.l,b.l),std::min(a.r,b.r)};}
struct jx{qj x,y;}sum,q[N];jx operator&(const jx&a,const jx&b){return(jx){a.x&b.x,a.y&b.y};}
aN jc,njc,ny,a[N],x,y,c;ll C(ll n,ll m){return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;}ll calc(jx b){
return b=b&sum,b.x.l>b.x.r||b.y.l>b.y.r?0:a[b.x.r][b.y.r]-a[b.x.l-1][b.y.r]-a[b.x.r][b.y.l-1]+a[b.x.l-1][b.y.l-1];}
int main(){
    ll n=readll(),m=readll(),r=readll(),ans=0;rep(i,1,n)x[i]=readll(),y[i]=readll(),c[i]=readll(),a[x[i]][y[i]]=1,
    sum.x.r=std::max(sum.x.r,x[i]),sum.y.r=std::max(sum.y.r,y[i]),q[i]=(jx){x[i]-r,x[i]+r,y[i]-r,y[i]+r};
    rep(i,1,sum.x.r)rep(j,1,sum.y.r)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];jc[0]=njc[0]=jc[1]=njc[1]=ny[1]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;ll si,sj,sij;sum.x.l=sum.y.l=1;
    rep(i,1,n)rep(j,i+1,n)si=calc(q[i]),sj=calc(q[j]),sij=calc(q[i]&q[j]),
    ans=(ans+2*c[i]*c[j]%mod*((C(m,n)-C(m,n-si)-C(m,n-sj)+C(m,n-si-sj+sij)+2*mod)%mod))%mod;
    rep(i,1,n)ans=(ans+c[i]*c[i]%mod*(C(m,n)-C(m,n-calc(q[i]))+mod))%mod;printf("%lld\n",ans%mod);return 0;
}