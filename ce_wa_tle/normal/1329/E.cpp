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
ll n,m,k,c[414514],maxr[414514];ll ddiv(ll a,ll b){return b?a/b:-inf;}ll udiv(ll a,ll b){return b?ddiv(a+b-1,b):inf;}
ll getr(){
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)>>1,ans=0;rep(i,1,m)ans+=udiv(c[i],mid)-1;
//        printf("%lld %lld\n",mid,ans);
        if(ans<=k)r=mid-1;else l=mid+1;
    }return l;
}
ll getl(){
    ll l=1,r=n;
    while(l<=r){
        ll mid=(l+r)>>1,ans=0;rep(i,1,m)ans+=ddiv(c[i],mid)-1;
//        printf("%lld %lld\n",mid,ans);
        if(ans<k)r=mid-1;else l=mid+1;
    }return r;
}
struct lim{ll l,r;operator ll()const{return-l;}}x[414514];
int main(void){
//    IO(CF1329E);
    rfor(ll T=readll()/*,ps=T==37813*/;T--;){
        n=readll(),m=readll(),k=readll();rep(i,1,m)c[i]=readll();
//        if(ps&&T+49==37813){
//            printf("%lld %lld %lld\n",n,m,k);
//            rep(i,1,m)printf("%lld ",c[i]);puts("");
//        }
//        if(ps)continue;
        c[++m]=n;per(i,m,1)c[i]=c[i]-c[i-1];
        ll r0=getr(),l0=getl(),cnt=0;
//        rep(i,1,m)printf("%lld ",c[i]);puts("");
//        printf("%lld %lld\n",r0,l0);
//        exit(0);
        if(l0>r0)puts("0");
        else{
            rep(i,1,m)if(udiv(c[i],r0)>ddiv(c[i],l0))
            x[++cnt]=(lim){ddiv(c[i],ddiv(c[i],l0)+1),udiv(c[i],udiv(c[i],r0)-1)};//,printf("%lld\n");
//            printf("l<=%lld&&r>=%lld\n",l0,r0);
//            rep(i,1,cnt)printf("l<=%lld||r>=%lld\n",x[i].l,x[i].r);puts("");
            std::sort(x+1,x+cnt+1);maxr[cnt+1]=r0;per(i,cnt,1)maxr[i]=max(maxr[i+1],x[i].r);
//            rep(i,1,cnt)printf("l<=%lld||r>=%lld\n",x[i].l,x[i].r);puts("");
            ll ans=1145141191981011111ll,minl=l0;rep(i,0,cnt)ans=min(ans,maxr[i+1]-(i?minl=min(minl,x[i].l):minl));//,printf("%lld %lld\n",minl,maxr[i+1]);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
/*
5
80 3 5
11 24 50
81 7 12
4 10 17 26 37 48 61
25 10 14
3 4 7 12 13 15 17 19 21 23
1 0 0
10 2 0
2 4
*/
/*
1
999999914808566 11 6640
5420407209319 118646271831485 170523551851918 288630513056159 451243453050358 471636034866876 498507068042671 607918172824838 697676123481663 970668490668419 975133385966547 
*/