#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
const db EPS=1e-10,PI=acos(-1);
template<class T> int sn(T x){ return x<-EPS?-1:(x>EPS); }
template<class T> struct P{
	T x,y;
	P(T _x=T(),T _y=T()){ x=_x,y=_y; }
	P<T> operator!()const { return P<T>(x,-y); }
	P<T> operator+(P<T> b)const { return P<T>(x+b.x,y+b.y); }
	P<T> operator-(P<T> b)const { return P<T>(x-b.x,y-b.y); }
	P<T> operator*(P<T> b)const { return P<T>(x*b.x-y*b.y,x*b.y+y*b.x); }
	P<T> operator/(T t)const { return P<T>(x/t,y/t); }
	P<T> div2(P<T> b)const { return (*this)*(!b); }
	P<T> operator/(P<T> b)const { return div2(b)/b.dis2(); }
	T dis()const { return sqrt(x*x+y*y); }
	T dis2()const { return x*x+y*y; }
	T dot(P<T> b)const { return x*b.x+y*b.y; }
	T cp(P<T> b)const { return x*b.y-y*b.x; }
	P<T> rot90()const { return P<T>(-y,x); }
	P<T> rot(db s)const { return (*this)*(cos(s),sin(s)); }
	int qua()const { return sn(y)>=0?(sn(x)>=0?1:2):(sn(x)>=0?4:3); }
};
template<class T>struct Cmp{
	bool operator()(P<T> a,P<T> b){
		return a.x<b.x||(a.x==b.x&&a.y<b.y); 
	}
};
struct ConvexHull{
	multiset<P<ll>,Cmp<ll> > a,b;
	bool check(P<ll> x,P<ll> y,P<ll> z,int s){
		return sn((z-x).cp(y-x))!=s; 
	}
	void insert(multiset<P<ll>,Cmp<ll> >& a,P<ll> x,int s){
		auto it=a.insert(x);
		if(it!=a.begin()&&next(it)!=a.end()){
			auto it1=prev(it),it2=next(it);
			if(check(*it1,*it,*it2,s)){
				a.erase(it);
				return;
			}
		}
		while(1){
			if(it==a.begin()) break;
			auto it1=prev(it);
			if(it1==a.begin()) break;
			auto it2=prev(it1);
			if(check(*it2,*it1,*it,s))
				a.erase(it1);
			else 
				break;
		}
		while(1){
			auto it1=next(it);
			if(it1==a.end()) break;
			auto it2=next(it1);
			if(it2==a.end()) break;
			if(check(*it,*it1,*it2,s))
				a.erase(it1);
			else 
				break;
		}
	}
	void insert(P<ll> x){
		insert(a,x,1);
		insert(b,x,-1);
/*		for(auto x:a) printf("(%lld %lld)",x.x,x.y); puts("");
		for(auto x:b) printf("(%lld %lld)",x.x,x.y); puts("");
		puts("----------------");
*/	}
	bool query(multiset<P<ll>,Cmp<ll> >& a,P<ll> x,int s){
		auto it=a.lower_bound(x);
		if(it==a.end()) return false;
		if(x.x==it->x&&x.y==it->y) return true;
		if(it==a.begin()) return false;
		auto it1=prev(it);
		int ret=sn(((*it)-(*it1)).cp(x-(*it1)));
//		printf("[%d %lld %lld]",ret,it1->x,it1->y);
		return ret!=s;
	}
	bool query(P<ll> x){ return query(a,x,1)&&query(b,x,-1); }
}s;
int main(){
	int q; scanf("%d",&q);
	while(q--){
		int opt; P<ll> x; scanf("%d%lld%lld",&opt,&x.x,&x.y);
		if(opt==1) s.insert(x);
		else puts(s.query(x)?"YES":"NO");
	}
	return 0;
}