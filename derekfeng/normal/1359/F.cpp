#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=1e-8;
int n;
db T;
struct Seg{
	db k,b,l,r;int id;
	bool operator <(Seg oth)const{
		db a=k*T+b;
		db b=oth.k*T+oth.b;
		if(fabs(a-b)>eps)return a<b;
		return id<oth.id;
	}
}a[25005];
db dx[25005],sx[25005];
vector<pair<db,int> >events;
set<Seg>st;
bool cross(Seg A,Seg B){
	if(fabs(A.k-B.k)<eps)
		return fabs(A.b-B.b)<eps&&A.r+eps>B.l-eps&&A.l-eps<B.r+eps;
	db p=(A.b-B.b)/(B.k-A.k);
	return A.l-eps<p&&p<A.r+eps&&B.l-eps<p&&p<B.r+eps;
}
bool check(db t){
	events.clear();
	for(int i=1;i<=n;i++){
		a[i].l=sx[i],a[i].r=sx[i]+t*dx[i],a[i].id=i;
		if(a[i].l>a[i].r)swap(a[i].l,a[i].r);
		events.push_back({a[i].l,-i});
		events.push_back({a[i].r,i});
	}
	sort(events.begin(),events.end());
	st.clear();
	for(auto [juruo,I]:events){
		T=juruo;
		int i=abs(I);
		if(I<0){
			Seg d=a[i];
			auto it=st.lower_bound(d),it1=it;
			if(it!=st.end()&&cross(d,*it))return 1;
			if(it!=st.begin()&&cross(d,*--it1))return 1;
			st.insert(d);
		}else{
			Seg d=a[i],A,B;
			bool fa=0,fb=0;
			auto it=st.find(d),it1=it,it2=it;
			if(it!=st.begin())fa=1,A=*--it1;
			if(it!=--st.end())fb=1,B=*++it2;
			if(fa&&fb&&cross(A,B))return 1;
			st.erase(it);
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		db x,y,xd,yd,s;
		scanf("%lf%lf%lf%lf%lf",&x,&y,&xd,&yd,&s);
		a[i].k=yd/xd,a[i].b=y-a[i].k*x;
		sx[i]=x,dx[i]=s/sqrt(xd*xd+yd*yd)*xd;
	}
	db l=0,r=1e12;
	for(int t=0;t<80;t++){
		db m=(l+r)*0.5;
		if(check(m))r=m;
		else l=m;
	}
	if(r>1e11)puts("No show :(");
	else printf("%.12lf",r);
}