#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){a%=p;ll res=1;while(b){if(b&1)res=res*a%p;a=a*a%p,b>>=1;}return res;}
template<int n,int m=n,ll mod=::mod>struct mtr{ll val[n][m];mtr(){memset(val,0,sizeof val);}
mtr(const ll(&a)[n][m]){memcpy(val,a,sizeof(val));}mtr(ll(&a)[n][m]){memcpy(val,a,sizeof(val));} 
const ll*operator[](ll b)const{return val[b];}ll*operator[](ll b){return val[b];}};void qm(ll&a,ll b){if(a>b)a-=b;}
template<int n,ll mod=::mod>struct vec{ll val[n];vec(){memset(val,0,sizeof val);}
vec(const ll(&a)[n]){memcpy(val,a,sizeof(val));}vec(ll(&a)[n]){memcpy(val,a,sizeof(val));}
void clear(){memset(val,0,sizeof val);}ll operator[](ll b)const{return val[b];}ll&operator[](ll b){return val[b];}};
template<int n,int m,int t,ll mod>mtr<n,m,mod>operator*(const mtr<n,t,mod>&a,const mtr<t,m,mod>&b){
    mtr<n,m,mod>c;ref(i,0,n)ref(j,0,t)ref(k,0,m)qm(c[i][k]+=a[i][j]*b[j][k],mod*mod);
    ref(i,0,n)ref(k,0,m)c[i][k]%=mod;return c;
}template<int m,int t,ll mod>vec<m,mod>operator*(const vec<t,mod>&a,const mtr<t,m,mod>&b){
    vec<m,mod>c;ref(j,0,t)ref(k,0,m)qm(c[k]+=a[j]*b[j][k],mod*mod);ref(k,0,m)c[k]%=mod;return c;
}template<int n,int mod>void calc(vec<n,mod>&res,mtr<n,n,mod>*a,ll b){ll t=0;while(b){if(b&1)res=res*a[t];b>>=1,++t;}}
mtr<64>g[4],sg[114];ll ans[N][4],a[N],f[4],mex[64];
struct node{ll x,y,c;}qd[N];int operator<(const node&a,const node&b){return a.x!=b.x?a.x<b.x:a.y<b.y;}const ll k=0x15;
void pr(ll x){printf("%lld,%lld,%lld",x>>4&3,x>>2&3,x&3);} 
int main(){
	ll n=rd,x,y,c;rep(i,1,n)a[i]=rd;ll m=rd;rep(i,1,m)x=rd,y=rd,c=rd,qd[i]=(node){x,y,c};
	rep(i,1,n)qd[m+i]=(node){i,a[i]+1,0};std::sort(qd+1,qd+m+n+1);
	rep(i,1,3)ref(j,0,3)f[i]|=rd?3<<(2*j):0;ref(j,0,64)mex[j]=~j>>1&~j&k?~j>>1&j&k?j>>1&~j&k?3:2:1:0;
	rep(i,1,3)ref(j,0,64)g[i][j][(j<<2&63)|mex[j|(~f[i]&63)]]++;
	rep(i,1,3)ref(j,0,64)ref(k,0,64)qm(g[0][j][k]+=g[i][j][k],mod);
	sg[0]=g[0];rep(i,1,45)sg[i]=sg[i-1]*sg[i-1];
	ans[0][0]=1;ll lst=0;vec<64>f;f[63]=1;rep(i,1,m+n+1){if(qd[i].x!=qd[i-1].x&&i!=1){
	ref(j,0,64)rep(c,0,3)qm(ans[qd[i-1].x][c]+=ans[qd[i-1].x-1][c^(j&3)]*f[j]%mod,mod);
	lst=0,f.clear(),f[63]=1;}if(i==m+n+1)continue;calc<64,mod>(f,sg,qd[i].y-lst-1),lst=qd[i].y;if(qd[i].c)f=f*g[qd[i].c];}
	printf("%lld\n",ans[n][0]);return 0;
}