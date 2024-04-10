//by chenkuowen01
/*-------------------Intialize Module--------------------*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
/*-------------------Basis Functions----------------------*/
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){ 
	for(auto t:y) t<x?x=t:0;
}
template<class T> inline void dmax(T& x,vector<T> y){
	for(auto t:y) t>x?x=t:0;
}
/*-------------------Input/Output Module------------------*/
namespace IO{
	const int sz=1<<20;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	bool flag=0;
	void change_flag(bool s){ flag=s; }
	inline char gc(){
		return p1==p2?(flag?getchar():(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++)):*p1++;
	}
	template<class T> void gi(T& ret){
		ret=0; char c=gc(); int f=1;
		for(;c<'0'||c>'9';c=gc())
			if(c=='-') f=-1;
		for(;c>='0'&&c<='9';c=gc())
			ret=ret*10+(c-'0');
		ret*=f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){
		*t++=x; if(t-b==sz) flush();
	}
	template<class T> void pi(T x,char c='\n'){
		if(x<0) pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
		if(flag) flush();
	}
	struct F{~F(){flush();}}f;
}
/*---------------Mod Operator&Combinatorial Mathematics-----------*/
namespace SB_MATH{
struct ModOperator{
	int MOD;
	ModOperator(int mod){ MOD=mod; }
	inline int fpow(int x,int n,int ret=1){
		for(;n;n>>=1,x=1ll*x*x%MOD)
			n&1?ret=1ll*ret*x%MOD:0;
		return ret;
	}
	inline void mo(int& x){ x>=MOD?x-=MOD:0; }
	inline int mo1(int x){ return x>=MOD?x-MOD:x; }
	inline int mo2(int x){ return x<0?x+MOD:x; }
	inline int mo3(int x){ return mo1(mo2(x)); }
	inline int mul(int x,int y){ return 1ll*x*y%MOD; }
	inline int add(int x,int y){ return mo1(x+y); }
	inline int sub(int x,int y){ return mo2(x-y); }
	inline int div(int x,int y){ return fpow(y,MOD-2,x); }
	inline vector<int> inv(vector<int> x){ 
		vector<int> y; y.resize(x.size());
		int s=1,s1=1,s2=1;
		for(auto t:x) s=1ll*s*t%MOD;
		if(s==0) assert(0);
		s=fpow(s,MOD-2);
		for(int i=0;i<x.size();++i){
			y[i]=1ll*s*s1%MOD;
			s1=1ll*s1*x[i]%MOD;
		}
		for(int i=(int)x.size()-1;i>=0;--i){
			y[i]=1ll*y[i]*s2%MOD;
			s2=1ll*s2*x[i]%MOD;
		}
		return y;
	}
};
struct Comb{
	vector<int> fac,inv,fac_inv;
	ModOperator* P;
	int MOD;
	Comb(ModOperator* s,int sz){
		P=s; MOD=P->MOD;
		fac.resize(sz);
		inv.resize(sz);
		fac_inv.resize(sz);
		inv[1]=fac[0]=fac_inv[0]=1;
		for(int i=1;i<sz;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			fac_inv[i]=1ll*fac_inv[i-1]*inv[i]%MOD;
		}
	}
	int operator()(int n,int m){
		if(m<0) return 0;
		if(n>=0){
			if(m>n) return 0;
			return 1ll*fac[n]*fac_inv[m]%MOD*fac_inv[n-m]%MOD;
		}else{
			int ret=1ll*fac[-n+m-1]*fac_inv[m]%MOD*fac_inv[-n-1]%MOD;
			if(m&1) ret=P->mo2(-ret);
			return ret;
		}
	}
};
struct Comb2{
	vector<vector<int> > c;
	Comb2(ModOperator* P,int sz){
		c.resize(sz+1);
		for(int i=0;i<=sz;++i){
			c[i].resize(i+1);
			c[i][0]=1;
			for(int j=0;j<=i;++j)
				c[i][j]=P->add(c[i-1][j],c[i-1][j-1]);
		}
	}
	int operator()(int n,int m){ return c[n][m]; }
};
}
/*--------------------Integer Polynomials------------------------*/
/*-----------------Non-integer Polynomials---------------*/
/*-------------------Geometry----------------------------*/
namespace GEO{
ld EPS=1e-10,PI=acos(-1);
template<class T> int sn(T x) { return x<-EPS?-1:(x>EPS); }
template<class T> struct P{
	T x,y;
	P(T _x=T(),T _y=T()){ x=_x,y=_y; }
	inline P<T> operator+(P<T> b){ return P<T>(x+b.x,y+b.y); }
	inline P<T> operator-(P<T> b){ return P<T>(x-b.x,y-b.y); }
	inline P<T> operator*(P<T> b){ return P<T>(x*b.x-y*b.y,x*b.y+y*b.x); }
	inline P<T> operator/(T t){ return P<T>(x/t,y/t); }
	inline T cp(P<T> b){ return x*b.y-y*b.x; }
	inline T dot(P<T> b){ return x*b.x+y*b.y; }
	inline P<T> rot90(){ return P<T>(-y,x); }
	inline P<T> rot(T x){ return (*this)*P<T>(cos(x),sin(x)); }
	inline int qua(){ return sn(y)>=0?(sn(x)>=0?1:2):(sn(x)>=0?4:3); }
};
template<class T> struct Line{
	P<T> a[2];
	inline P<T>& operator[](int x){ return a[x]; }
	inline P<T> v(){ return a[1]-a[0]; }
	inline int include(P<T> x){ return sn(v().cp(x-a[0])); }
};
template<class T> bool para(P<T> x,P<T> y){ return sn(x.cp(y))==0; }
template<class T> bool para(Line<T> x,Line<T> y){return para(x.v(),y.v());}
template<class T> P<T> getIP(Line<T> a,Line<T> b){
	if(para(a,b)) assert(0);
	T w0=(a[0]-b[0]).cp(b[1]-b[0]);
	T w1=(b[1]-b[0]).cp(a[1]-b[0]);
	return (a[0]*w1+a[1]*w0)/(w0+w1);
}
template<class T> Line<T> getPL(P<T> x,P<T> y){
	P<T> z=(x+y)/2;
	return (Line<T>){z,z+(y-z).rot90()};
}
}
/*-------------------Data Structure----------------------*/
/*-----------------String Algorithms---------------------*/
/*-------------------Coding-----------------------------*/
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a,b; a.resize(n); b.resize(n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		for(int i=0;i<n;++i) scanf("%d",&b[i]);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i=0;i<n;++i) printf("%d ",a[i]); puts("");
		for(int i=0;i<n;++i) printf("%d ",b[i]); puts("");
	}
	return 0;
}