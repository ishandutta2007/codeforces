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
const ll N=222222;typedef ll aN[N];ll n,q,cnt=0;aN head,to,next,w;
void add(ll u,ll v,ll c){next[++cnt]=head[u],to[head[u]=cnt]=v,w[cnt]=c;}
struct cmp{const ll*s;cmp(const ll*s_):s(s_){}operator()(ll a,ll b){return s[a]>s[b];}};
struct tree{
    aN d,g,f[22],r,s,l,t,len,p,ans,rk;ll cnt=0,root;
    void dfs1(ll u,ll fa,ll c){d[u]=d[fa]+c;rfor(ll i=head[u];i;i=next[i])if(to[i]^fa)dfs1(to[i],u,w[i]);}
    void dfs2(ll u,ll fa,ll c){
        d[u]=d[f[0][u]=fa]+c,s[u]=0,l[u]=0;rfor(ll i=head[u];i;i=next[i])
        if(to[i]^fa){dfs2(to[i],u,w[i]);if(l[u]<l[to[i]]+w[i])l[u]=l[s[u]=to[i]]+w[i];}
    }
    void dfs3(ll u,ll fa,ll c){
        t[u]=c;if(s[u])dfs3(s[u],u,c);rfor(ll i=head[u];i;i=next[i])if(to[i]^fa&&to[i]^s[u])dfs3(to[i],u,to[i]);
    }
    void getroot(ll u){
        dfs1(u,0,0);rep(i,1,n)if(d[i]>d[root])root=i;dfs2(root,0,0),dfs3(root,0,root);
        rep(j,1,20)rep(i,1,n)f[j][i]=f[j-1][f[j-1][i]];
//        printf("%lld\n",root);
//        rep(i,1,n)printf("%lld ",s[i]);puts("");
//        rep(i,1,n)printf("%lld ",d[i]);puts("");
        rep(i,1,n)if(t[i]==i)len[p[++cnt]=i]=l[i]+d[i]-d[f[0][i]];//,printf("%lld ",len[p[cnt]]);puts("");
        std::sort(p+1,p+cnt+1,cmp(len));rep(i,1,cnt)ans[i]=ans[i-1]+len[p[i]];
        rep(i,1,cnt)rk[p[i]]=i;rep(i,1,n)rk[i]=rk[t[i]];
//        rep(i,1,n)printf("%lld ",rk[i]);puts("");
//        rep(i,1,cnt)printf("%lld ",len[p[i]]);puts("");
    }
    ll get(ll x,ll y){per(j,20,0)if(rk[f[j][x]]>y)x=f[j][x];return x;}
    ll getans(ll x,ll y){
        if(rk[x]<=(y=y*2-1))return ans[min(y,cnt)];ll u=f[0][get(x,y-1)],v=f[0][get(x,y)];
//        printf("%lld %lld %lld %lld %lld %lld %lld\n",y,get(x,y),v,ans[y],l[v],l[x],d[x]-d[v]);
        return max(ans[y-1]+l[x]+d[x]-d[u],ans[y]-l[v]+l[x]+d[x]-d[v]);
    }
}t[2];
int main(void){
//    IO(CF526G);
    n=readll(),q=readll();rep(i,2,n){ll x=readll(),y=readll(),c=readll();add(x,y,c),add(y,x,c);}
    t[0].getroot(1),t[1].getroot(t[0].root);//printf("%lld %lld %lld\n",t[0].ans[1],t[0].cnt,t[1].cnt);
    ll lst=0;rep(i,1,q){ll x=(lst+readll()-1)%n+1,y=(lst+readll()-1)%n+1;
//    printf("%lld %lld ",x,y);
    printf("%lld\n",lst=max(t[0].getans(x,y),t[1].getans(x,y)));}
    return 0;
}
/*
9 1
3 7 700
5 4 523
7 1 665
9 5 373
8 7 120
2 3 80
2 5 739
6 8 353
9 1

8 1
4 6
7 6
2 3
3 9
2 3
1 9
5 3
4 3
3 3
*/
/*
9 10
2 1 903
1 8 76
5 6 737
3 4 204
8 7 676
6 1 694
3 1 65
2 9 27
2 1
3 7
2 7
7 7
2 7
1 7
7 5
5 3
6 2
9 7
*/