#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;typedef int ll;const ll N=2e6+77,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;char s_[N],*s[N];aN id,sum,st,len,fv;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll a,ll b){return a<0?a+b:a<b?a:a-b;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll son[27][N/2];aN f,next,to,head,v,sz,q,dfn;ll tot=1,cnt,top;ll ins(char*s){ll now=1;rfor(ll i=0;ll c=s[i++];)now=son[c&31][now]?:son[c&31][now]=++tot;return now;}
struct bit{ll n;aN f;void set(ll n_){n=n_;}void update(ll u,ll c){while(u)f[u]+=c,u&=~-u;}ll query(ll u){ll res=1;while(u<=n)res+=f[u],u+=u&-u;return res;}}t;
void add(ll u,ll v){next[++cnt]=head[u],to[head[u]=cnt]=v;}void dfs(ll u,ll fa){dfn[u]=++top,sz[u]++,v[u]=v[u]?:v[fa];rev(i,u,v)dfs(v,u),sz[u]+=sz[v];}bool p2;
int main(){IO();ll n=readll(),ans=0;s[1]=s_;rep(i,1,n)s[i+1]=s[i]+(len[i]=mygets(s[i]))+1,v[fv[i]=ins(s[i])]=i;rep(i,1,26)son[i][0]=1;rfor(ll h=1,t=q[1]=1,v;ll u=q[h++];)rep(i,1,26)((v=son[i][u])?f[q[++t]=v]:son[i][u])=son[i][f[u]];
rep(i,2,tot)add(f[i],i);t.set(tot),dfs(1,0);rep(i,1,n){ll now=1,ts=0;rfor(ll j=0;(id[j]=(now=son[s[i][j]&31][now],v[now]==i?now=f[now]:now));t.update(dfn[now],1),st[++ts]=j,j++)while(ts&&st[ts]-len[v[id[st[ts]]]]>=j-len[v[now]])ts--;
rep(i,1,ts)if(ll c=v[id[st[i]]])(sum[c]?--sum[c]:sum[c]=t.query(dfn[fv[c]])-t.query(dfn[fv[c]]+sz[fv[c]])-1)||++ans;ref(j,0,len[i])sum[v[id[j]]]=0,t.update(dfn[id[j]],-1);}writell(ans);return 0;}
//rep(i,1,tot)rep(j,1,26)if(i<son[j][i])printf("%lld %lld %c\n",i,son[j][i],96|(int)j);rep(i,1,tot){printf("%lld %lld\n",i,f[i]);}
/*
3
aba
ab
a
*/