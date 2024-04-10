#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=2e5+777,B=256,mod=998244353;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN a;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}int qm(ll&a,ll b){return a<b?a=b,1:0;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll query(ll a,ll l,ll r){pc('?'),pc(32),writell(1),writell(r-l+1,10),writell(a,10);rep(i,l,r)writell(i," \n"[i==r]);fout();return fflush(stdout),readll();}
void calc(){ll n=readll();ll f=0,cnt=0;rep(i,1,n)a[i]=0;rep(i,2,n)if(query(i,1,i-1)){a[f=i]=1;break;}rep(i,f+1,n)a[i]=query(f,i,i);ll l=1,r=f-1,ans=0;while(l<=r){ll m=(l+r)>>1;if(query(f,1,m))r=m-1,ans=m;else l=m+1;}
a[ans]=1;pc('!'),pc(32);rep(i,1,n)if(!a[i])cnt++;writell(cnt);rep(i,1,n)if(!a[i])writell(i);pc(10);fout(),fflush(stdout);}int main(){pc=fpc;ll T=readll();while(T --> 0)calc();}