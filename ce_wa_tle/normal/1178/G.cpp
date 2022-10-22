#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=2e5+7,mod=1e18;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
aN next,head,to,dfn,sz,a,b,f,g;ll cnt=0,top=0;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa){g[dfn[u]=++top]=u,sz[u]=1;rev(i,u,v)if(v^fa)dfs(v,u),sz[u]+=sz[v];}
ll min(ll a,ll b,ll c){return a<b?a<c?a:c:b<c?b:c;}ll calc(ll a,ll b){return!a&&b?1:a*b>0?a/b+1:mod;}
struct nd{ll a,b,t;};int gt(ll a,ll b){return a>b;}int ls(ll a,ll b){return a<b;}
struct sgt{int(*const cp)(ll,ll);ll cmp(ll a,ll b)const{return cp(a,b)?a:b;}nd v[N<<2];ll t[N<<2];
    nd mg(const nd&a,const nd&b)const{nd r=cp(a.a,b.a)?a:b;r.t=min(a.t,b.t,calc(a.a-b.a,b.b-a.b));return r;}
    void pd(ll u,ll l,ll r){if(t[u])v[u].a+=t[u]*v[u].b,v[u].t-=t[u],l<r&&(t[u<<1]+=t[u],t[u<<1|1]+=t[u]),t[u]=0;}
    void pu(ll u,ll l,ll r){if(l<r)v[u]=mg(v[u<<1],v[u<<1|1]);}sgt(int(*s)(ll,ll)):cp(s){}
    void bd(ll u,ll l,ll r){ll m=(l+r)>>1;if(l==r)v[u].a=a[g[l]]*(v[u].b=b[g[l]]),v[u].t=mod;else bd(u<<1,l,m),bd(u<<1|1,m+1,r),pu(u,l,r);}
    void up(ll u,ll l,ll r,ll ql,ll qr,ll c){ll m=(l+r)>>1;pd(u,l,r);if(ql<=l&&r<=qr&&c<v[u].t)return t[u]=c,pd(u,l,r);
    m>=ql?up(u<<1,l,m,ql,qr,c):pd(u<<1,l,m),m+1<=qr?up(u<<1|1,m+1,r,ql,qr,c):pd(u<<1|1,m+1,r);pu(u,l,r);}
    ll qu(ll u,ll l,ll r,ll ql,ll qr){ll m=(l+r)>>1;pd(u,l,r);if(ql<=l&&r<=qr)return v[u].a;
    return m<ql?qu(u<<1|1,m+1,r,ql,qr):m+1>qr?qu(u<<1,l,m,ql,qr):cmp(qu(u<<1,l,m,ql,qr),qu(u<<1|1,m+1,r,ql,qr));}
}t1(gt),t2(ls);
int main(){//IO(G);
    ll n=readll(),q=readll(),v,x,l,r;rep(i,2,n)add(f[i]=readll(),i);rep(i,1,n)a[i]=readll()+a[f[i]];
    rep(i,1,n)b[i]=readll()+b[f[i]];rep(i,1,n)b[i]=llabs(b[i]);dfs(1,0),t1.bd(1,1,n),t2.bd(1,1,n);
    rep(i,1,q)readll()==1?l=dfn[v=readll()],r=l+sz[v]-1,t1.up(1,1,n,l,r,x=readll()),t2.up(1,1,n,l,r,x),0:
    (l=dfn[v=readll()],r=l+sz[v]-1,printf("%lld\n",std::max(t1.qu(1,1,n,l,r),-t2.qu(1,1,n,l,r))));return 0;
}