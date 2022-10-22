#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef int ll;const ll N=55,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;char a[N];
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline int qm(ll&a,ll b=mod){return a>b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
const ll A=27,B=270,lA=A<<1|1,lB=B<<1|1,dlt=B+A*lB;struct ss{ll a[lA*lB];ss(){memset(a,0x3f,sizeof a);}ll*operator[](ll b){return a+dlt+b*lB;}const ll*operator[](ll b)const{return a+dlt+b*lB;}}f[N];
int main(){IO();ll n=mygets(a+2)+1;a[1]='0';f[0][0][0]=0;rep(i,1,n)a[i]^=48;ref(i,0,n)rep(j,-A,A)rep(k,-5*i,5*i)if(f[i][j][k]<mod)rep(l,-6,6)
{const ll e=k+l,t=j*10+a[i+1]+e;t>=-A&&t<=A&&e>=-B&&e<=B&&qm(f[i+1][t][e],f[i][j][k]+llabs(l)*(n-i));}ll ans=mod;rep(i,~(5*n),5*n+1)qm(ans,f[n][0][i]);writell(ans);return 0;}