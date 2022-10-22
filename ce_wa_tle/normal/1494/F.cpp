#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=4e5+7,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll now,ts;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
aN next,head,to,d,vis,in,flag,h,st;ll cnt=1;void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}
ll dfs(ll u,ll now){if(vis[u]==now)return 0;vis[u]=now;ll s=1;rev(i,u,v)if(!flag[i>>1])s+=dfs(v,now);return s;}int check(ll n){ll s=0;++now;rep(i,1,n)if(dfs(i,now)>1)s++;return s<=1;}
void dfs(ll u){rfor(ll i=h[u];i&&(h[u]=next[h[u]],1);i=h[u])if(!flag[i>>1])flag[i>>1]=2,dfs(to[i]),st[++ts]=to[i];}
void getans(ll u){memcpy(h,head,sizeof h);dfs(u);st[++ts]=u,st[++ts]=-1;rev(i,u,v)if(flag[i>>1]==1)st[++ts]=v,st[++ts]=u;writell(ts,10);rep(i,1,ts)writell(st[i]);exit(0);};
int main(){IO();ll n=readll(),m=readll(),u,v,s=0;rep(i,1,m)u=readll(),v=readll(),add(u,v),add(v,u),d[u]++,d[v]++;rep(i,1,n)s+=d[i]&1;if(!check(n))return!myputs("0");
if(s==0||s==2){ll u=1;rep(i,1,n)if(d[i]&1)u=i;getans(u);}rep(u,1,n){ll g=d[u]&1;rev(i,u,v)g+=d[v]&1;if(g==s-1){rev(i,u,v)if(d[v]&1)flag[i>>1]=1;if(check(n))getans(u);rev(i,u,v)if(d[v]&1)flag[i>>1]=0;}
if(s==g){rev(i,u,v)if(d[v]&1)flag[i>>1]=1;dfs(u,++now);ll s=0;rev(i,u,v)if(flag[i>>1]&&dfs(v,now)>1&&flag[i>>1]--&&++s==2)break;if(s<=1)getans(u);rev(i,u,v)if(d[v]&1)flag[i>>1]=0;}}myputs("0");return 0;}