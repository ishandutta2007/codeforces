#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
struct poin{
	double x,y;
	poin(double xx=0,double yy=0):x(xx),y(yy){}
	inline poin operator +(const poin &a)const{
		return poin(x+a.x,y+a.y);
	}
	inline poin operator -(const poin &a)const{
		return poin(x-a.x,y-a.y);
	}
	inline poin operator *(const double a)const{
		return poin(x*a,y*a);
	}
	inline poin operator /(const double a)const{
		return poin(x/a,y/a);
	}
	inline double operator *(const poin &a)const{
		return x*a.y-y*a.x;
	}
	inline double operator ^(const poin &a)const{
		return x*a.x+y*a.y;
	}
}ori; 
const double eps=1e-8,pi=acos(-1.0);
inline int cmp(double x){
	if(fabs(x)<eps)return 0;
	return (x<0)?-1:1;
}
inline double distan(poin a){
	return sqrt(a.x*a.x+a.y*a.y);
}
inline bool operator <(poin a,poin b){
	a=a-ori;b=b-ori;
	double x=atan2(a.y,a.x),y=atan2(b.y,b.x);
	return !cmp(x-y)?distan(a)<distan(b):x<y;
} 
#define iter set<poin>::iterator
set<poin>s;
iter pre(iter it){
	if(it==s.begin())it=s.end();
	return --it;
}
iter nxt(iter it){
	++it;
	if(it==s.end())it=s.begin();
	return it;
}
inline bool query(poin a){
	iter it=s.lower_bound(a);
	if(it==s.end())it=s.begin();
	return cmp(((*it)-(*pre(it)))*(a-(*pre(it))))>-1;
}
inline void insert(poin a){
	if(query(a))return;
	s.insert(a);
	iter it=nxt(s.find(a));
	while(s.size()>3&&cmp(((*nxt(it))-a)*((*it)-a))>-1){s.erase(it);it=nxt(s.find(a));}
	it=pre(s.find(a));
	while(s.size()>3&&cmp(((*it)-a)*((*pre(it))-a))>-1){s.erase(it);it=pre(s.find(a));}
}
poin tmp[4];
int main(){
	int Q=read()-3,op,x,y;
	for(int i=1;i<=3;i++){
		op=read();tmp[i].x=read();tmp[i].y=read();
		ori=ori+tmp[i];
	} 
	ori=ori/3;
	for(int i=1;i<=3;i++)s.insert(tmp[i]);
	while(Q--){
		op=read();x=read();y=read();
		if(op==1)insert(poin(x,y));
		else puts(query(poin(x,y))?"YES":"NO");
	}
	return (0-0);
}