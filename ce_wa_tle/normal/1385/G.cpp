#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1116333,inf=1e9,mod=1e9+7;typedef ll aN[N];aN next,to,head,vis,w,s,t;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
void add_(ll u,ll v,ll c){/*printf("%lld %lld %lld\n",u,v,c),*/next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
void add(ll u,ll v,ll w){add_(u,v,w),add_(v,u,w);}ll tot[2];
int dfs(ll u){
    tot[vis[u]]++;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(!~vis[v])
    if(vis[v]=w[i]^vis[u],!dfs(v))return 0;else(void)0;else if(vis[v]^w[i]^vis[u])return 0;return 1;
}
void swap(ll u){vis[u]^=1;rfor(ll i=head[u];i;i=next[i])if(vis[to[i]]^w[i]^vis[u])swap(to[i]);}
int calc(ll cases){
    ll n=readll(),x,sz=sizeof(ll)*2*(n+1);memset(head,0,sz),memset(vis,-1,sz),memset(s,0,sz),memset(t,0,sz);
    ll flag=0;ref(i,0,2*n)x=readll()-1,t[x]>=2?flag=1:s[x+t[x]++*n]=i;if(flag)return puts("-1"),-1;//exit(0);
    ref(i,0,n)add(s[i]%n,s[i+n]%n,s[i]/n==s[i+n]/n);(void)cases;
    ref(i,0,n)if(!~vis[i]){if(tot[0]=tot[1]=vis[i]=0,!dfs(i))return puts("-1"),-1;else if(tot[0]<tot[1])swap(i);}
    ll cnt=0;ref(i,0,n)cnt+=vis[i];printf("%lld\n",cnt);ref(i,0,n)if(vis[i])printf("%lld ",i+1);puts("");return cnt;
}
int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}
/*
6
5
5 3 5 1 4
1 2 3 2 4
4
1 2 3 4
2 3 1 4
3
1 2 1
3 3 2
4
1 2 2 1
3 4 3 4
4
4 3 1 4
3 2 2 1
3
1 1 2
3 2 2

*/