#include <bits/stdc++.h>
#define fi first
#define se second;
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

const ld EPS = 1e-12;
struct pt { 
	ld x, y; 
	pt(){}
	pt(ld x, ld y) : x(x), y(y) {}
	pt operator + (const pt &p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt &p) const { return pt(x-p.x, y-p.y); }
	pt operator * (ld c) const { return pt(x*c, y*c); }
	pt operator / (ld c) const { return pt(x/c, y/c); }
	bool operator == (const pt &p) const { return fabsl(x-p.x)+fabsl(y-p.y) < EPS; }
	bool operator < (const pt &p) const { return (x==p.x)?y<p.y:x<p.x; }
};

const int N = 1e5+5;
pt v[N],tgt;
vector<pt> imp;
ld scale_point(const pt& p) {
	return max(tgt.x/p.x,tgt.y/p.y);
}

ld cross(pt p, pt q)   { return p.x*q.y-p.y*q.x; }
ld mag(pt p)   { return sqrtl(p.x*p.x+p.y*p.y); }

bool intersectSL(pt a, pt b, pt c, pt d){
	return cross(a-c,a-d) * cross(b-c,b-d) <=0;
}

pt intersectLL(pt a, pt b, pt c, pt d) {
  return a + (b-a)*(cross(c-a, c-d))/(cross(b-a, c-d));
}

bool ccw(pt a, pt b, pt c) {
	return cross(b-a,c-b) >= 0;
}

int main() {
	// ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n >> tgt.x >> tgt.y;
	// scanf("%d%Lf%Lf",&n,&tgt.x,&tgt.y);
	ld ans = 1e200;
	for(int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y;
		ans = min(ans,scale_point(v[i]));
	}
	sort(v,v+n);
	imp.push_back(v[0]);
	for(int i = 1; i < n; ++i) {
		while(imp.size() > 1 && ccw(imp[imp.size()-2],imp[imp.size()-1],v[i]))
			imp.pop_back();
		imp.push_back(v[i]);
	}

	pt C(0,0);
	pt D(tgt.x,tgt.y);
	for(int i = 1; i < imp.size(); ++i) {
		if(intersectSL(imp[i-1],imp[i],C,D)) {
			pt p = intersectLL(imp[i-1],imp[i],C,D);
			ans = min(ans,mag(D)/mag(p));
		}
	}
	cout << setprecision(12) << fixed << ans << "\n";
	return 0;
}