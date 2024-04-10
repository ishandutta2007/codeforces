#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef unsigned long long ull;const ll N=(2e5+7)*32,inf=998244353;typedef ll aN[N];aN d;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
template<typename T,int N>struct ptarr{
    T*p[N];ptarr(){}ptarr(T*a){ref(i,0,N)p[i]=a+i;}T&operator[](ll b){return*p[b];}
    const T&operator[](ll b)const{return*p[b];}void swap(ll x,ll y){std::swap(p[x],p[y]);}
};struct bitset{
    ull f[(2002>>6)+1];ll n;void reset(ll n_){memset(f,0,sizeof(ll)*(((n=n_)>>6)+1));}
    void set(ll d){f[d>>6]|=1ull<<(d&63);}void operator^=(const bitset&b){ll u=n>>6;rep(i,0,u)f[i]^=b.f[i];}
    ll operator[](ll b)const{return f[b>>6]>>(b&63)&1;}void print()const{rep(i,0,n)printf("%lld",(*this)[i]);puts("");}
}g[2002];ptarr<bitset,2002>f(g);
void calc(int cases){
    ll n=readll(),m=readll(),u,v;rep(i,1,n)f[i].reset(n+1),d[i]=0;(void)cases;
    rep(i,1,m)u=readll(),v=readll(),f[u].set(v),f[v].set(u),d[u]^=1,d[v]^=1;
    ll flag=1;rep(i,1,n)if(d[i])f[i].set(n+1),f[i].set(i),flag=0;if(flag){puts("1");rep(i,1,n)printf("1 ");puts("");}
    else{rep(i,1,n){rep(j,i,n)if(f[j][i]){f.swap(i,j);break;}if(f[i][i])rep(j,1,n)if(i^j&&f[j][i])f[j]^=f[i];}
    puts("2");rep(i,1,n)printf("%lld ",f[i][n+1]+1);puts("");}
}int main(){ll T=readll(),cnt=0;while(T --> 0)calc(++cnt);return 0;}