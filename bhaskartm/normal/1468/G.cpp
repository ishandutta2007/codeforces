#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'






#define T long double
#define EPS 1e-9

struct PT{
	T x, y;
	PT() {}
	PT(T x, T y) : x(x), y(y) {}
	PT(const PT& p) : x(p.x), y(p.y) {}
	bool operator < (const PT& rhs) const{
		return make_pair(y, x) < make_pair(rhs.y, rhs.x);
	}
	bool operator == (const PT& rhs) const{
		return make_pair(y, x) == make_pair(rhs.y, rhs.x);
	}
	PT operator + (const PT& p) const{
		return PT(x+p.x, y+p.y);
	}
	PT operator - (const PT& p) const{
		return PT(x-p.x, y-p.y);
	}
	PT operator * (T c) const {
		return PT(x*c, y*c);
	}
	PT operator / (T c) const {
		return PT(x/c, y/c);
	}
};

T cross(PT p, PT q){
	return p.x*q.y-p.y*q.x;
}

T area2(PT a, PT b, PT c){
	return cross(a, b)+cross(b, c)+cross(c, a);
}

T dot(PT p, PT q){
	return p.x*q.x+p.y*q.y;
}

T dist2(PT p, PT q){
	return dot(p-q, p-q);
}

bool between(const PT& a, const PT& b, const PT& c){
	return (fabs(area2(a, b, c))<EPS && (a.x-b.x)*(c.x-b.x)<=0 && (a.y-b.y)*(c.y-b.y)<=0);
}

void Con(vector<PT>& pts){
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	vector<PT> up, dn;
	for(int i=0; i<pts.size(); i++){
		while(up.size()>1 && area2(up[up.size()-2], up.back(), pts[i])>=0){
			up.pop_back();
		}
		while(dn.size()>1 && area2(dn[dn.size()-2], dn.back(), pts[i])<=0){
			dn.pop_back();
		}
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts=dn;
	for(int i=up.size()-2; i>=1; i--){
		pts.push_back(up[i]);
	}
	if(pts.size()<=2){
		return;
	}
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for(int i=2; i<pts.size(); i++){
		if(between(dn[dn.size()-2], dn[dn.size()-1], pts[i])){
			dn.pop_back();
		}
		dn.push_back(pts[i]);
	}
	if(dn.size()>=3 && between(dn.back(), dn[0], dn[1])){
		dn[0]=dn.back();
		dn.pop_back();
	}
	pts=dn;
}

int LP(PT a, PT b, PT c, PT d){
	return fabs(cross(b-a, c-d))<EPS;
}

int LC(PT a, PT b, PT c, PT d){
	return LP(a, b, c, d) && fabs(cross(a-b, a-c)) < EPS && fabs(cross(c-d, c-a))<EPS;
}


int seg(PT a, PT b, PT c, PT d){
	if(LC(a, b, c, d)){
		if(dist2(a, c)<EPS || dist2(a, d)<EPS || dist2(b, c)<EPS || dist2(b, d)<EPS){
			return 1;
		}
		if(dot(c-a, c-b)>0 && dot(d-a, d-b)>0 && dot(c-b, d-b)>0){
			return 0;
		}
		return 1;
	}
	if(cross(d-a, b-a)*cross(c-a, b-a)>0){
		return 0;
	}
	if(cross(a-c, d-c)*cross(b-c, d-c)>0){
		return 0;
	}
	return 1;
}

PT lin(PT a, PT b, PT c, PT d){
	b=b-a;
	d=c-d;
	c=c-a;
	return a + b*cross(c, d)/cross(b, d);
}




main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, h;
	cin>>n>>h;
	int x[n];
	int y[n];
	for(int i=0; i<n; i++){
		cin>>x[i]>>y[i];
	}
	bool val[n];
	for(int i=0; i<n; i++){
		val[i]=0;
	}
	val[n-1]=1;
	val[n-2]=1;
	int xx=x[n-1];
	int yy=y[n-1]+h;
	
	T ang=((yy-y[n-2])*(1.0))/(xx-x[n-2]);
	for(int i=n-3; i>=0; i--){
		T ang2=((yy-y[i])*(1.0))/(xx-x[i]);
		if(ang2<=ang+EPS){
			val[i]=1;
			ang=ang2;
		}
	}
	
	vector<int>v;
	for(int i=0; i<n; i++){
		if(val[i]){
			v.pb(i);
		}
	}
	
	T ans=0;
	for(int i=0; i<v.size()-1; i++){
		PT a(xx, yy);
		PT b(x[v[i+1]], y[v[i+1]]);
		PT c(x[v[i]], y[v[i]]);
		PT d(x[v[i]+1], y[v[i]+1]);
		if(LC(a, b, c, d)){
			ans+=sqrt(dist2(c, d));
			continue;
		}
		PT ne=lin(a, b, c, d);
		ans+=(sqrt(dist2(c, ne)));
	}
	cout<<setprecision(20)<<ans;
	
	return 0;
}