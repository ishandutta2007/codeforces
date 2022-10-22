#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define double ld
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
struct point {
	int x,y,id;
};
const double EPS = 1e-15;
const double PI = acosl(-1);
const point origin = {0,0,-1};
bool up (const point &p) {
  return p.y > 0 || (p.y == 0 && p.x >= 0);
}
double angle (const point &a, const point &b) {
	double a1 = atan2l(a.y,a.x), a2 = atan2l(b.y,b.x);
	if (a1 > a2) swap(a1,a2);
	double ret = a2-a1;
	return min(ret,2*PI-ret);
}
int main () { //tan > cos?
	int n;
	scanf ("%d",&n);
	vector<point> v(n);
	int cid = 0;
	for (auto &au : v) scanf ("%d %d",&au.x,&au.y), au.id = ++cid;
	sort(v.begin(), v.end(), [] (point a, point b) {return up(a) == up(b) ? a.x * b.y > a.y * b.x : up(a) < up(b);});	
	//reverse(all(v));
	double mn = 12; int a=-1,b=-1;
	for (int i = 0; i < n; i++) {
		double att = angle(v[i],v[(i+1)%n]);
		if (att < mn) {
			mn = att;
			a = v[i].id;
			b = v[(i+1)%n].id;
		}
	}
	printf ("%d %d\n",a,b);
	return 0;
}