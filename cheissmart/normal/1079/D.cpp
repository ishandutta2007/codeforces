#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)
#define int long long 
typedef long double ld;
#define double ld

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

double d( double x1, double y1, double x2, double y2) {
	return sqrtl(powl(x1-x2, 2) + powl(y1-y2, 2));
}

signed main()
{
	IO_OP;
	int a, b, c, x1, y1, x2, y2;
	cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
	double ans = (abs(x1-x2)+abs(y1-y2));
	if(!(a && b)) {
		cout << fixed << setprecision(30) << ans << endl;
		return 0;
	}
	double y1L = -1.0*(a*x1+c)/b, x1L = -1.0*(b*y1+c)/a;
	double y2L = -1.0*(a*x2+c)/b, x2L = -1.0*(b*y2+c)/a;
	vector<pair<double, double>> v1, v2;
	v1.PB({x1, y1L});
	v1.PB({x1L, y1});
	v2.PB({x2, y2L});
	v2.PB({x2L, y2});
	for(auto fp:v1) {
		for(auto sp:v2) {
			ans = min(ans, abs(fp.F-x1)+abs(fp.S-y1)+ abs(x2-sp.F)+abs( y2- sp.S) + d(fp.F, fp.S, sp.F, sp.S)); 
		}
	}
	cout << fixed << setprecision(30) << ans << endl;
}