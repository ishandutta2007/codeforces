#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,mod=1e9+7,mod2=mod*mod,inf=1e18;typedef ll aN[N];
void qmod(ll&a,ll b){if(a>b)a-=b;}
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}ll ssh[N];
ll pow(ll a,ll b,ll p){ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
template<ll n,ll m=n>struct mtr{
    ll val[n][m];mtr(){memset(&val,0,sizeof(val));}mtr(const ll(&a)[n][m]){memcpy(&val,a,sizeof(val));}
    const ll*operator[](ll b)const{return val[b];}ll*operator[](ll b){return val[b];} 
};template<ll n,ll t,ll m>mtr<n,m>operator*(const mtr<n,t>&a,const mtr<t,m>&b){
    mtr<n,m>c;ref(i,0,n)ref(j,0,t)ref(k,0,m)qmod(c[i][k]+=a[i][j]*b[j][k],mod2);
    ref(i,0,n)ref(k,0,m)c[i][k]%=mod;return c;
}template<ll n>struct vec{
    ll val[n];vec(){memset(&val,0,sizeof(val));}vec(const ll(&a)[n]){memcpy(&val,a,sizeof(val));}
    ll operator[](ll b)const{return val[b];}ll&operator[](ll b){return val[b];} 
};template<ll t,ll m>vec<m>operator*(const vec<t>&a,const mtr<t,m>&b){
    vec<m>c;ref(j,0,t)ref(k,0,m)qmod(c[k]+=a[j]*b[j][k],mod2);ref(k,0,m)c[k]%=mod;return c;
}template<int n>void calc(vec<n>&res,mtr<n>a,ll b){while(b){if(b&1)res=res*a;a=a*a,b>>=1;}}
const ll K=101;vec<K>f;mtr<K>g;ll a[N]; 
int main(){
    ll n=readll(),k=readll(),s=0,now=0;rep(i,1,n)s+=!(a[i]=readll());
    rep(i,0,s)i&&(g[i][i-1]=i*i),g[i][i]=n*(n-1)/2-i*i-(s-i)*(n-s-i),i!=n&&(g[i][i+1]=(s-i)*(n-s-i));
    rep(i,1,s)now+=a[i];f[now]=1;calc<K>(f,g,k);printf("%lld\n",f[0]*pow(n*(n-1)/2%mod,mod-1-k,mod)%mod);return 0; 
}