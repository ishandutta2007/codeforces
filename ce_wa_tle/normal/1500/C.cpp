#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=2.5e6+7,M=2222,mod=1e9+9;typedef ll aN[N],aM[M];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}aM a[M],q,cnt,vis,nxt,tl;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}int qm(ll&a,ll b){return a>b?a=b,1:0;}
int mygets(char*s,char c=0){char*t=s;while((*t++=gc())>31);*(t-1)>0&&c&&(*(t++-1)=c);*--t=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
struct hash{const static ll m=1e6+7;ll v[m],k[m];ll g(ll b)const{ll n=b%m,x=0;while(k[n]&&k[n]!=b)n=(n+2*x+++1)%m;return n;};int count(ll b)const{return!!k[g(b)];}
ll operator[](ll b)const{ll n=g(b);return k[n]?v[n]:0;}ll&operator[](ll b){ll n=g(b);return!k[n]?k[n]=b,v[n]=0:v[n];}}t;void getnxt(ll&a){a=nxt[a];}
aN next,head,to;ll tt;void add(ll u,ll v){next[++tt]=head[u],to[head[u]=tt]=v;}
int main(){
    ll n=readll(),m=readll();rep(i,1,n){ll x=0;rep(j,1,m)x=(x<<12|readll())%mod;t.count(x)?nxt[tl[x=t[x]]]=i,tl[x]=i:tl[i]=t[x]=i;}
    rep(i,1,n){ll x=0;rep(j,1,m)x=(x<<12|(a[i][j]=readll()))%mod;(a[i][m+1]=t[x])?getnxt(t[x]):exit(!myputs("-1"));}
    ll h=1,t=0;rep(j,1,m+1)rep(i,2,n||!(cnt[j]||(q[++t]=j)))if(a[i][j]>a[i-1][j])add(j+n,i);else if(a[i][j]<a[i-1][j])add(i,j+n),cnt[j]++;
    while(h<=t){ll u=q[h++];rev(i,u+n,v)if(!vis[v]){vis[v]=1;rev(j,v,w)if(!--cnt[w-n])q[++t]=w-n;}}
    if(t!=m+1)myputs("-1");else{ll t=0;while(q[t+1]!=m+1)t++;writell(t,10);while(t)writell(q[t--]);};return 0;
}