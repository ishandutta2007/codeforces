#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,inf=1e18;typedef ll aN[N];aN dfn,sz,a,s;ll top=0,cnt=0;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct segment_tree{
    ll val[N<<2],add[N<<2];void pushup(ll u,ll l,ll r){if(l==r)return;val[u]=std::max(val[u<<1],val[u<<1|1]);}
    void pushdown(ll u,ll l,ll r){if(add[u]){if(l!=r)add[u<<1]+=add[u],add[u<<1|1]+=add[u];val[u]+=add[u],add[u]=0;}}
    void update(ll u,ll l,ll r,ll ql,ll qr,ll c){
        ll mid=(l+r)>>1;pushdown(u,l,r);if(ql<=l&&r<=qr){add[u]+=c,pushdown(u,l,r);return;}
        if(ql<=mid)update(u<<1,l,mid,ql,qr,c);else pushdown(u<<1,l,mid);
        if(qr>=mid+1)update(u<<1|1,mid+1,r,ql,qr,c);else pushdown(u<<1|1,mid+1,r);pushup(u,l,r);
    }
}tr;aN next,head,to;ll n,r;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){dfn[u]=++top,sz[u]=1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs(v,u),sz[u]+=sz[v];}
void add(ll u){tr.update(1,1,r,dfn[u],dfn[u]+sz[u]-1,1);}void del(ll u){tr.update(1,1,r,dfn[u],dfn[u],-inf);}
int main(){
    ll n=readll(),k=readll(),t=0;rep(i,1,n+1){a[i]=i==n+1?inf:readll();while(t&&a[i]>a[s[t]])add(i,s[t--]);s[++t]=i;}
    ::n=n,r=n+1;dfs(r,0);rep(i,1,n)add(i),i>k&&(del(i-k),0),i>=k&&printf("%lld ",tr.val[1]);return 0;
}