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
namespace GEO{
/*
CH,HP/,PL,IP
TG,CTG(ICTG,ECTG)
*/
// point,vector&line
ld EPS=1e-10,PI=acos(-1);
template<class T> int sn(T x) { return x<-EPS?-1:(x>EPS); }
template<class T> struct P{ //represent a point, a vector, or a complex
	T x,y;
	P(T _x=T(),T _y=T()){ x=_x,y=_y; }
	inline P<T> operator!()const { return P<T>(x,-y); }
	inline P<T> operator+(const P<T>& b)const { return P<T>(x+b.x,y+b.y); }
	inline P<T> operator-(const P<T>& b)const { return P<T>(x-b.x,y-b.y); }
	inline P<T> operator*(const P<T>& b)const { return P<T>(x*b.x-y*b.y,x*b.y+y*b.x); }
	inline P<T> operator/(const T& t)const { return P<T>(x/t,y/t); }
	inline P<T> div2(const P<T>& b) const { return (*this)*(!b); }
	inline P<T> operator/(const P<T>& b)const { return div2(b)/b.dis2(); }
	inline T dis2()const { return x*x+y*y; }
	inline T dis()const { return sqrt(dis2()); }
	inline T cp(const P<T>& b)const { return x*b.y-y*b.x; }
	inline T dot(const P<T>& b)const { return x*b.x+y*b.y; }
	inline P<T> rot90()const { return P<T>(-y,x); }
	inline P<T> rot(const T& x)const { return (*this)*P<T>(cos(x),sin(x)); }
	inline int qua()const { return sn(y)>=0?(sn(x)>=0?1:2):(sn(x)>=0?4:3); }
	inline P<T> splay(const T& d)const{ return (*this)/dis()*d; }
};
template<class T>istream& operator>>(istream& s,P<T>& p)
{ return s>>p.x>>p.y; }
template<class T>ostream& operator<<(ostream& s,P<T>& p)
{ return s<<"("<<p.x<<","<<p.y<<")"; }
template<class T> struct Line{ 
	//represent a line, a half-line, a segment line or a half-plane
	P<T> a[2];
	inline P<T>& operator[](int x){ return a[x]; }
	inline P<T> v()const { return a[1]-a[0]; }
	inline int in(const P<T>& x)const { return sn(v().cp(x-a[0])); }
	inline P<T> proj(const P<T>& x)const { return a[0]+v()*(x-a[0]).dot(v())/v().dis2(); }
	inline T dis(const P<T>& x)const { return (x-proj(x)).dis(); }
	inline Line<T> tran(const P<T>& x)const{ return (Line){a[0]+x,a[1]+x}; }
};
template<class T> istream& operator>>(istream& s,Line<T>& p)
{ return s>>p[0]>>p[1]; }
template<class T> ostream& operator<<(ostream& s,Line<T>& p)
{ return s<<"("<<p[0]<<","<<p[1]<<")"; }
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
template<class T> bool point_cmp_1(P<T> a,P<T> b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
template<class T> vector<P<T> > getCH(vector<P<T> > h){ //get convexhull
	sort(h.begin(),h.end(),point_cmp_1<T>);
	vector<P<T> > a,b; a.resize(h.size()); b.resize(h.size());
	int tpa=0,tpb=0;
	for(int i=0;i<h.size();++i){
		while(tpa>1&&sn((a[tpa-1]-a[tpa-2]).cp(h[i]-a[tpa-2]))>=0) --tpa;
		while(tpb>1&&sn((b[tpb-1]-b[tpb-2]).cp(h[i]-b[tpb-2]))<=0) --tpb;
		a[tpa++]=h[i]; b[tpb++]=h[i];
	}
	for(int i=tpb-2;i>=1;--i) a[tpa++]=b[i];
	return vector<P<T> >(a.begin(),a.begin()+tpa);
}
template<class T>bool vector_cmp_1(Line<T> a,Line<T> b){
	P<T> va=a.v(),vb=b.v();
	if(va.qua()!=vb.qua()) return va.qua()<vb.qua();
	if(para(a,b)) return b.include(a[0])>0;
	return sn(va.cp(vb))>0;
}
template<class T>inline vector<Line<T> > getHP(vector<Line<T> > h){
	sort(h.begin(),h.end(),vector_cmp_1<T>);
	deque<Line<T> > q;
	for(int i=0;i<h.size();++i){
		if(i>0&&para(h[i],h[i-1])) continue;
		while(q.size()>1&&h[i].in(getIP(q[q.size()-1],q[q.size()-2]))<0)
			q.pop_back();
		while(q.size()>1&&h[i].in(getIP(q[0],q[1]))<0) q.pop_front();
		q.push_back(h[i]);
	}
	while(q.size()>2&&q[0].in(getIP(q[q.size()-1],q[q.size()-2]))<0)
		q.pop_back();
	while(q.size()>2&&q[q.size()-1].in(getIP(q[0],q[1]))<0)
		q.pop_front();
	vector<Line<T> > ans;
	for(auto x:q) ans.push_back(x);
	return ans;
}
//circle
template<class T>struct Circle{
	P<T> x; T r;
	Circle(P<T> _x=P<T>(),T _r=T()){ x=_x,r=_r; }
	Circle(P<T> a,P<T> b,P<T> c){
		x=getIP(getPL(a,b),getPL(b,c));
		r=(x-a).dis();
	}
	int in(P<T> y){ return sn(r-(x-y).dis()); }
	vector<P<T> > getIP(Line<T> a){
		P<T> s=a.proj(x);
		db dis1=(x-s).dis();
		if(in(s)<0) return {};
		if(in(s)==0) return {s};
		P<T> v=a.v()*sqrt(r*r-dis1*dis1)/a.v().dis();
		return {s+v,s-v};
	}
	vector<Line<T> > getTG(P<T> a){
		if(in(a)>0) return {};
		if(in(a)==0) return {(Line<T>){a,a+(x-a).rot90()}};
		db s1=(x-a).dis(),s2=sqrt(s1*s1-r*r);
		P<T> p1=(x-a)*P<T>(s2/s1,r/s1),p2=(x-a)*P<T>(s2/s1,-r/s1);
		return {Line<T>{a,a+p1},(Line<T>){a,a+p2}};
	}
};
template<class T> vector<Line<T> > getECTG(Circle<T> a,Circle<T> b){
	if(a.r<b.r) swap(a,b);
	int w1=sn((a.x-b.x).dis()-(a.r-b.r));
	if(w1<0) return {};
	if(w1==0){
		if(a.r==b.r) assert(0);
		P<T> p=(b.x-a.x).splay(a.r);
		return {(Line<T>){a.x+p,a.x+p+p.rot90()}};
	}
	if(a.r==b.r){
		Line<T> l=(Line<T>){a.x,b.x};
		P<T> p=(b.x-a.x).rot90().splay(a.r);
		return {l.tran(p),l.tran(P<T>()-p)};
	}
	return a.getTG(a.x+(b.x-a.x)/(a.r-b.r)*a.r);
}
template<class T> istream& operator>>(istream& s,Circle<T>& a)
{return s>>a.x>>a.r; }
template<class T> ostream& operator<<(ostream& s,Circle<T>& a)
{return s<<"["<<a.x<<a.r<<"]"; }
namespace GEO_3D{
//3D template
template<class T> struct P3{
	T x,y,z;
	P3(T _x=T(),T _y=T(),T _z=T()){ x=_x,y=_y,z=_z; }
	inline P3<T> operator+(const P3<T>& b)const{return P3(x+b.x,y+b.y,z+b.z); }
	inline P3<T> operator-(const P3<T>& b)const{return P3(x-b.x,y-b.y,z-b.z); }
	inline P3<T> operator*(const T& t)const{ return P3(x*t,y*t,z*t); }
	inline P3<T> operator/(const T& t)const{ return P3(x/t,y/t,z/t); }
	inline T dis2()const{ return x*x+y*y+z*z; }
	inline T dis()const{ return sqrt(dis2()); }
	inline T dot(const P3<T>& b)const{ return x*b.x+y*b.y+z*b.z; }
	inline P3<T> cp(const P3<T>& b)const
	{ return P3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x); }
};
template<class T>istream& operator>>(istream& s,P3<T> x)
{ return s>>x.x>>x.y>>x.z; }
template<class T>ostream& operator<<(ostream& s,P3<T> x)
{ return s<<'('<<x.x<<','<<x.y<<','<<x.z<<')'; }
}
}
/*-------------------Coding-----------------------------*/
const int MAX_N=5+1e5,MOD=2520;
int cnt[10],sum=0,pw[MAX_N];
void add(int a[],int n){
	sum=(sum+1)%MOD;
	for(int i=0;i<n+1;++i){
		if(a[i]<9){
			cnt[a[i]]--;
			a[i]++; 
			cnt[a[i]]++;
			break;
		}
		a[i]=2; cnt[9]--; cnt[2]++;
		sum=(sum+2*pw[i])%MOD;
	}
//	for(int i=1;i<=9;++i) printf("[%d]",cnt[i]);
//	printf("{%d}\n",sum);
}
bool check(){
	for(int i=1;i<=9;++i)
		if(cnt[i]>0&&sum%i==0)
			return false;
	return true;
}
int a[MAX_N];
int main(){
	pw[0]=1;
	for(int i=1;i<=100000;++i) pw[i]=10ll*pw[i-1]%MOD;
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		memset(a,0,sizeof(int)*(n+1));
		memset(cnt,0,sizeof(cnt));
		cnt[2]=n; sum=0;
		for(int i=0;i<n;++i) a[i]=2,sum=(sum+2*pw[i])%MOD;
		while(1){
			if(a[n]>0){
				puts("-1");
				break;
			}
/*			if(a[0]==3&&a[1]==2){
				puts("A");
				printf("[%d]",sum);
			}
*/
	//		printf("<%d>\n",sum);
			if(check()){
				for(int i=n-1;i>=0;--i)
					printf("%d",a[i]);
				puts("");
				break;
			}
			add(a,n);
		}
	}
	return 0;
}