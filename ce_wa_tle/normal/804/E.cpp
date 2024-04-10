#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;typedef long double ld;
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
typedef struct sw{ll a,b;}aN[];
aN kn={1,2,3,4,1,4,2,3,1,3,2,4},k2={1,0,1,2,2,0,3,0,3,4,4,0,1,4,2,3,1,3,2,4},
//kw={1,5,2,6,1,6,2,5,1,7,2,8,1,8,2,7,3,5,4,6,3,6,4,5,3,7,4,8,3,8,4,7};
  kw={1,1,2,2,1,2,2,1,1,3,2,4,1,4,2,3,3,1,4,2,3,2,4,1,3,3,4,4,3,4,4,3};
//1 2 3 4
//2 1 3 4
//2 1 4 3
//3 1 4 2
//3 4 1 2
//1 4 3 2
//1 2 3 4
//1 2 3 4 5 6 7 8
//2 1 3 4 6 5 7 8
//1 2 3 4 6 5 8 7
//1 2 4 3 5 6 8 7
//1 2 3 4 5 6 7 8
int main(void){
//    IO(CF804E);
    ll n=readll();
    if((n&3)>1)return puts("NO"),0;
    puts("YES");//ll p=n%4?n--:0;
    ref(s,0,n>>2)if(n&3)ref(i,0,10)printf("%lld %lld\n",k2[i].a?s*4+k2[i].a:n,k2[i].b?s*4+k2[i].b:n);
        else ref(i,0,6)printf("%lld %lld\n",s*4+kn[i].a,s*4+kn[i].b);
    ref(s,0,n>>2)ref(t,s+1,n>>2)ref(i,0,16)printf("%lld %lld\n",kw[i].a+s*4,kw[i].b+t*4);
    return 0;
}