#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=422222,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){a%=p;ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
template<int n,int m=n,ll mod=::mod>struct mtr{ll val[n][m];mtr(){memset(val,0,sizeof val);}
mtr(const ll(&a)[n][m]){memcpy(val,a,sizeof(val));}mtr(ll(&a)[n][m]){memcpy(val,a,sizeof(val));} 
const ll*operator[](ll b)const{return val[b];}ll*operator[](ll b){return val[b];}};void qm(ll&a,ll b){if(a>b)a-=b;}
template<int n,ll mod=::mod>struct vec{ll val[n];vec(){memset(val,0,sizeof val);}
vec(const ll(&a)[n]){memcpy(val,a,sizeof(val));}vec(ll(&a)[n]){memcpy(val,a,sizeof(val));} 
ll operator[](ll b)const{return val[b];}ll&operator[](ll b){return val[b];}};
template<int n,int m,int t,ll mod>mtr<n,m,mod>operator*(const mtr<n,t,mod>&a,const mtr<t,m,mod>&b){
    mtr<n,m,mod>c;ref(i,0,n)ref(j,0,t)ref(k,0,m)qm(c[i][k]+=a[i][j]*b[j][k],mod*mod);
    ref(i,0,n)ref(k,0,m)c[i][k]%=mod;return c;
}template<int m,int t,ll mod>vec<m,mod>operator*(const vec<t,mod>&a,const mtr<t,m,mod>&b){
    vec<m,mod>c;ref(j,0,t)ref(k,0,m)qm(c[k]+=a[j]*b[j][k],mod*mod);ref(k,0,m)c[k]%=mod;return c;
}template<int n,int mod>void calc(vec<n,mod>&res,mtr<n,n,mod>a,ll b){while(b){if(b&1)res=res*a;a=a*a,b>>=1;}}
mtr<5,5,mod-1>g({
{0,0,1,0,0},
{1,0,1,0,0},
{0,1,1,0,0},
{0,0,2,1,0},
{0,0,-6,1,1} 
});
int main(){
    ll n=rd,ans=1;vec<5,mod-1>f;ref(i,0,3)memset(f.val,0,sizeof(f)),f[i]=1,calc<5,mod-1>(f,g,n-1),ans=ans*pow(rd,f[0],mod)%mod;
    memset(f.val,0,sizeof(f)),f[f[3]=4]=1,calc<5,mod-1>(f,g,n-1),printf("%lld\n",ans*pow(rd,f[0],mod)%mod);return 0;
}