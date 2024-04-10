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
const ll p=998244353,n=2,N=3;
struct mtr{
    ll a[N][N];//ll p,n;mtr(ll p_,ll n_):p(p_),n(n_){memset(a,0,sizeof a);}
    mtr(){memset(a,0,sizeof a);}
    ll*operator[](ll b){return a[b];}
    const ll*operator[](ll b)const{return a[b];}
    mtr operator*(const mtr&b)const{
        mtr c/*(p,n)*/;const ll p2=p*p;
        rep(i,1,n)rep(k,1,n)rep(j,1,n)
        (c[i][j]+=a[i][k]*b[k][j])>p2&&(c[i][j]-=p2);
        rep(i,1,n)rep(j,1,n)c[i][j]%=p;
        return c;
    }
    void read(){
        rep(i,1,n)rep(j,1,n)a[i][j]=readll();
    }
    void print()const{
        rep(i,1,n){
            rep(j,1,n)printf("%lld ",a[i][j]);
            puts("");
        }
    }
};
char s[1500050];
struct ds{
    mtr val[1500050];
    ll a[1500050];
    void set(const char*s){
        ll n=strlen(s);a[0]=9;
        ref(i,0,n)a[n-i]=s[i]^48;
    }
    void build(ll u,ll l,ll r){
        #if 0
        [f_{i-1},f_{i-2}][       a_i+1       ,1]=[f_i,f_{i-1}]
                         [[a_i==1](9-a_{i-1}),0]
        #endif
        if(l==r){
            mtr&now=val[u];
            now[1][1]=a[l]+1,now[1][2]=1,
            now[2][1]=a[l]==1?(9-a[l-1]):0,now[2][2]=0;
            return;
        }
        ll mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        val[u]=val[u<<1]*val[u<<1|1];
    }
    void update(ll u,ll l,ll r,ll q){
        if(l==r){
            mtr&now=val[u];
            now[1][1]=a[l]+1,now[1][2]=1,
            now[2][1]=a[l]==1?(9-a[l-1]):0,now[2][2]=0;
            return;
        }
        ll mid=(l+r)>>1;
        if(q<=mid)update(u<<1,l,mid,q);
        else update(u<<1|1,mid+1,r,q);
        val[u]=val[u<<1]*val[u<<1|1];
    }
}tree;
int main(void){
//    IO(CF1380F);
    ll n=readll(),m=readll();
    scanf("%s",s);
    tree.set(s);
    tree.build(1,1,n);
    mtr g;g[1][1]=g[1][2]=1;
    rep(i,1,m){
        ll x=n-readll()+1,y=readll();
        tree.a[x]=y;
        tree.update(1,1,n,x);
        if(x!=n)
        tree.update(1,1,n,x+1);
//        rep(j,1,n)printf("%lld ",tree.a[j]);puts("");
        printf("%lld\n",(g*tree.val[1])[1][1]);
    }
    return 0;
}

//1 1 1 1
//1 1 1 1
//1 1 1 1
//1 1 1 1