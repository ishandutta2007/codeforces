#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=1e6+9,inf=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN head,next,c,e,in,u,v,l,f,to,s,dp_v,dp_e,vis;ll cnt=0,top;
void add(ll u,ll v,ll w){next[++cnt]=head[u],to[head[u]=cnt]=v,c[cnt]=w;}
void solve(){
    ll min=inf,max=0,mini=0,maxi=0;rep(i,1,top)if(e[i]<min)min=e[mini=i];else if(e[i]>max)max=e[maxi=i];s[min]=max;
    rfor(ll x=mini,y;y=x==top?1:x+1,x!=maxi;x=y)if(e[x]>e[y])s[min]=0;
    rfor(ll x=maxi,y;y=x==top?1:x+1,x!=mini;x=y)if(e[x]<e[y])s[min]=0;
}
void dfs(ll u,ll fa,ll w){
    rfor(ll i=head[f[u]=fa,l[u]=w,vis[u]=in[u]=1,u],v;v=to[i],i;i=next[i])if(!vis[v])dfs(v,u,i);
    else if(v^fa&&in[v]){e[top=1]=c[i];rfor(ll x=u;x!=v;x=f[x])e[++top]=c[l[x]];solve();}in[u]=0;
}
int main(){
    ll n=readll(),m=readll();rep(i,1,m)u[i]=readll(),v[i]=readll(),add(u[i],v[i],i),add(v[i],u[i],i);
    dfs(1,0,0);rep(i,1,n)dp_v[i]=1;per(i,m,1)dp_v[u[i]]=dp_v[v[i]]=dp_e[i]=dp_v[u[i]]+dp_v[v[i]]-dp_e[s[i]];
    rep(i,1,n)printf("%lld ",dp_v[i]-1);puts("");return 0;
}