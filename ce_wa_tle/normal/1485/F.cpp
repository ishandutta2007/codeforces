#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
#define reva(i,u,v,a)rfor(ll i=a.head[u],v;v=a.to[i],i;i=a.next[i])
typedef long long ll;const ll N=1e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline int qm(ll&a,ll b=mod){return a>b?a-=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
struct hash{static const ll m=9260817;ll k[m],v[m],r[m];ll t;mutable ll l,a;ll g(ll&b)const{if(l==(b=b>0?b:(~0ull>>1)+b))return a;ll n=(l=b)%m,x=0;for(;k[n]&&k[n]!=b;n=(n+2*x+++1)%m);return a=n;}
int count(ll b)const{return!!k[g(b)];}ll&operator[](ll b){ll n=g(b);return!k[n]?k[n]=b,v[r[++t]=n]=0:v[n];}ll operator[](ll b)const{ll n=g(b);return k[n]?v[n]:0;}void clear(){while(t)k[r[t--]]=0;}}t;
ll calc(){ll n=readll(),s=1,x=0,r=0;t.clear();t[0]=1;rep(i,1,n)qm(r=s+mod-t[x+=readll()]),qm(s+=r),qm(t[x]+=r);qm(s+=mod-r);return s;}int main(){IO();ll T=readll();while(T--)writell(calc(),10);return 0;}