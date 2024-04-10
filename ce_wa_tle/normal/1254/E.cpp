#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+5,mod=1e9+7;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,to,deep,f,fa,l,fst,lst,pre,nxt,d,jc;ll cnt=1;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa,ll c){deep[u]=deep[::fa[u]=fa]+1,l[u]=c;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs(to[i],u,i);}
#define f(x...)dfsafjnfds(x)
ll f(ll u){return u^f[u]?f[u]=f(f[u]):u;}ll flag=0;ll merge(ll u,ll v){return(u=f(u))^(v=f(v))?f[u]=v,0:1;}
void link(ll u,ll v){
    if(u==v)flag=1;if(flag)return;static aN s1,s2;ll t1=0,t2=0,lu=u,lv=v;
    while(deep[u]>deep[v])d[u]--,s1[++t1]=l[u],u=fa[u];while(deep[u]<deep[v])d[v]--,s2[++t2]=l[v]^1,v=fa[v];
    while(u!=v)d[u]--,d[v]--,s1[++t1]=l[u],s2[++t2]=l[v]^1,u=fa[u],v=fa[v];d[u]--;while(t2)s1[++t1]=s2[t2--];
    ll now=s1[1],lp=0;if(pre[now]||fst[lu])return(void)(flag=1);pre[fst[lu]=now]=-1;
    rep(i,2,t1){lp=now^1,now=s1[i];if(pre[now]||nxt[lp]||merge(now,lp))return(void)(flag=1);nxt[pre[now]=lp]=now;}
    lp=now^1;if(nxt[lp]||lst[lv])return(void)(flag=1);nxt[lst[lv]=lp]=-1;
}
int main(){
    ll n=readll(),u,v;rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u),d[u]++,d[v]++;dfs(1,0,0);rep(i,1,cnt)f[i]=i;
    rep(i,1,n)if((u=readll()))link(u,i);if(flag)return puts("0"),0;jc[0]=1;rep(i,1,n)jc[i]=jc[i-1]*i%mod;ll sum=1;
    rep(i,1,n)sum=sum*(fst[i]&&f(fst[i])==f(lst[i])?d[i]==-1:jc[d[i]])%mod;printf("%lld\n",sum);return 0;
}