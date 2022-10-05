#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vi poly;

namespace IOManager {
	constexpr int FILESZ = 131072;
	char buf[FILESZ];
	const char *ibuf = buf, *tbuf = buf;
 
	struct IOManager {
		inline char gc() {
			return (ibuf == tbuf) && (tbuf = (ibuf = buf) + fread(buf, 1, FILESZ, stdin), ibuf == tbuf) ? EOF : *ibuf++;
		}
 
		template <class _Tp>
			inline operator _Tp() {
				_Tp s = 0u; char c = gc();
				for (; c < 48; c = gc());
				for (; c > 47; c = gc())
					s = (_Tp)(s * 10u + c - 48u);
				return s;
			}
	};
} IOManager::IOManager io;
/*
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;

}
*/
#define read(x) (x=io)

const int N=100005;
namespace{
	const int mod=998244353;
	int fac[N],rev[N];
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	void init(int n){
		fac[0]=1;
		rep(i,1,n) fac[i]=mul(fac[i-1],i);
		rev[n]=power(fac[n],mod-2);
		per(i,n,1) rev[i-1]=mul(rev[i],i);
	}
}
namespace Poly{
	const int N=(1<<20)+5,g=3;
	void dft(poly &A,int n){
		static ll W[N<<1],*H[30],*las=W,mx=0;
		for(;mx<n;mx++){
			H[mx]=las;ll w=1,wn=power(g,(mod-1)>>(mx+1));
			REP(i,1<<mx)*las++=w,w=w*wn%mod;
		}
		static ll a[N];A.resize(1<<n);
		for(int i=0,j=0;i<(1<<n);++i){
			a[i]=A[j];
			for(int k=1<<(n-1);(j^=k)<k;k>>=1);
		}
		for(int k=0,d=1;k<n;k++,d<<=1)
			for(int i=0;i<(1<<n);i+=d<<1){
				ll *l=a+i,*r=a+i+d,*w=H[k],t;
				for(int j=0;j<d;++j,++l,++r){
					t=(*w++)*(*r)%mod;
					*r=*l+mod-t,*l+=t;
				}
			}
		REP(i,1<<n)A[i]=a[i]%mod;
	}
	void idft(poly &a,int n){
		a.resize(1<<n);
		reverse(a.begin()+1,a.end());
		dft(a,n);
		int inv=power(1<<n,mod-2);
		REP(i,1<<n)a[i]=(ll)a[i]*inv%mod;
	}
	poly mul(poly a,poly b){
		int aim=(a.size()+b.size()),n=1;
		while((1<<n)<=aim)n++;
		dft(a,n),dft(b,n);
		REP(i,1<<n)a[i]=(ll)a[i]*b[i]%mod;
		return idft(a,n),a.resize(aim),a;
	}
}

poly f,g,c,r;
int n; ll m;

int main(){
	read(n),read(m),init(n+1);
	f.resize(n+1),c.resize(n+1);
	rep(i,0,n){
		read(f[i]);
		f[i]=mul(f[i],fac[i]);
		c[n-i]=rev[i];
	}
	r=Poly::mul(f,c),g.resize(n+1);
	rep(i,0,n){
		int inv=mul(rev[i+1],fac[i]);
		g[i]=mul(r[i+n],power(inv,m%(mod-1)));
		c[n-i]=(i&1?mod-rev[i]:rev[i]);
	}
	r=Poly::mul(g,c);
	rep(i,0,n){
		f[i]=mul(r[i+n],rev[i]);
		printf("%d ",f[i]);
	}
	puts("");
	return 0;
}