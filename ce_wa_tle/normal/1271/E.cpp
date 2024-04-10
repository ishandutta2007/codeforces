#include<bits/stdc++.h>
#define rfor(x...)for(register x)
#define rep(i,l,r)rfor(ll i=l;i<=r;i++)
#define per(i,l,r)rfor(ll i=l;i>=r;i--)
#define ref(i,l,r)rfor(ll i=l;i<r;i++)
#define rev(i,u,v)rfor(ll i=head[u],v;v=to[i],i;i=next[i])
#define rej(i,s)rfor(ll i=s;i;i=(i-1)&s)
#define IO(x...)freopen(#x".in","r",stdin),freopen(#x".out","w",stdout),gc=fgc,pc=fpc,atexit(flush)
typedef long long ll;char is[1<<22],os[1<<22],*i1=is,*i2=is,*o1=os;
int fpc(int c){return*o1++=c;}int fgc(){return i1==i2&&is==(i2=is+fread(i1=is,1,1<<21,stdin))?-1:*i1++;}
void flush(){fwrite(os,o1-os,1,stdout);}int(*gc)()=getchar,(*pc)(int)=putchar;int qmax(ll&a,ll b){return a<b?a=b,1:0;}
ll readll(){ll x=0,w=1;int c=gc();for(;c<48||c>57;c=gc())c-45||(w=-w);for(;c>47&&c<58;c=gc())x=x*10+c-48;return x*w;}
int readchar(int l=48,int r=122){if(l>r)std::swap(l,r);int c=gc();for(;c<l||c>r;c=gc());return c;}
ll check(ll n,ll x){if(x>n)return 0;ll s=63^__builtin_clzll(n/x);return (2ll<<s)-1-std::max(0ll,((x+1)<<s)-1-n)+(x&1?0:check(n,x+1));}
int main(){ll n=readll(),k=readll(),x=0;per(i,60,0)check(n,x|1ll<<i)>=k&&(x|=1ll<<i);printf("%lld\n",x);return 0;}
/*
i is even

i is odd
2^{log(n/i)+1}-1-std::max(0ll,2^{log(n/i)}*i-n)>=k

*/