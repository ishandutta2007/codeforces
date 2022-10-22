#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define log djskfanj
typedef long long ll;const ll N=2e5+7,inf=998244353;typedef ll aN[N];aN deep,next,to,head,log;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll min2(ll a,ll b){return (a?deep[a]:inf)<(b?deep[b]:inf)?a:b;}
ll min(ll a,ll b){return (a?:inf)<(b?:inf)?a:b;}ll max(ll a,ll b){return (a?:-inf)>(b?:-inf)?a:b;}
struct ds{aN st[23];ll n;ll(*const min)(ll,ll);ds(ll(*cmp)(ll,ll)):min(cmp){};
    ll operator[](ll b)const{return st[0][b];}ll&operator[](ll b){return st[0][b];}
    ll getans(ll l,ll r){if(l>r)return 0;ll lg=log[r-l+1];return min(st[lg][l],st[lg][r-(1<<lg)+1]);}
    void calc(){rep(i,1,log[n])rep(j,1,n-(1<<i)+1)st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);}
}s(min2),dn(min),dx(max);ll cnt=0,top=0;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){//printf("u=%lld\n",u); 
    deep[s[dn[u]=dx[u]=++top]=u]=deep[fa]+1;rfor(ll i=head[u],v;v=to[i],i;i=next[i])if(v^fa)dfs(v,u),s[++top]=u;
}int main(){
    ll n=readll(),m=readll();rep(i,2,n)add(readll(),i);rep(i,2,2*n)log[i]=log[i>>1]+1;dfs(1,0);dn.n=dx.n=n,s.n=top;
    dn.calc(),dx.calc(),s.calc();rep(i,1,m){ll l=readll(),r=readll(),sl=s[dn.getans(l,r)],sr=s[dx.getans(l,r)],
    dl=s.getans(min(dn.getans(l,sl-1),dn.getans(sl+1,r)),max(dx.getans(l,sl-1),dx.getans(sl+1,r))),
    dr=s.getans(min(dn.getans(l,sr-1),dn.getans(sr+1,r)),max(dx.getans(l,sr-1),dx.getans(sr+1,r)));
    if(min2(dl,dr)==dr)printf("%lld %lld\n",sl,deep[dl]-1);else printf("%lld %lld\n",sr,deep[dr]-1);}return 0;
}