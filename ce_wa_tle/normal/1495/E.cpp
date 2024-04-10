#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=5e6+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN a,t,f;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
int main(){IO();ll n=readll(),m=readll(),lst=1,p,k,b,w,s2=0,s1=0;rep(i,1,m){p=readll(),k=readll(),b=readll(),w=readll();rep(i,lst,p)t[i]=b%2+1,
(t[i]==1?s1:s2)+=f[i]=a[i]=(b=(b*w+233)%mod)%k+1,b=(b*w+233)%mod;lst=p+1;}ll g=(s2<s1)+1,e=t[1]!=g,s=1,x=0;//printf("%lld %lld %lld %lld\n",s1,s2,g,e);
rep(j,1,2)rep(i,1,n)g==t[i]?e+=f[i],f[i]=0:(x=std::min(e,f[i]),e-=x,f[i]-=x);rep(i,1,n)s=(((a[i]-f[i])^i*i)%mod*s+s)%mod;writell(s);return 0;}