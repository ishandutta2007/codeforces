#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=1e9+7;typedef ll aN[N];aN vis,f,d,head,next,to,c,p,u,v,sp,vsi;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
#define f(x...)fdsf(x)
ll f(ll u){return u^f[u]?f[u]=f(f[u]):u;}void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}ll s[777][777];
ll solve1(ll n,ll m){
    ll u=1,cnt=0;rep(i,1,n)if(vis[f[i]=i]=0,d[i]<d[u])u=i;vis[u]=1;rfor(ll i=head[u];i;i=next[i])vis[to[i]]=1;
    ll lst=0;rep(i,1,n)if(!vis[i])lst&&(f[i]=f(lst)),lst=i;else sp[++cnt]=i;sp[++cnt]=lst;
    rep(i,1,cnt){
        ll u=sp[i];
        rfor(ll i=head[u];i;vsi[to[i]]=1,i=next[i]);
        rep(i,1,cnt)if(!vsi[sp[i]])f[f(u)]=f(sp[i]);
        rfor(ll i=head[u];i;vsi[to[i]]=0,i=next[i]);
    }
    {ll u=0,v=0,ans=0;rep(i,1,m)if((u=f(::u[p[i]]))!=(v=f(::v[p[i]])))f[u]=v,ans+=c[p[i]];return ans;}
}
ll solve2(ll n,ll m){
//fprintf(stderr,"???");
    ll u=0,v=0,ans=0;rep(i,1,n)f[i]=i;rep(i,1,n)rep(j,i+1,n)if(!s[i][j]&&(u=f(i))!=(v=f(j)))f[u]=v;
    rep(i,1,m)if((u=f(::u[p[i]]))!=(v=f(::v[p[i]])))f[u]=v,ans+=c[p[i]];return ans;
}ll cmp(ll a,ll b){return c[a]<c[b];}
int main(){//IO(1508C);
    ll n=readll(),m=readll(),ans=inf,w=0;rep(i,1,m)d[u[i]=readll()]++,d[v[i]=readll()]++,add(u[i],v[i]),add(v[i],u[i]),
    w^=c[p[i]=i]=readll();c[p[m+1]=m+1]=w,std::sort(p+1,p+m+(n*(n-1)/2-m<n)+1,cmp);if(n*(n-1)/2-m>=n)ans=solve1(n,m);
    else{rep(i,1,m)s[u[i]][v[i]]=s[v[i]][u[i]]=1;rep(i,1,n)rep(j,i+1,n)if(!s[i][j])s[i][j]=1,
    u[m+1]=i,v[m+1]=j,ans=std::min(ans,solve2(n,m+1)),s[i][j]=0;}printf("%lld\n",ans);return 0;
}
/*
4 2
1 2 1
1 3 2
*/