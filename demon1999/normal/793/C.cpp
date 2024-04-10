#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int ma = 1024 * 1024 * 2;

int n;
int xa, ya, xb, yb;
int rx, ry, vx, vy;

void solve(double xl, double xr, double x, double v, double &l, double &r) {
	if (x > xl && x < xr) {
		l = 0;
		if (v == 0) {
			r = double(1e9);
			re;
		}
		if (v < 0) {
			r = (xl - x) / v;
		} else
			r = (xr - x) / v;
	} else {
		if (x <= xl && v <= 0) {
			l = 0;
			r = -1;
			re;
		}
		if (x >= xr && v >= 0) {
			l = 0;
			r = -1;
			re;
		}
		if (v < 0) {
			l = (xr - x) / v + 1e-11;
			r = (xl - x) / v - 1e-11;
		} else {
			l = (xl - x) / v + 1e-11;
			r = (xr - x) / v - 1e-11;
		}
	}
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d%d%d%d", &n, &xa, &ya, &xb, &yb);
	if (xa == xb || ya == yb) {
		cout << "-1";
		re 0;
	} 
	double ltm = 0, rtm = double(1e9);
	forn (i, n) {
		scanf("%d%d%d%d", &rx, &ry, &vx, &vy);
		double la, ra, lb, rb;
		solve(xa, xb, rx, vx, la, ra);
		solve(ya, yb, ry, vy, lb, rb);
		ltm = max(ltm, la);
		rtm = min(rtm, ra);
		ltm = max(ltm, lb);
		rtm = min(rtm, rb);
		//cout << la << " " << ra << " " << lb << " " << rb << "\n";
	}
	if (rtm - ltm < double(1e-11)) {
		cout << "-1";
		re 0;
	}
	cout.precision(30);
	cout << min(ltm, rtm) + double(1e-11);
	re 0;
}