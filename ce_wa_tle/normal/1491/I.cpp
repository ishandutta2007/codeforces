#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout)//,gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll cnt=1,j=1,n;aN w,id,s,fz,st;
#define print()void()//,({printf("%lld\n",cnt);rep(i,1,n)printf("%lld ",id[i]);pc(10);rep(i,1,n)printf("%d ",sr(i));pc(10);})
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll a,ll b){return a<0?a+b:a<b?a:a-b;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}aN v[3],&a=v[0],&b=v[1],&c=v[2];
static inline int sr(ll i){return~-i&&a[id[i]]<b[id[i-1]];}void calc(){print();rep(i,2,n)v[j][id[1]]<a[id[i]]?std::swap(id[1],id[i]),j=1:++j==3&&(writell(id[1]-1),writell(cnt+i-1,10),exit(0),0);cnt+=n-1;print();}
void work(ll k){print();if(k>n)exit(!myputs("-1 -1"));ll tw=0;rep(i,1,n)sr(i)||(w[++tw]=i,fz[tw]=id[i]);const ll s=k%tw;rep(i,1,tw)id[w[i]]=fz[qm(i-s-1,tw)+1];cnt+=k*(n-1);print();}
ll next(){rep(i,3,n)if(sr(i-1)&&c[id[i-2]]>a[id[i]])return 0;ll tw=0,ans=mod;rep(i,1,n)sr(i)||(w[++tw]=i);rep(i,1,tw)w[i+tw]=w[i]+n;w[tw<<2|1]=0;memcpy(id+n+1,id+1,n<<3);ll h=1,t=0,lst=-mod;rep(i,1,tw*2)
{while(h<=t&&b[id[w[st[t]]]]>b[id[w[i]]])t--;c[id[w[st[++t]=i]]]>a[id[w[i+1]]]&&(lst=i);if(w[i+1]>w[i]+1)for(ans=std::min(ans,i-lst);h<=t&&b[id[w[st[h]]]]<a[id[w[i]+1]];)ans=std::min(ans,i-st[h++]);}return ans;}
int main(){IO();n=readll();rep(i,1,n)a[i]=readll(),b[i]=readll(),c[i]=readll(),id[i]=i+1;id[n]=(id[1]=(a[1]<a[2])+1)^3;
while(sr(n)&&sr(2))calc();if(j==2)calc();if(sr(n)){ll t=id[1];cnt++,memmove(id+1,id+2,(n-1)<<3),id[n]=t,j=1;}print();while(1)work(next()),calc();return 0;}