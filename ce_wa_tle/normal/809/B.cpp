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
ll getans(ll a,ll b){
    printf("1 %lld %lld\n",a,b),fflush(stdout);
    char x[114];
    scanf("%s",x);
    return*x!='N';
}
void submit(ll a,ll b){
    printf("2 %lld %lld\n",a,b),fflush(stdout);
}
int main(void){
//    IO(P1368);
    ll n=readll(),k=readll();
    ll w1=-1,w2=-1,w3=-1;
    rfor(ll l=1,r=n,mid;mid=(l+r)>>1,l>=r?w1=l,0:1;)
    if(getans(mid,mid+1))r=mid;else l=mid+1;
    rfor(ll l=1,r=w1-1,mid;mid=(l+r)>>1,l>=r?w2=l,0:1;)
    if(getans(mid,mid+1))r=mid;else l=mid+1;
    rfor(ll l=w1+1,r=n,mid;mid=(l+r)>>1,l>=r?w3=l,0:1;)
    if(getans(mid,mid+1))r=mid;else l=mid+1;
    submit(w1,w1^w2&&getans(w1,w2)&&getans(w2,w1)?w2:w3);
    return 0;
}