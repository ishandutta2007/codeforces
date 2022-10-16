#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7;

const double eps = 1e-10;

double go(double c, double p, double v) {
	double ans = 0;
	ans += 1;
	if(c <= v + eps) ans += c;
	else ans += c * go(c - v, p + v, v);
	return ans;
}

double go(double c, double m, double p, double v) {
	double ans = 0;
	ans += 1;
	if(c <= v + eps) {
		ans += c * go(m + c / 2, p + c / 2, v);
	} else {
		ans += c * go(c - v, m + v / 2, p + v / 2, v);
	}
	if(m <= v + eps) {
		ans += m * go(c + m / 2, p + m / 2, v);
	} else {
		ans += m * go(c + v / 2, m - v, p + v / 2, v);
	}
	return ans;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		double c, m, p, v;
		cin >> c >> m >> p >> v;
		cout << fixed << setprecision(10) << go(c, m, p, v) << '\n';
	}
	
}