#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
bool p1;
typedef long long ll;const ll N=1e6+9,inf=1e9+7;typedef ll aN[N];aN to,head,next,id,u,v,vis,in;ll cnt=0,top=0;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
struct hs_{
    static const ll mod=5926081;ll k1[mod],k2[mod],val[mod];ll n;hs_():n(0){} 
    ll operator()(ll b1,ll b2){ll g=gcd(b1,b2);b1/=g,b2/=g;ll c=(b1%mod*1134+b2)%mod,x=0;
    while(val[c]&&(k1[c]!=b1||k2[c]!=b2))c=(c+2*x+++1)%mod;return!val[c]?k1[c]=b1,k2[c]=b2,val[c]=++n:val[c];}
}hs;void add(ll u,ll v,ll i){/*printf("%lld %lld %lld\n",u,v,i);*/next[++cnt]=head[u],to[head[u]=cnt]=v,id[cnt]=i;}
void res(ll a,ll b){u[++top]=id[a],v[top]=id[b];}bool p2;
ll dfs(ll u,ll w){
    if(vis[u])return 0;in[u]=vis[u]=1;ll f=0;rfor(ll i=head[u];i;i=next[i])
    if(!in[to[i]]&&!dfs(to[i],i))f?res(f,i),f=0:f=i;if(w&&f)res(w,f),w=f=0;in[u]=0;return!w;
}int main(){fprintf(stderr,"%.2lfMiB\n",(&p2-&p1)/1048576.0); 
    ll m=rd,a,b,c,d,s,t;rep(i,1,m)a=rd,b=rd,c=rd,d=rd,s=hs((a+b)*d,b*c),t=hs(a*d,b*(c+d)),add(s,t,i),add(t,s,i);
    ll n=hs.n;rep(i,1,n)if(!vis[i])dfs(i,0);printf("%lld\n",top);rep(i,1,top)printf("%lld %lld\n",u[i],v[i]);return 0;
}
//((a/b)+1)/(c/d)=((a+b)d)/bc
//(a/b)/((c/d)+1)=ad/(b(c+d))