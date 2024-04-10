#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}
 
namespace Bluestein{
	const u64 mod1=1004535809;
	const u64 mod2=998244353;
	const int N=(1<<20)+5,g=3;
	template<const u64 mod> u64 po(u64 x,u64 p){
		u64 res=1;
		for(;p;p>>=1,x=x*x%mod)
			if(p&1) res=res*x%mod;
		return res;
	}
	struct Z{
		u64 a,b;
		Z(const u64 &x=0,const u64 &y=0):a(x),b(y){}
		friend Z operator * (const Z &x,const Z &y){
			return Z(x.a*y.a%mod1,x.b*y.b%mod2);
		}
		friend Z operator + (const Z &x,const Z &y){
			return Z(x.a+y.a,x.b+y.b);
		}
		friend Z operator - (const Z &x,const Z &y){
			return Z(x.a-y.a,x.b-y.b);
		}
	} a[N],b[N],w[N],*H[30],*las=w;
	const Z mod=Z(mod1,mod2);
	void dft(Z *a,int n){
		static int R[N],mx=0;
		for(;mx<n;mx++){
			H[mx]=las; Z w=Z(1,1),wn;
			wn.a=po<mod1>(u64(g),(mod1-1)>>(mx+1));
			wn.b=po<mod2>(u64(g),(mod2-1)>>(mx+1));
			REP(i,1<<mx) *las++=w,w=w*wn;
		}
		REP(i,1<<n){
			R[i]=(i&1?R[i^1]|(1<<(n-1)):R[i>>1]>>1);
			if(i<R[i]) swap(a[i],a[R[i]]);
		}
		for(int k=0,d=1;k<n;k++,d<<=1){
			for(int i=0;i<(1<<n);i+=d<<1){
				Z *l=a+i,*r=a+i+d,*w=H[k];
				for(int j=0;j<d;j++,l++,r++){
					const Z t=*r*(*w++);
					*r=*l+mod-t,*l=*l+t;
				}
			}
			if(k!=12) continue;
			REP(i,1<<n) a[i]=a[i]*Z(1,1);
		}
		REP(i,1<<n) a[i]=a[i]*Z(1,1);
	}
	void idft(Z *a,int n){
		reverse(a+1,a+(1<<n));
		dft(a,n);
		Z inv=Z(po<mod1>(u64(1)<<n,mod1-2),po<mod2>(u64(1)<<n,mod2-2));
		REP(i,1<<n) a[i]=a[i]*inv;
	}
	int p[N],phi,k;
	ll P(ll x){ return p[(x%phi+phi)%phi]; }
	void DFT(int *f,int m,int w){
		for(k=1;(1<<k)<m*2;k++);
		p[0]=1,phi=m-1;
		rep(i,1,phi-1) p[i]=(ll)p[i-1]*w%m;
		REP(i,m-1){
			int x=(ll)f[i]*P(-(ll)i*(i-1)/2)%m;
			int y=P((ll)i*(i-1)/2);
			a[m-1-i]=Z(x,x),b[i]=Z(y,y);
		}
		dft(a,k),dft(b,k);
		REP(i,1<<k) a[i]=a[i]*b[i];
		idft(a,k);
		REP(i,m-1){
			u64 x=a[m-1+i].a*po<mod1>(mod2,mod1-2)%mod1;
			u64 y=a[m-1+i].b*po<mod2>(mod1,mod2-2)%mod2;
			f[i]=(x*mod2+y*mod1)%(mod1*mod2)%m*P(-(ll)i*(i-1)/2)%m;
		}
		REP(i,m-1){
			u64 x=a[i].a*po<mod1>(mod2,mod1-2)%mod1;
			u64 y=a[i].b*po<mod2>(mod1,mod2-2)%mod2;
			f[i]=((x*mod2+y*mod1)%(mod1*mod2)%m
				*P(-(ll)i*(i-1)/2+phi/2)+f[i])%m;
		}
	}
}
 
const int mod=490019,N=mod+5,w=2;
int a[N],f[N],n,m,b,c,ind,ans;
 
int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}
 
int main(){
	read(n),read(m),read(c);
	REP(i,n) read(a[i]);
	REP(i,m){
		read(b);
		int k=(ll)i*i*i%(mod-1);
		f[k]=(f[k]+b)%mod;
	}
	Bluestein::DFT(f,mod,w);
	for(int now=1;now!=c;now=(ll)now*w%mod,ind++);
	REP(i,n){
		int k=(ll)ind*i*i%(mod-1);
		ans=(ans+(ll)a[i]*f[k])%mod;
	}
	cout<<ans<<endl;
	return 0;
}