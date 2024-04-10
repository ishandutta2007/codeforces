#include<bits/stdc++.h>
using namespace std;
const int N=1<<19|5,MOD=998244353;
typedef unsigned long long ull;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0; }
inline int fpow(int x,int n,int ret=1){	
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int fac[N],inv[N],ifac[N];
struct II{
	II(){
		fac[0]=inv[1]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
namespace POLY{
	int w[N<<1];
	struct II{
		II(){
			for(int s=1;s<N;s<<=1){
				w[s]=1; int wn=fpow(3,(MOD-1)/(s<<1));
				for(int i=1;i<s;++i) w[s+i]=1ll*w[s+i-1]*wn%MOD;
			}
		}
	}__ii;
	inline void NTT(int a[],int n,int t){
		static ull f[N],x,y;
		for(int i=0,pos=0;i<n;++i){
			f[i]=a[pos];
//			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2;s<n;sx=(s=sx)<<1)
			for(ull* i=f;i!=f+n;i+=sx){
				int *wn=w+s;
				for(ull* j=i;j!=i+s;++j,++wn){
					x=*j,y=j[s]**wn%MOD;
					*j=x+y; j[s]=x-y+MOD;
				}
			}
		for(int i=0;i<n;++i) a[i]=f[i]%MOD;
		if(t==-1){
			reverse(a+1,a+n);
			for(int i=0;i<n;++i) a[i]=1ll*a[i]*inv[n]%MOD;
		}
	}
	int x[N],y[N];
	inline void mul(int a[],int b[],int n){
		NTT(a,n,1); NTT(b,n,1);
		for(int i=0;i<n;++i) a[i]=1ll*a[i]*b[i]%MOD;
		NTT(a,n,-1);
	}
	inline void mul2(int a[],int b[],int c[],int n,int t=1){
		for(int i=0;i<n;++i) x[i]=a[i],y[i]=b[~t?i:n-1-i],x[i+n]=y[i+n]=0;
		mul(x,y,n+n);
		for(int i=0;i<n;++i) c[i]=x[~t?i:n-1+i],c[i+n]=0;
	}
	inline void get_inv(int a[],int b[],int n){
		int* g=x; b[0]=fpow(a[0],MOD-2);
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) g[i]=b[i]=0;
			for(int i=0;i<s;++i) g[i]=a[i];
			NTT(g,s+s,1); NTT(b,s+s,1);
			for(int i=0;i<s+s;++i)
				b[i]=(2ll+MOD-1ll*b[i]*g[i]%MOD)*b[i]%MOD;
			NTT(b,s+s,-1);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
		int dftsz(int n){ int t=1; for(;t<n;t<<=1); return t; }
	inline void dc_exp(int x[],int b[],int n,int l=0){//[l,l+n)
		static int y[N];
		if(n==1){
			if(l==0) b[0]=1;
			else b[0]=1ll*b[0]*inv[l]%MOD;
			return;
		}
		int m=n/2; dc_exp(x,b,m,l);
		for(int i=0;i<m;++i) y[i]=b[i],y[i+m]=0;
		NTT(y,n,1);
		for(int i=0;i<n;++i) y[i]=1ll*y[i]*x[i+n]%MOD;
		NTT(y,n,-1);
		for(int i=m;i<n;++i) mo(b[i]+=y[i]);
		dc_exp(x,b+m,m,l+m);
	}
	inline void exp(int a[],int b[],int n){
		static int x[N<<1];
		for(int s=1;s<=n;s<<=1){
			for(int i=0;i<s;++i) x[s+i]=1ll*a[i]*i%MOD;
			NTT(x+s,s,1);
		}
		dc_exp(x,b,n,0);
	}
}
struct Poly{
	vector<int> a;
	Poly(vector<int> _a):a(_a){}
	Poly(int x=0){a.clear(); a.push_back(x); }
	size_t size()const { return a.size(); }
	int& operator[](int x){ return a[x]; }
	int coef(const int& x)const{ return x<a.size()?a[x]:0; }
	void poly_mod(int n){while(a.size()>n) a.pop_back(); }
	Poly operator+(const Poly& b){
		Poly c; c.a.resize(max(a.size(),b.size()));
		for(int i=0;i<c.size();++i) c[i]=mo1(coef(i)+b.coef(i));
		return c;
	}
	Poly operator-(const Poly& b){
		Poly c; c.a.resize(max(a.size(),b.size()));
		for(int i=0;i<c.size();++i) c[i]=mo1(coef(i)+MOD-b.coef(i));
		return c;
	}
	Poly inv(int n){
		static int x[N],y[N];
		int top=1; for(;top<n;top<<=1);
		for(int i=0;i<top;++i) x[i]=coef(i);
		POLY::get_inv(x,y,top);
		return Poly(vector<int>(y,y+n));
	}
	Poly exp(int n){
		static int x[N],y[N];
		int top=1; for(;top<n;top<<=1);
		for(int i=0;i<top;++i) x[i]=coef(i);
		POLY::exp(x,y,top);
		return Poly(vector<int>(y,y+n));
	}
};
Poly operator*(const Poly& a,const Poly& b){
	if(a.size()==0||b.size()==0) return Poly();
	static int x[N],y[N];
	Poly c; c.a.resize(a.size()+b.size()-1);
	int top=1; for(;top<c.size();top<<=1);
	for(int i=0;i<top;++i) x[i]=a.coef(i),y[i]=b.coef(i);
	POLY::mul(x,y,top);
	for(int i=0;i<c.size();++i) c[i]=x[i];
	return c;
}
Poly trans_mul(const Poly& a,const Poly& b){
	if(a.size()<b.size()) return Poly();
	static int x[N],y[N];
	Poly c; c.a.resize(a.size());
	int top=1; for(;top<a.size()+b.size()+2;top<<=1);
	for(int i=0;i<top;++i) x[i]=a.coef(i),y[i]=b.coef(i);
	reverse(y,y+b.size());
	POLY::mul(x,y,top);
	for(int i=0;i<c.size();++i) c[i]=x[i+b.size()-1];
	return c;
}
Poly f,g;
int ans[N];
int main(){
	int n; scanf("%d",&n);
	f.a.resize(n+1);
	for(int i=1;i<=n;++i) 
		if(i<=(n-1)/2) f[i]=inv[i];
	g=f.exp(n+1);
	for(int i=0;i<=n;++i){
		f[i]=1ll*f[i]*fac[i]%MOD;
		g[i]=1ll*g[i]*fac[i]%MOD;
	}
//	for(int i=0;i<=n;++i) printf("<%d>",f[i]); puts("");
//	for(int i=0;i<=n;++i) printf("<%d>",g[i]); puts("");
	Poly h,h2; h.a.resize(n+1,0); h2.a.resize(n+1,0);
	for(int i=1;i<=n;++i){
		if(i-1<=(n-1)/2){
			h[i]=1ll*ifac[n-i]*f[i-1]%MOD*g[n-i]%MOD;
		}
	}
	for(int i=0;i<=n;++i) h2[i]=ifac[i];
	Poly ret=trans_mul(h,h2);
	ans[1]=g[n-1];
	for(int i=2;i<=n;++i)
		ans[i]=1ll*ret[i]*fac[n-i]%MOD*(i-1)%MOD;
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	return 0;
}