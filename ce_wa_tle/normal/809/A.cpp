#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
typedef long long ll;typedef long double ld;typedef long long ull;
const ll inf=0x3f3f3f3f3f3f3f3f;
using std::max;
using std::min;
inline ll readll(void){
    ll x=0,w=1;
    char ch=getchar();
    for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
    for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
    return x*w;
}
inline void writell(ll x,int c='\0'){
    static ll s[112];ll*n=s;
    while(x||n==s)*++n=x%10,x/=10;
    while(n!=s)putchar(*n--^48);
    if(c)putchar(c);
}
inline ll iabs(ll x){
    return max(x,-x);
}
inline int readchar(void){
    int ch=getchar();
    for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
    return ch;
}
const ll mod=1e9+7;
ll a[1145141];
int main(void){
//    IO(P1368);
    ll n=readll(),sum=0;
    rep(i,1,n)a[i]=readll();std::sort(a+1,a+n+1);
    ll now=1;
    rep(i,1,n)sum=(sum+a[i]*now)%mod,now=now*2%mod;
    now=1;
    per(i,n,1)sum=(sum-a[i]*now)%mod,now=now*2%mod;
    printf("%lld\n",(sum%mod+mod)%mod);
    return 0;
}