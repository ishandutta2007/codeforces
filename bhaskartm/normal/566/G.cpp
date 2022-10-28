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
const int N=1e6;
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
	if(pts.size()==1){
		return;
	}
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	if(pts.size()==1){
		return;
	}
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
		return ;
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

int cro(int a, int b, int c, int d){
	return a*d-b*c;
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int x, y;
	cin>>x>>y;
	vector<pair<int, int>>maxi;
	vector<PT>mini;
	for(int i=0; i<n; i++){
		int a, b;
		cin>>a>>b;
		maxi.pb({a, b});
	}
	for(int i=0; i<m; i++){
		int c, d;
		cin>>c>>d;
		mini.pb(PT(c, d));
	}
	
	Con(mini);
	
	vector<pair<int, int>>mini2;
	for(auto u:mini){
		mini2.pb({round(u.x), round(u.y)});
	}
	int maxim=-1;
	int ind=-1;
	for(int i=0; i<mini2.size(); i++){
		if(mini2[i].f>maxim){
			maxim=mini2[i].f;
			ind=i;
		}
	}
	vector<pair<int, int>>fin;
	int pt=ind;
	int las=-1;
	
	int mi2=mini2.size();
	while(1){
		
		if(mini2[pt].s>las){
			fin.pb(mini2[pt]);
			las=mini2[pt].s;
			pt++;
			
			pt=pt%mi2;
		}
		else{
			break;
		}
	}
	
	int m1=0;
	int m2=0;
	for(int i=0; i<fin.size(); i++){
		m1=max(m1, fin[i].f);
		m2=max(m2, fin[i].s);
	}
	int m3=0;
	int m4=0;
	for(int i=0; i<n; i++){
		m3=max(maxi[i].f, m3);
		m4=max(maxi[i].s, m4);
	}
	if(m1<=m3 || m2<=m4){
		cout<<"Max";
		return 0;
	}
	map<pair<int, int>, int>ma1;
	for(auto u:fin){
		ma1[u]=1;
	}
	for(auto u:maxi){
		if(ma1[u]==1){
			cout<<"Max";
			return 0;
		}
	}
	vector<pair<T, pair<int, int>>>v1;//inner
	vector<pair<T, pair<int, int>>>v2;//outer
	for(auto u:maxi){
		v1.pb({(u.s*1.0)/(u.f), {u.f, u.s}});
	}
	for(auto u:fin){
		v2.pb({(u.s*1.0)/(u.f), {u.f, u.s}});
	}
	sort(v1.begin(), v1.end());
	reverse(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end());
	pt=0;
	
	for(int i=0; i<n; i++){
		if(v1[i].f>=v2[0].f){
			continue;
		}
		if(v1[i].f<=v2.back().f){
			continue;
		}
		while(1){
			if(v2[pt+1].f>v1[i].f){
				pt++;
			}
			else{
				break;
			}
		}
		if(cro(((v1[i].s.f)-(v2[pt+1].s.f)), ((v1[i].s.s)-(v2[pt+1].s.s)), ((v2[pt].s.f)-(v2[pt+1].s.f)), ((v2[pt].s.s)-(v2[pt+1].s.s)))>=0){
			cout<<"Max";
			return 0;
		}
	}
	cout<<"Min";
	return 0;
}