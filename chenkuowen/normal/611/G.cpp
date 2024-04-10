#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld EPS=1e-10,PI=acos(-1);
template<class T> int sn(T x) { return x<-EPS?-1:(x>EPS); }
template<class T> struct P{ //represent a point, a vector, or a complex
	T x,y;
	P(T _x=T(),T _y=T()){ x=_x,y=_y; }
	inline P<T> operator!()const { return P<T>(x,-y); }
	inline P<T> operator+(const P<T>& b)const { return P<T>(x+b.x,y+b.y); }
	inline P<T> operator-(const P<T>& b)const { return P<T>(x-b.x,y-b.y); }
	inline P<T> operator*(const P<T>& b)const { return P<T>(x*b.x-y*b.y,x*b.y+y*b.x); }
	inline P<T> operator*(const T& t)const{ return P<T>(x*t,y*t); }
    inline P<T> operator/(const T& t)const { return P<T>(x/t,y/t); }
	inline P<T> div2(const P<T>& b) const { return (*this)*(!b); }
	inline P<T> operator/(const P<T>& b)const { return div2(b)/b.dis2(); }
	inline T dis2()const { return x*x+y*y; }
	inline T dis()const { return sqrtl(dis2()); }
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
const int MOD=1e9+7;
inline void mo(int& x){x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int main(){
	vector<P<ll> > a;
	int n; scanf("%d",&n);
	a.resize(n);
	for(int i=0;i<n;++i) cin>>a[i];
	reverse(a.begin(),a.end());
	ll ss=0;
	for(int i=0;i+1<n;++i)
		ss+=(a[i]-a[0]).cp(a[i+1]-a[0]);
//	printf("[%lld]",ss);
	int sumx=0,sumy=0,c=0,poi=0,ans=0,cnt=0;
	int sumx2=0,sumy2=0,c2=0;
	ll s0=0;
	for(int i=0;i<n;++i){
		if(poi==i-1){
//			cerr<<"A"<<endl;
			poi=i,cnt=0;
			sumx=sumy=c=0;
			sumx2=sumy2=c2=0;
		}
		ll s1;
		while((s1=s0+(a[poi]-a[i]).cp(a[(poi+1)%n]-a[i]))<=ss/2){
//			printf("<%lld %lld %lld %lld %d %d>",s0,s1-s0,s1,ss/2,i,poi);
			s0=s1;
			P<ll> k=a[poi]-a[(poi+1)%n];
			sumx=(sumx+k.y%MOD)%MOD;
			sumy=(sumy-k.x%MOD)%MOD;
			c=(c+k.x%MOD*a[(poi+1)%n].y%MOD-k.y%MOD*a[(poi+1)%n].x%MOD)%MOD;
			sumx2=(sumx2+sumx)%MOD;
			sumy2=(sumy2+sumy)%MOD;
			c2=(c2+c)%MOD;
			poi=(poi+1)%n; ++cnt;
		}
//		printf("[%d %d %lld %lld %lld]",i,poi,s0,s1,ss);
		ll s2=sumx2*a[i].x+sumy2*a[i].y+c2;
	//	printf("{%lld}\n",s2);
		ans=(ans+ss%MOD*(cnt-1)-s2%MOD*2)%MOD;
		if(poi!=i){
			ll s3=(a[(i+1)%n]-a[i]).cp(a[poi]-a[i]);
//			printf("[%lld %lld %lld]",s0,s3,s0-s3);
			s0-=s3;

		P<ll> k=a[i]-a[(i+1)%n];
		sumx2=(sumx2-k.y%MOD*(cnt))%MOD;
		sumy2=(sumy2+k.x%MOD*(cnt))%MOD;
		c2=(c2-(k.x%MOD*a[(i+1)%n].y-k.y%MOD*a[(i+1)%n].x)%MOD*cnt)%MOD;
		sumx=(sumx-k.y%MOD)%MOD;
		sumy=(sumy+k.x%MOD)%MOD;
		c=(c-k.x%MOD*a[(i+1)%n].y+k.y%MOD*a[(i+1)%n].x)%MOD;
		--cnt;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",ans);
	return 0;	
}