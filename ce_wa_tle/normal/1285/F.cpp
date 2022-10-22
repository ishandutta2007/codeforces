#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e6+9;typedef ll aN[N];
void qmax(ll&a,ll b){if(a<b)a=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,to,head,p,mu,c,t,st;ll cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
#define mj(x,y) rfor(ll i##x=head[y],x;x=to[i##x],i##x;i##x=next[i##x])
int main(){
    const ll s=readll(),N=1e5;rep(i,1,s)t[readll()]++;rep(i,1,N)rfor(ll j=i;j<=N;add(j,i),j+=i)if(t[j])t[i]=1;
    ll top=0,ans=0;rfor(ll i=2,j;i<=N;i++)for(p[i]||(mu[p[++top]=i]=-1),j=1;j<=top&&p[j]*i<=N;j++)
    {p[i*p[j]]=1,mu[i*p[j]]=-mu[i];if(i%p[j]==0){mu[i*p[j]]=0;break;}}top=0;mu[1]=1;
    per(i,N,1)if(t[i]){//printf("%lld\n",i);
        ll flag=0;mj(j,i)flag+=mu[j]*c[j]/*,printf("%lld %lld\n",j,flag)*/;for(;flag;ans=std::max(ans,i*st[top--]))
        mj(j,st[top])c[j]--,i%j||(flag-=mu[j]);mj(j,i)c[j]++;ans=std::max(ans,st[++top]=i);
//        rep(s,1,top)printf("%lld ",st[s]);puts("");
    }printf("%lld\n",ans);return 0;
}