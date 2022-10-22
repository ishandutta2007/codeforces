#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=998244353;typedef ll aN[N];ll n,m;ll p[1145],t[1145];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll q1(ll len,ll l1,ll l2){printf("? %lld %lld %lld 1 %lld 1\n",len,m,l1,l2),fflush(stdout);return readll();}
ll q2(ll len,ll l1,ll l2){printf("? %lld %lld 1 %lld 1 %lld\n",n,len,l1,l2),fflush(stdout);return readll();}
ll calc(ll n,ll(*query)(ll,ll,ll)){
    ll ln=n,ans=1,cnt=0;rfor(ll i=2;i*i<=n;i++)if(!(n%i))for(p[++cnt]=i;!(n%i);n/=i,t[cnt]++);
    if(n>1)p[++cnt]=n,t[cnt]=1;n=ln;//rep(i,1,cnt)printf("%lld %lld\n",p[i],t[i]);exit(0);
    #define check(l,x,y) if(!query((l)*len,len*(x)-len+1,len*(y)-len+1))break
    rfor(ll i=1,d,len;d=p[i],i<=cnt;i++)rfor(ll j=1;len=n/d,j<=t[i];d*=p[i],j++){
        if(j==1&&(d&1)){check(d/2,1,(d+3)/2);check(d/2,1,(d+1)/2);}else check(p[i]-1,1,p[i]);ans*=p[i];
    }ll ts=0;rep(i,1,ans)if(ans%i==0)ts++;while(cnt)p[cnt]=t[cnt]=0,cnt--;return ts;
}
int main(){n=readll(),m=readll();ll a1=calc(n,q1),a2=calc(m,q2);printf("! %lld\n",a1*a2),fflush(stdout);return 0;}