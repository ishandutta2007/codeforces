#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
const ld PI=acosl(-1),EPS=1e-14;
template<class T> int sn(const T& x){ return x<-EPS?-1:(x>EPS?1:0); }
template<class T> T normal(T x){ 
	x-=int(x/(2*PI))*(2*PI);
	while(x>=2*PI) x-=2*PI;
	while(x<0) x+=2*PI;
	return x;
}
template<class T> struct P{
	T x,y;
	P(T _x=T(),T _y=T()){x=_x,y=_y; }
	T dis2()const { return x*x+y*y; }
	T dis()const { return sqrtl(dis2()); }
	T cp(const P<T>& b)const{ return x*b.y-y*b.x; }
	T dot(const P<T>& b)const{ return x*b.x+y*b.y; }
	int qua()const { return sn(y)>=0?(sn(x)>=0?1:2):(sn(x)>=0?4:3); }
	ld angle()const{ return atan2(y,x); }
	P<T> operator!(){ return P<T>(x,-y); }
	P<T> operator+(const P<T>& b)const{ return P<T>(x+b.x,y+b.y); }
	P<T> operator-(const P<T>& b)const{ return P<T>(x-b.x,y-b.y); }
	P<T> operator*(const P<T>& b)const{ return P<T>(x*b.x-y*b.y,x*b.y+y*b.x); }
	P<T> operator/(const T& t)const{ return P<T>(x/t,y/t); }
	P<T> div2(const P<T>& b)const{ return (*this)*(!b); }
	P<T> operator/(const P<T>& b)const{ div2(b)/b.dis2(); }
	P<T> rot90()const{ return P<T>(-y,x); }
	P<T> rot(const ld& t)const{ return (*this)*P<T>(cosl(t),sinl(t)); }
	P<T> splay(const T& d)const{ return (*this)/dis()*d; }
};
template<class T>istream& operator>>(istream& s,P<T>& a){return s>>a.x>>a.y;}
template<class T>ostream& operator<<(ostream& s,P<T> a)
{return s<<"("<<a.x<<","<<a.y<<")";}
template<class T>struct Line{
	P<T> s,t;
	Line(P<T> _s=P<T>(),P<T> _t=P<T>()){ s=_s,t=_t; }
	P<T> v(){ return t-s; }
	int in(const P<T>& x){ return sn(v().cp(x-s)); }
	P<T> proj(const P<T>& x){ return s+v()*(x-s).dot(v())/v().dis2();  }
	ld dis(const P<T>& x){ return (proj(x)-x).dis(); }
};
template<class T>istream& operator>>(istream& s,Line<T>& a)
{return s>>a.s>>a.t; }
template<class T>ostream& operator<<(ostream& s,Line<T> a)
{return s<<"["<<a.s<<a.t<<"]"; }
template<class T>Line<T> getPL(P<T> a,P<T> b){
	P<T> x=(a+b)/2;
	return Line<T>(x,x+(b-a).rot90());
}
template<class T>bool para(P<T> a,P<T> b){ return sn(a.cp(b))==0; }
template<class T>bool same_dir(P<T> a,P<T> b){ 
	return para(a,b)&&sn(a.dot(b))>0; 
}
template<class T>bool para(Line<T> a,Line<T> b){ return para(a.v(),b.v()); }
template<class T>bool same_dir(Line<T> a,Line<T> b){
	return same_dir(a.v(),b.v());
}
template<class T>P<T> getIP_1(Line<T> a,Line<T> b){
	T w1=(b.s-a.s).cp(a.t-a.s),w2=(a.t-a.s).cp(b.t-a.s);
	return (b.s*w2+b.t*w1)/(w1+w2);
}
template<class T>vector<P<T> > getIP(Line<T> a,Line<T> b){
	if(para(a,b)) return {};
	return {getIP_1(a,b)};
}
const int N=5+1e5;
vector<Line<ld> > a;
vector<ld> dis,ang;
struct K{
	ld l,r;
	int rkl,rkr;
	Line<ld> d;
};
vector<K> f;
struct DCZ{ 
	ld x; int id,type;
	bool operator<(DCZ b){ return x<b.x; }
};
vector<DCZ> key;
pair<int,ld> operator+(pair<int,ld> x,pair<int,ld> y){ 
	return make_pair(x.first+y.first,x.second+y.second);
}
bool cmp1(K x,K y){ return x.r<y.r; }
void init(ld r){
	f.clear(); key.clear();
	for(int i=0;i<a.size();++i){
		if(sn(dis[i]-r)>=0) continue;
		ld d=acosl(dis[i]/r);
		K k=(K){normal(ang[i]-d),normal(ang[i]+d),0,0,a[i]};
		if(k.l>k.r) swap(k.l,k.r);
		f.push_back(k);
	}
	sort(f.begin(),f.end(),cmp1);
	for(int i=0;i<f.size();++i){ 
		key.push_back((DCZ){f[i].l,i,0});
		key.push_back((DCZ){f[i].r,i,1});
	}
	sort(key.begin(),key.end());
//	int cnt=0;
	for(int i=0;i<key.size();++i){
//		if(i>0&&sn(key[i].x-key[i-1].x)>0) ++cnt;
		if(key[i].type==0) f[key[i].id].rkl=i;
		else f[key[i].id].rkr=i;
	}
}
struct BIT1{
	vector<int> c;
	void init(int n){c=vector<int>(n+1,0);}
	void add(int x,int key){
		for(;x<c.size();x+=x&-x) c[x]+=key;
	}
	int query(int x){
		int ret=0;
		for(;x;x-=x&-x) ret+=c[x];
		return ret;
	}
}bit;
struct BIT2{
	vector<multiset<int> > c;
	void init(int n){c.clear(); c.resize(n+1); }
	void add(int x,int k){
		for(;x<c.size();x+=x&-x) c[x].insert(k);
	}
	void erase(int x,int k){
		for(;x<c.size();x+=x&-x) c[x].erase(c[x].find(k));
	}
	pair<int,ld> query(int x,Line<ld> l){
		pair<int,ld> ret(0,0);
		for(;x;x-=x&-x){
			ret.first+=c[x].size();
			for(auto y:c[x])
				ret.second+=getIP_1(f[y].d,l).dis();
		}
		return ret;
	}
}bit2;
bool check(ld r,int m){
	init(r);
	bit.init(key.size());
	int sum=0;
	for(int i=0;i<key.size();++i){
		int p=key[i].id;
		if(key[i].type==1){
			bit.add((int)key.size()-f[p].rkl,-1);
			sum+=bit.query((int)key.size()-f[p].rkl);
			if(sum>=m) return false;
		}else{
			bit.add((int)key.size()-f[p].rkl,1);
		}
	}
	return sum<m;
}
pair<int,ld> calc(ld r){
	init(r);
	bit2.init(key.size());
	pair<int,ld> ret(0,0);
	for(int i=0;i<key.size();++i){
		int p=key[i].id;
		if(key[i].type==1){
			bit2.erase((int)key.size()-f[p].rkl,p);
			ret=ret+bit2.query((int)key.size()-f[p].rkl,f[p].d);
		}else{
			bit2.add((int)key.size()-f[p].rkl,p);
		}
	}
//	cout<<ret.first<<" "<<ret.second;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	P<ld> x; int n,m; cin>>n>>x>>m;
	a.resize(n); dis.resize(n); ang.resize(n);
	x=x/1000;
	for(int i=0;i<n;++i){
		ld c,d; cin>>c>>d; c/=1000; d/=1000;
		a[i]=Line<ld>(P<ld>(0-x.x,d-x.y),P<ld>(1-x.x,c+d-x.y));
//		cout<<a[i]<<endl;
		P<ld> k=a[i].proj(P<ld>(0,0));
		if(sn(k.x)==0&&sn(k.y)==0){
			dis[i]=0;
			ang[i]=(a[i].v().rot90()).angle();
		}else{
			ang[i]=k.angle();
			dis[i]=k.dis();
		}
//		printf("<%.10Lf %.10Lf>",ang[i],dis[i]);
	}
//	exit(0);
	ld left=0,right=2e12;
	while(fabs(right-left)/max(left,(ld)1.0)>1e-7){
		ld mid=(left+right)/2;
		if(check(mid,m)) left=mid;
		else right=mid;
	}
//	printf("[%.10Lf %d]",left,check(left,m));
	pair<int,ld> ret=calc(left);
	ld ans=(ret.second+(m-ret.first)*left);
	printf("%.10Lf\n",ans);
	return 0;
}