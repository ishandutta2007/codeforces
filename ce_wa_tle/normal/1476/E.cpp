#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ld eps=1e-6,inf=1e9;const ll N=1e5+5,mod=1e9+7;typedef ll aN[N],aN16[N*16];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct trie{static ll cnt;ll v[28];}tr[N*4];ll trie::cnt=1;
ll cnt=0;aN16 next,to,id;aN head,q,d;char s[6];
void add(ll u,ll v){next[++cnt]=head[u],d[to[head[u]=cnt]=v]++;}
int main(){
    ll n=readll(),m=readll(),k=readll();
    rfor(ll i=1,r,u;u=1,i<=n;id[trie::cnt]=i++)rep(j,1,k)r=readchar()-94,u=tr[u].v[r]?:tr[u].v[r]=++trie::cnt;
    rep(i,1,m){
        rep(j,1,k)s[j]=readchar()-94;ll d=readll(),flag=0;rfor(ll t=0,u;!(t>>k);(u=id[u])&&(u^d?add(d,u),0:(flag=1)),t++)
        rep(j,u=1,k)u=tr[u].v[t>>(j-1)&1?s[j]:1];if(!flag)return puts("NO"),0;
    }
    ll h=1,t=0;rep(i,1,n)if(!d[i])q[++t]=i;rfor(ll u;h<=t;)rfor(ll i=head[u=q[h++]];i;i=next[i])--d[to[i]]||(q[++t]=to[i]);
    if(t!=n)return puts("NO"),0;puts("YES");rep(i,1,n)printf("%lld ",q[i]);
	return 0;
}