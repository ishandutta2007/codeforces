#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define red(i,f)rfor(ll i=f;i;i>>=1)
#define IO(x...)*#x&&freopen(#x".in","r",stdin)&&freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
bool p1;typedef long long ll;const ll N=2e6+77,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;ll f[66][66];ll flag=0;ll cnt=0;
int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}int fpc(int c){return*o1++=c;}typedef long double ld;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s,int c=10){const char*t=s;while(*t)pc(*t++);c&&pc(c);return t-s;}static inline ll qm(ll a,ll b){return a<0?a+b:a<b?a:a-b;}
int mygets(char*s,int c=0){char*t=s;while((*t++=gc())>31);*(t[-1]>0&&c?t[-1]=c,t:--t)=0;return t-s;}
void writell(ll u,int c=32){ll t=0;rfor(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
ll query(ll u){if(u>1e14)return 0;pc(63),pc(32),writell(u,10),fout(),fflush(stdout);if(flag)return printf("%lld\n",++cnt),u<=flag;static char s[N];mygets(s);assert(s[1]!='i');return s[0]=='L';}void calc(){ll l=1,r=0;while(query(l))l*=2;r=l-1,l/=2;rep(i,1,3)query(l);
r>1e14&&(r=1e14);ll x=0,y=0;while(f[x][0]<r-l+1)x++;while(l<r){if(!y)x--,y++,query(l);assert(x>0);ll mid=std::min(r,l+f[--x][y-1]);if(query(mid))y++,l=mid;else y--,r=mid-1;};pc(33),pc(32),writell(l,10),fout(),fflush(stdout);}
int main(){/*IO();*/pc=fpc,atexit(fout);rep(j,0,60)f[0][j]=1;rep(i,1,60){rep(j,1,60)f[i][j]=f[i-1][j+1]+f[i-1][j-1];f[i][0]=f[i-1][1];}ll T=readll();while(T --> 0)calc();return 0;}