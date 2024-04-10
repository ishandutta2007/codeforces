#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb push_back
#pragma GCC optimize(2)
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
int mod=998244353;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
	mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
	friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, int b){return a^=b;}
	mint operator-(){return 0-*this;}bool operator==(const mint b)const{return x==b.x;}
};
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e5+100;
namespace Poly{
	namespace R{
		const ll mod=1231453023109121;
		struct mint{
			ll x;mint(ll o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
			mint&operator*=(mint a){return(x=(__int128)x*a.x%mod),*this;}mint&operator^=( ll b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}
			mint&operator/=(mint a){return*this*=(a^=mod-2);}friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}
			friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}friend mint operator^(mint a, ll b){return a^=b;}
			mint operator-(){return 0-*this;}bool operator==(const mint b)const{return x==b.x;}
		};
		const mint G=3,iG=1/G;
		int rev[N];
		mint a[N],b[N];
		int ext(int n){for(int k=1;;k<<=1)if(k>=n)return k;}
		void init(int n){for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);}
		void ntt(mint*f,int n,int op){
			for(int i=0;i<n;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
			for(int m=1;m<n;m*=2){
				mint wn=(op>0?G:iG)^((mod-1)/(2*m));
				for(int i=0;i<n;i+=2*m){
					mint w=1;
					for(int j=0;j<m;j++,w*=wn){
						mint x=f[i+j],y=w*f[i+j+m];
						f[i+j]=x+y,f[i+j+m]=x-y;
					}
				}
			}
			if(op<0){
				mint inv=mod-(mod-1)/n;
				for(int i=0;i<n;i++)f[i]*=inv;
			}
		}
	}
	struct poly{
		vector<mint>a;
		mint&operator[](int x){return a[x];}
		void resize(int x){a.resize(x);}
		int size(){return a.size();}
		void print(){for(auto x:a)write(x.x),pc(' ');pc('\n');}
	};
	poly operator+(poly a,poly b){
		a.resize(max(a.size(),b.size()));
		for(int i=0;i<b.size();i++)a[i]+=b[i];
		return a;
	}
	poly operator*(poly a,poly b){
		if(!a.size())return a;
		if(!b.size())return b;
		if(a.size()==1&&b.size()==1)return a[0]*=b[0],a;
		int n=a.size()+b.size()-1,lim=R::ext(n);
		a.resize(lim);b.resize(lim);R::init(lim);
		for(int i=0;i<lim;i++)R::a[i].x=a[i].x,R::b[i].x=b[i].x;
		R::ntt(R::a,lim,1);R::ntt(R::b,lim,1);
		for(int i=0;i<lim;i++)R::a[i]*=R::b[i];
		R::ntt(R::a,lim,-1);
		a.resize(n);for(int i=0;i<n;i++)a[i].x=R::a[i].x%mod;
		return a;
	}
	poly shift(poly a){
		a.resize(a.size()+1);
		for(int i=a.size()-1;i;i--)a[i]=a[i-1];
		a[0]=0;return a;
	}
}
using Poly::poly;
using Poly::shift;
int n,a;
map<int,poly>vis[2];
poly f(int a,int p){
	if(vis[p].count(a))return vis[p][a];
	if(a==0)return (poly){};
	if(a&1){
		poly res;
		if(a%2==p)
			res=shift(f(a-1,0)+f(a-1,1)),
			res.resize(max(2,res.size())),res[1]+=1;
		res=res+f(a-1,p);
		if(res.size()>n+1)res.resize(n+1);
		return vis[p][a]=res;
	}else{
		poly res;
		res=f(a/2,0)+f(a/2,1);res[0]+=1;
		res=res*f(a/2,p^((a/2)&1));
		res=res+f(a/2,p);
		if(res.size()>n+1)res.resize(n+1);
		return vis[p][a]=res;
	}
}
signed main(){
	read(n,a,mod);
	mint res=0;
	for(int lim=2;lim<=a;lim*=2){
		poly tmp=f(a/lim,1);
		for(int i=1;i<tmp.size();i+=2)res+=tmp[i];
	}
	writeln(res.x);
}