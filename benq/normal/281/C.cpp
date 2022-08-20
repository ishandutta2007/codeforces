#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> point;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	double w,h,a; cin >> w >> h >> a;
	
	a = min(a,180-a);
	point p1; p1.real(w/2); p1.imag(-h/2);
	p1 *= polar(1.0,PI/180*a);
	double a1 = p1.real()-double(w)/2;
	
	point p2; p2.real(w/2); p2.imag(h/2);
	p2 *= polar(1.0,PI/180*a);
	double a2 = p2.imag()-double(h)/2;
	
	cout << fixed << setprecision(9);
	if (a == 0) {
		cout << w*h;
		return 0;
	}
	if (a == 90) {
		cout << min(w,h)*min(w,h);
		return 0;
	}
	if (a1 >= 0 && a2 >= 0) {
		double ans = w*h;
		//cout << ans << " " << a1 << " " << a2 << "\n";
		ans -= a2*a2*(tan(PI/180*a)+1/tan(PI/180*a));
		//cout << ans << "\n";
		ans -= a1*a1*(tan(PI/180*a)+1/tan(PI/180*a));
		cout << ans;
	} else {
		cout << min(w,h)*min(w,h)/sin(PI/180*a);
	}
}