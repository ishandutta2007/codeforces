#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;typedef long double ld;const ll N=2e6+9,mod=998244353;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN next,head,to,lst,vis,st;ll top=0,cnt=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll dfs(ll u){
    if(lst[u])return lst[u];if(vis[u])return 0;st[lst[u]=++top]=u;vis[u]=1;
    rfor(ll i=head[u],v,s;v=to[i],i;i=next[i])if((s=dfs(v)))return s;return lst[u]=0;
}
int solve(int cases){
    ll n=readll(),w=0;rep(i,1,n)head[i]=lst[i]=vis[i]=0;(void)cases;
    rep(i,1,n)add(i,i-readll());rep(i,1,n)if(!vis[i])if((w=dfs(i)))break;
    printf("%lld\n",top-w+1);rep(i,w,top)printf("%lld ",st[i]);puts("");return top=cnt=0;
}int main(){ll T=readll(),cnt=0;while(T --> 0)solve(++cnt);return 0;}
/*
1<=si<=n
ai=i-si
sum s_i=sum i
*/