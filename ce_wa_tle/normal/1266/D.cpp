#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(fout)
typedef long long ll;const ll N=3e6+7,inf=1e18;typedef ll aN[N];char is[1<<22],os[1<<24],*i1=is,*i2=is,*o1=os;aN d,z,f;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}ll tz,tf;aN ot;
void fout(){fwrite(os,o1-os,1,stdout),o1=os;}int(*gc)()=getchar,(*pc)(int)=putchar;typedef unsigned long long ull;
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}int wt[114];
int myputs(const char*s){const char*t=s;while(*t)pc(*t++);pc(10);return t-s;}int qm(ll&a,ll b){return a>b?a=b,1:0;}
void writell(ll u,int c=32){ll t=0;for(ull n=u<0?pc(45),0uLL-u:u;n||!t;wt[++t]=n%10^48,n/=10);for(;t;pc(wt[t--]));c&&pc(c);}
int main(){
    ll n=readll(),m=readll(),u,v,c,cnt=0;rep(i,1,m)u=readll(),v=readll(),c=readll(),d[u]-=c,d[v]+=c;
    rep(i,1,n)if(d[i])(d[i]>0?z[++tz]:f[++tf])=i;
    while(tz&&tf)ot[++cnt]=f[tf],ot[++cnt]=z[tz],ot[++cnt]=c=std::min(d[z[tz]],-d[f[tf]]),
    (d[z[tz]]-=c)||--tz,(d[f[tf]]+=c)||--tf;writell(cnt/3,'\n');rep(i,1,cnt)writell(ot[i],"\n  "[i%3]);return 0;
}