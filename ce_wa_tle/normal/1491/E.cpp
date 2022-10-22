#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=4e5+777,B=256,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN f;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll a,b,s1,s2,cnt=1;aN next,head,to,sz,vis;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
void dfs(ll u,ll fa,ll id){sz[u]=1;rev(i,u,v)if(v^fa&&!vis[i>>1])dfs(v,u,i>>1),sz[u]+=sz[v];if((sz[u]==a||sz[u]==b)&&!s1)s1=u,vis[id]=1;}
int check(ll r,ll n){if(n<=3)return 1;s1=s2=0,a=n*0.6180339887+0.5,b=n-a;dfs(r,0,0);if(!s1)return 0;ll z1=sz[s1],zr=n-z1;return check(s1,z1)&&check(r,zr);}
int main(){IO();ll n=readll(),u,v;rfor(ll i=1;i<=n*2&&i!=n;i=i*1.6180339887+0.5)if(i>n)return!myputs("NO");rep(i,2,n)u=readll(),v=readll(),add(u,v),add(v,u);myputs(check(1,n)?"YES":"NO");return 0;}