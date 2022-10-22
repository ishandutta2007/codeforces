#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
typedef long long ll;typedef long double ld;const ll inf=0x3f3f3f3f3f3f3f3f,N=31111;
const ld pi=acos(-1);
ll readll(void){
    ll x=0,w=1;char ch=getchar();for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
    for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());return x*w;
}
inline int readchar(void){
    int ch=getchar();for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());return ch;
}
ll s[114514];
int main(void){
    ll k=readll(),t=0,c=97,d;while(t*(t-1)/2<=k)++t,s[t]=t*(t-1)/2;
    while(k){d=std::upper_bound(s+1,s+t+1,k)-s-1;rep(i,1,d)putchar(c);c++,k-=d*(d-1)/2;}putchar(c);
    return 0;
}