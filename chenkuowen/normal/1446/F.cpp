#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
/*
CH,HP/,PL,IP
TG,CTG(ICTG,ECTG)
*/
const ld EPS=1e-16,PI=acosl(-1);
template<class T> int sn(const T& x){ return x<-EPS?-1:(x>EPS); }
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
	inline ld angle()const{ return atan2(y,x); }
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
		P<T> v=a.v()*sqrtl(r*r-dis1*dis1)/a.v().dis();
		return {s+v,s-v};
	}
	vector<Line<T> > getTG(P<T> a){ 
		if(in(a)>0) return {};
		if(in(a)==0) return {(Line<T>){a,a+(x-a).rot90()}};
		ld s1=(x-a).dis(),s2=sqrtl(max((ld)0.0,s1*s1-r*r));
		P<T> p1=(x-a)*P<T>(s2/s1,r/s1),p2=(x-a)*P<T>(s2/s1,-r/s1);
		return {Line<T>{a,a+p1.splay(s2)},(Line<T>){a,a+p2.splay(s2)}};
	}
};
template<class T> istream& operator>>(istream& s,Circle<T>& a)
{return s>>a.x>>a.r; }
template<class T> ostream& operator<<(ostream& s,Circle<T>& a)
{return s<<"["<<a.x<<a.r<<"]"; }
struct BIT{
	vector<int> c;
	inline void init(int n){ c=vector<int>(n+1); }
	inline void add(int x,int key){
		for(;x<c.size();x+=x&-x) c[x]+=key;
	}
	inline int query(int x){
		int ret=0;
		for(;x;x-=x&-x)
			ret+=c[x];
		return ret;
	}
}bit;
vector<P<ld> > a;
ll k;
ld normal(ld x){
	while(x>=2*PI) x-=2*PI;
	while(x<0) x+=2*PI;
	return x;
}
bool cmp(pair<ld,int> x,pair<ld,int> y){
	if(fabs(x.first-y.first)<EPS) return x.second<y.second;
	else return x.first<y.first;
}
ll solve(ld std){
	Circle<ld> c(P<ld>(0,0),std);
	vector<P<ld> > f;
	ll cnt=0,ans=0;
	for(auto x:a){
		if(c.in(x)>=0) ++cnt;
		else f.push_back(x);  
	}
	vector<vector<int> > b(f.size(),vector<int>(2));
	ans+=cnt*((int)a.size()-1+(int)f.size())/2;
	vector<pair<ld,int> > key(f.size()*2);
	for(int i=0;i<f.size();++i){
		vector<ld> g(2);
		ld s=f[i].angle(),d=acosl(c.r/(c.x-f[i]).dis());
		g[0]=normal(s-d);
		g[1]=normal(s+d);
//		cerr<<g[0]<<" "<<g[1]<<" "<<s<<" "<<d<<endl;
		if(g[0]>g[1]) swap(g[0],g[1]);
		key[i+i]=make_pair(g[0],-(i+1));
		key[i+i+1]=make_pair(g[1],i+1);
	}
	sort(key.begin(),key.end(),cmp);
	int tp=0;
	vector<int> s;
	for(int i=0;i<key.size();++i){
		if(i==0||fabs(key[i].first-key[i-1].first)>=EPS) ++tp;
//		printf("[%.10Lf %d]",key[i].first,key[i].second);
		if(key[i].second<0){
			int x=-key[i].second-1;
			b[x][0]=tp;
		}else{
			int x=key[i].second-1;
			b[x][1]=tp;
			s.push_back(x);
		}
	}
	bit.init(tp);
//	for(int i=0;i<s.size();++i) printf("<%d %d>",b[s[i]][0],b[s[i]][1]);
	int j=0;
	for(int i=0;i<key.size();++i){
		bool type=key[i].second>0;
		int x=abs(key[i].second)-1;
		while(j<s.size()&&b[s[j]][1]<=b[x][type]){
			bit.add(b[s[j]][0],1);
			++j;
		}
	//	printf("<%d>",j);
		if(!type) ans+=j;
		else ans+=j-bit.query(b[x][0]-1)-1;
	}
	return ans;
}
int main(){
	int n; scanf("%d%lld",&n,&k);
	a.resize(n);
	for(int i=0;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		a[i]=P<ld>(x,y);
	}
//	printf("[%lld]\n",solve(0.8));

	ld left=1e-10,right=sqrtl(2)*1e4+1;
	while(right-left>2e-7){
		ld mid=(left+right)/2;
		if(solve(mid)>=k) right=mid;
		else left=mid;
	}
	printf("%.10Lf\n",right);
//	printf("<%lld>",solve(right));
	return 0;
}