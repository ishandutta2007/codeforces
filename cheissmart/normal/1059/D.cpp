#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl;
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 100005;
const double eps = 1e-8;

struct Point{
	int x, y;
} a[N];

int n, mxy = -INF;

bool ok(double ra) {
	if(ra * 2 < mxy) return false;
	double mxl = -INF, mnr = INF;
	for(int i = 0; i < n; i++) {
	    double d = sqrtl(a[i].y) * sqrtl(2 * ra - a[i].y);
		double l = a[i].x - d, r = a[i].x + d;
		mxl = max(mxl, l);
		mnr = min(mnr, r);
	}
	return mxl <= mnr;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	bool neg = false, pos = false;
	for(int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		if(a[i].y < 0) neg = true;
		else pos = true;
	}
	if(pos && neg) {
		cout << -1 << endl;
		return 0;
	}
	if(neg) for(int i = 0; i < n; i++) a[i].y *= -1;
	for(int i = 0; i < n; i++) mxy = max(mxy, a[i].y);
	double l = 0, r = 1e15;
	for(int i = 0; i < 200; i++) {
		double m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m;
	}
	cout << fixed << setprecision(15) << l << endl;
}