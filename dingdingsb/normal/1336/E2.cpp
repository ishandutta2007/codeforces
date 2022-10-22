#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=60;
#define cnt __builtin_popcountll
int n,m,rka,rkb,c[N];
ll f[N],g[N];mint p[N],fac[N],ifac[N];
mint C(int n,int m){return m<0||n<m?0:fac[n]*ifac[m]*ifac[n-m];}
void ins(ll x){
	for(int i=m-1;~i;i--)if(x>>i&1){
		if(f[i])x^=f[i];
		else return f[i]=x,void();
	}
}
namespace solve0{
	void dfs(int now,ll val){
		if(now==rka)return p[cnt(val)]+=1,void();
		dfs(now+1,val);dfs(now+1,val^g[now]);
	}
	void work(){dfs(0,0);}
}
namespace solve1{
	mint q[N];
	void dfs(int now,ll val){
		if(now==m)return q[cnt(val)]+=1,void();
		dfs(now+1,val);dfs(now+1,val^g[now]);
	}
	void work(){
		dfs(rka,0);
		for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)for(int k=0;k<=i&&k<=j;k++)
			if(k&1)p[i]-=(mint(2)^(mod-1+rka-m))*q[j]*C(j,k)*C(m-j,i-k);
			else p[i]+=(mint(2)^(mod-1+rka-m))*q[j]*C(j,k)*C(m-j,i-k);
	}
}
signed main(){
	fac[0]=ifac[0]=1;for(int i=1;i<N;i++)fac[i]=fac[i-1]*i,ifac[i]=1/fac[i];
	read(n,m);
	for(int i=1;i<=n;i++){ll x;read(x);ins(x);}
	for(int i=0;i<m;i++)for(int j=i+1;j<m;j++)if(f[j]>>i&1)f[j]^=f[i];
	for(int i=0;i<m;i++)if(f[i])c[i]=rka++;
	for(int i=0;i<m;i++)if(!f[i])c[i]=rka+(rkb++);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)if(f[i]>>j&1)g[c[i]]|=1ll<<c[j],g[c[j]]|=1ll<<c[i];
	for(int i=rka;i<m;i++)g[i]|=1ll<<i;
	if(rka<=m/2)solve0::work();
	else solve1::work();
	mint val=mint(2)^(n-rka);
	for(int i=0;i<=m;i++)write((p[i]*val).x),pc(' ');
}