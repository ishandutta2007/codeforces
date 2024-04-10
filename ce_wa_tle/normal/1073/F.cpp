#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=4e5+7,mod=998244353;typedef ll aN[N];aN d,next,to,head,deep,l;ll cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct node{ll u,x,y;operator ll()const{return x&&y&&u!=x?deep[u]*mod+deep[x]+deep[y]:0;}};
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
node dfs(ll u,ll fa){//printf("%lld %lld\n",u,fa);
    node now=(node){0,0,0};l[u]=u;deep[u]=deep[fa]+1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa){node add=dfs(v,u);
    now=std::max(now,(node){u,l[u],l[v]});if(deep[l[v]]>deep[l[u]])l[u]=l[v];now=std::max(now,add);};return now;
}int main(){
    ll n=readll(),u,v,r=0;rep(i,2,n)d[u=readll()]++,d[v=readll()]++,add(u,v),add(v,u);rep(i,1,n)if(d[i]>=3){r=i;break;}
    node u1=dfs(r,0),u2=dfs(u1.u,0);printf("%lld %lld\n%lld %lld\n",u1.x,u2.x,u1.y,u2.y);return 0;
}