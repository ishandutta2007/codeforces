#pragma GCC optimize(2)
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
	mint operator-(){return 0-*this;}bool operator==(const mint b)const{return x==b.x;}
};
namespace Poly{
	const int N=2e5+10;
	const mint G=3,iG=1/G;
	int rev[N];mint a[N],b[N];
	int ext(int n){for(int m=1;;m<<=1)if(m>=n)return m;}
	void init(int n){for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);}
	void ntt(mint*f,int n,int op){
		for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
		for(int i=1;i<n;i<<=1){
			mint wn=(op>0?G:iG)^((mod-1)/(2*i));
			for(int j=0;j<n;j+=2*i){
				mint w=1;
				for(int k=0;k<i;k++,w*=wn){
					mint x=f[j+k],y=w*f[i+j+k];
					f[j+k]=x+y,f[i+j+k]=x-y;
				}
			}
		}
		if(op<0){
			mint inv=mod-(mod-1)/n;
			for(int i=0;i<n;i++)f[i]*=inv;
		}
	}
	struct poly{
		vector<mint>a;
		inline mint&operator[](int x){return a[x];}
		inline void resize(int x){a.resize(x);}
		inline int size(){return a.size();}
		void print(){for(auto x:a)write(x.x),pc(' ');pc('\n');}
	};
	poly operator+(poly f,poly g){
		f.resize(max(f.size(),g.size()));
		for(int i=0;i<g.size();i++)f[i]+=g[i];
		return f;
	}
	poly operator+(poly f,mint g){
		if(!f.size())f.resize(1);
		f[0]+=g;return f;
	}
	poly operator-(poly f,poly g){
		f.resize(max(f.size(),g.size()));
		for(int i=0;i<g.size();i++)f[i]-=g[i];
		return f;
	}
	poly operator-(poly f,mint g){
		if(!f.size())f.resize(1);
		f[0]-=g;return f;
	}
	poly operator*(poly f,poly g){
		int n=f.size()+g.size()-1,lim=ext(n);init(lim);
		for(int i=0;i<f.size();i++)a[i]=f[i];
		for(int i=f.size();i<lim;i++)a[i]=0;
		for(int i=0;i<g.size();i++)b[i]=g[i];
		for(int i=g.size();i<lim;i++)b[i]=0;
		ntt(a,lim,1);ntt(b,lim,1);
		for(int i=0;i<lim;i++)a[i]*=b[i];
		ntt(a,lim,-1);
		f.resize(n);
		for(int i=0;i<n;i++)f[i]=a[i];
		return f;
	}
}
using Poly::poly;
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+10;
int n,fa[N],sz[N],top[N],son[N];vector<int>e[N];mint x;
void dfs1(int u){
	sz[u]=1;
	for(auto v:e[u])if(v!=fa[u])
		fa[v]=u,dfs1(v),sz[u]+=sz[v];
}
void dfs2(int u){
	if(!top[u])top[u]=u;
	pair<int,int>mx(0,0);for(auto v:e[u])if(v!=fa[u])chkmx(mx,mp(sz[v],v));
	if(mx.se)top[son[u]=mx.se]=top[u];
	for(auto v:e[u])if(v!=fa[u])dfs2(v);
}
poly a[N],f[N];
poly v[N];int c;
pair<poly,poly>cdq(int l,int r){
	if(l==r)return mp(v[l]+1,v[l]);
	auto L=cdq(l,mid),R=cdq(mid+1,r);
	return mp(L.fi+(R.fi-1)*L.se,L.se*R.se);
}
void dfs3(int u){
	a[u].resize(2);a[u][1]=1;
	for(auto v:e[u])if(v!=fa[u])
		dfs3(v),(v!=son[u])&&(a[u]=a[u]*f[v],1);
	if(u==top[u]){
		poly&res=f[u];
		c=0;while(u)v[++c]=a[u],u=son[u];
		res=cdq(1,c).fi;
	}
}
signed main(){
	read(n,x);
	for(int i=1,u,v;i<n;i++)read(u,v),e[u].pb(v),e[v].pb(u);
	dfs1(1);dfs2(1);dfs3(1);
	mint val=1,ans=0;
	for(int i=1;i<=n;i++){
		ans+=val*f[1][i];
		val*=x+i;val/=i;
	}
	writeln(ans.x);
}