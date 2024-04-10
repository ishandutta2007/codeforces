#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int ma = 128 * 1024;
const ll mod = ll(1e9) + 7;
const int N = 5 * 100 * 1000;

int n;
vector<int> e[N];
double x[N], v[N];

double ans(double xx) {
	double tm = 0;
	forn (i, n)
		tm = max(tm, abs(xx - x[i]) / v[i]);
	re tm;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, n) {
		cin >> x[i];
	}
	forn (i, n)
		cin >> v[i];
	double l = 1, r = 1000000000;
	forn (i, 100) {
		double ql = l + (r - l) / 3., qr = (ql + r) / 2.;
		if (ans(ql) < ans(qr))
			r = qr;
		else
			l = ql;
	}
	//cout << l << " " << r << "\n";
	cout.precision(10);
	cout << ans(l);
}