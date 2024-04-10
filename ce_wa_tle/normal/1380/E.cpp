#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=3116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN f,vis,size,next,head,to,real;ll cnt=0,flag=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define f(x...) fds(x)
ll f(ll u){return u^f[u]?f[u]=f(f[u]):u;}void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll merge(ll cs,ll u,ll v){
    if(size[f(to[head[u]])]>size[f(to[head[v]])])std::swap(u,v);
//    printf("mg %lld %lld %lld\n",cs,u,v);if(vis[u]||vis[v])puts("nmsl");vis[u]=1;
    ll sum=0,s=f(to[head[v]]),sv=v;rfor(ll i=head[u],v;v=to[i],i;i=next[i])sum+=(f(v+1)==s)+(f(v-1)==s),add(sv,v);
    ll t=f(to[head[u]]);size[s]+=size[t],f[t]=s,real[cs]=v;
    return sum;
}int main(){//IO(1380E);
    ll n=readll(),m=readll(),ans=n-1;rep(i,1,n)size[f[i]=i]=1;rep(i,1,n)add(readll(),i);
    rep(u,1,m){
        ll s=f(to[head[u]]);rfor(ll i=next[head[u]],v;v=to[i],i;i=next[i])ans-=(f(v-1)==s)+(f(v+1)==s),size[f[v]=s]++;
    }rep(i,1,m)real[i]=i;
    printf("%lld\n",ans);rep(i,1,m-1){ll u=readll(),v=readll();printf("%lld\n",ans-=merge(u,real[u],real[v]));}return 0;
}
//    ll n=readll(),m=readll(),ans=n-1;rep(i,1,n)size[f[i]=i]=1;rep(i,1,n)add(readll(),i);
//    rep(u,1,m){
//        ll s=f(to[head[u]]);rfor(ll i=next[head[u]],v;v=to[i],i;i=next[i])ans-=(f(v-1)==s)+(f(v+1)==s),size[f[v]=s]++;
//    }rep(i,1,m)real[i]=i;
//    printf("%lld\n",ans);rep(i,1,m-1){ll u=readll(),v=readll();printf("%lld\n",ans-=merge(u,real[u],real[v]));
//    rep(j,1,m)if(!vis[j]){printf("%lld:[",j);rfor(ll i=head[j];i;i=next[i])printf("%lld,",to[i]);putchar(']');}puts("");}return 0;
//}