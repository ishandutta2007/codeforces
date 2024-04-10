#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;const ll N=5e3+7,mod=1e9+7;typedef ll aN[N];char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=getchar());for(;c>=48&&c<=57;x=x*10+(c&15),c=getchar());return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}aN t;
ll calc(){ll n=readll(),m=readll(),x=0,s=0;rep(i,1,n)t[readll()]=i;rep(i,1,m)s+=qmax(x,t[readll()])?(x-i)*2+1:1;return s;}
int main(){ll T=readll();while(T --> 0)printf("%lld\n",calc());return 0;}