#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

double angle(pair<double,double> a, pair<double,double> b, pair<double,double> c) {
	a.f -= b.f, a.s -= b.s;
	c.f -= b.f, c.s -= b.s;
	return acos((a.f*c.f+a.s*c.s)/sqrt(a.f*a.f+a.s*a.s)/sqrt(c.f*c.f+c.s*c.s));
}

bool ok(double a1, double a2, double a3, int num) {
	double err = 0.0001;
	// cout << "HI " << abs(a1*num-round(a1*num)) << "\n";
	if (abs(a1*num-round(a1*num))>err) return 0;
	if (abs(a2*num-round(a2*num))>err) return 0;
	if (abs(a3*num-round(a3*num))>err) return 0;
	return 1;
}

double area(double radius, int s) {
	return radius*radius*sin(2*PI/s)/2*s;
}

double dist(pair<double,double> a, pair<double,double> b) {
	b.f -= a.f, b.s -= a.s;
	return sqrt(b.f*b.f+b.s*b.s);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	pair<double,double> a,b,c; 
	cin >> a.f >> a.s >> b.f >> b.s >> c.f >> c.s;
	
	double a1 = angle(b,a,c), b1 = angle(a,b,c), c1 = angle(a,c,b);
	double a2 = a1/PI, b2 = b1/PI, c2 = c1/PI;
	
	double R = dist(b,c)/2/sin(a1);
	FOR(i,3,101) {
		if (ok(a2,b2,c2,i)) {
			// cout << i << "\n";
			cout << fixed << setprecision(9) << area(R,i);
			return 0;
		}
	}
}