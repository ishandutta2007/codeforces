#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
//bool p1;
typedef long long ll;const ll N=100007,inf=1e18,M=4407;typedef ll aN[N],aM[M];char is[1<<21],os[1<<21],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<20,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;typedef long double ld;const ld eps=1e-6;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aM a,b,c,m,k;
struct cmp{const ll*const t;cmp(ll*b):t(b){}int operator()(ll x,ll y){return t[x]<t[y];}};
aN next,head,to,w,f;ll cnt=1;void add_(ll u,ll v,ll c,ll h){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c,f[cnt]=h;}
void add(ll u,ll v,ll w,ll f){add_(u,v,w,f),add_(v,u,0,-f);}
int qmax(ll&a,ll b){return a<b?a=b,1:0;}int qmin(ll&a,ll b){return a>b?a=b,1:0;}aN cur,dis,in;int q[N*2];
int spfa(ll s,ll e,ll n){memcpy(cur,head,(n+1)<<3),memset(dis,0x3f,(n+1)<<3),memset(in,dis[q[1]=s]=0,(n+1)<<3);
rfor(ll h=1,t=1,u;in[/*fprintf(stderr,"%lld\n",h),*/q[h]]=0,h<=t;)rev(i,u=q[h++],v)w[i]&&qmin(dis[v],dis[u]+f[i])&&!in[v]&&++in[q[++t]=v];return dis[e]<inf;}
ll dfs(ll u,ll t,ll fl){if(u==t)return fl;in[u]=1;ll now=fl,q=0;rfor(ll i=cur[u],v;v=to[i],i&&now;i=cur[u]=next[cur[u]])
if(w[i]&&!in[v]&&dis[v]==dis[u]+f[i])q=dfs(v,t,std::min(now,w[i])),w[i]-=q,w[i^1]+=q,now-=q;in[u]=0;return fl-now;}
//bool p2;
int main(){//IO(H);//fprintf(stderr,"%.2fMiB\n",(&p2-&p1)/1048576.0);
    ll n=readll(),s=0,e=4*n+1;rep(i,1,2*n)a[i]=readll(),b[i]=readll(),c[i]=k[i]=i;b[0]=m[0]=-1;std::sort(c+1,c+2*n+1,cmp(b));
    ll ans=0;rfor(ll l=0,r=1e9+7,flag,t;t=(l+r)>>1,flag=1,l<=r||(ans=r+1,0);flag?r=t-1:l=t+1){
        ll lst=1,mx=0,s1=0,s2=0;rep(i,1,2*n){qmax(mx,(m[c[i]]=a[c[i]]*t+b[c[i]]));
        if(b[c[i]]!=b[c[i+1]]){rep(j,lst,i)if(c[j]<=n)m[c[j]]=mx;lst=i+1;}}std::sort(k+1,k+2*n+1,cmp(m));
        rep(i,1,2*n){(k[i]<=n?s1:s2)++;if(m[k[i]]!=m[k[i+1]]&&s1>s2){flag=0;break;}}
    }if(ans>1e9L)return puts("-1");printf("%lld ",ans);
    rep(i,1,n)add(s,i,1,0),add(i+3*n,e,1,0),add(i,i+2*n,inf,0),add(i+n,i+3*n,inf,0);const ll t=ans;ll y=e;
    rep(i,1,2*n){if(b[c[i]]!=b[c[i-1]]&&y++!=e)add(y,y-1,inf,0);add(c[i],y,inf,0),add(y,c[i],inf,1);}
    rep(i,1,2*n)m[i]=a[i]*t+b[i];std::sort(k+1,k+2*n+1,cmp(m));const ll g=y;
    rep(i,1,2*n){if(m[k[i]]!=m[k[i-1]]&&y++!=g)add(y,y-1,inf,0);add(k[i]+2*n,y,inf,0),add(y,k[i]+2*n,inf,1);}
    ll sum=0;while(spfa(s,e,n*8+1))sum+=dfs(s,e,inf)*dis[e];printf("%lld\n",sum);return 0;
}