#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=998244353;typedef ll aN[N];aN head,next,to,q;ll cnt=0,s[666];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll dis[666][666],tot[666][666];
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void bfs(ll u,ll*dis,ll*cnt){
//printf("???\n");
    cnt[q[1]=u]=1;rfor(ll h=1,t=1,u;h<=t;)rfor(ll i=head[u=q[h++]];i;i=next[i]){
    if(!cnt[to[i]])q[++t]=to[i],dis[to[i]]=dis[u]+1,cnt[to[i]]=cnt[u];
    else if(dis[to[i]]==dis[u]+1)cnt[to[i]]+=cnt[u];}
}
int main(){
    ll n=readll(),m=readll(),u,v;rep(i,1,m)u=readll(),v=readll(),add(u,v),add(v,u);
    rep(i,1,n)bfs(i,dis[i],tot[i]);/*rep(i,1,n){rep(j,1,n)printf("%lld ",tot[i][j]);puts("");}*/rep(a,1,n){
        rep(b,1,n)if(tot[a][b]==1){
            memset(s,0,sizeof(ll)*(n+1));rep(u,1,n)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
            if(dis[a][u]==dis[a][v]+1&&dis[b][u]==dis[b][v]+1)s[u]++;
            ll sum=1;rep(u,1,n)sum=sum*(s[u]?:dis[a][u]+dis[b][u]==dis[a][b])%mod;printf("%lld ",sum);
        }else printf("0 ");puts("");
    }return 0;
}