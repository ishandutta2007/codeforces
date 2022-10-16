#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
// #define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int N = 25005;
const double INF = 1e18;
const double eps = 1e-8;

int x[N], y[N], dx[N], dy[N], sp[N];

pair<double, double> solve(double a1, double b1, double c1, double a2, double b2, double c2) {
	double y = (c1 * a2 - c2 * a1) / (b1 * a2 - b2 * a1);
	double x = (c1 * b2 - c2 * b1) / (b2 * a1 - b1 * a2);
	return {x, y};
}

double len(int i) {
	return sqrtl(dx[i] * dx[i] + dy[i] * dy[i]);
}

double dist(int i, int j) {
	int sa = x[i] - x[j], na = y[i] - y[j];
	return sqrtl(sa * sa + na * na);
}

signed main()
{
	IO_OP;
		int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> sp[i];
		int g = __gcd(abs(dx[i]), abs(dy[i]));
		dx[i] /= g, dy[i] /= g;
	}	
	double ans = INF;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			if(MP(dx[i], dy[i]) != MP(dx[j], dy[j]) && MP(dx[i], dy[i]) != MP(-dx[j], -dy[j])) {
				pair<double, double> ts = solve(dx[i], -dx[j], x[j] - x[i], dy[i], -dy[j], y[j] - y[i]);
				double t = ts.first, s = ts.second;
				if(s >= -eps && t >= -eps) {
					ans = min(ans, max(t * len(i) / sp[i], s * len(j) / sp[j]));
				}
			} else {
				double d = dist(i, j);
				int sa = x[i] - x[j], na = y[i] - y[j];
				if(sa * dy[i] != na * dx[i]) continue;
				if(MP(dx[i], dy[i]) == MP(dx[j], dy[j])) {
					if(sa * dx[j] + na * dy[j] < 0) {
						ans = min(ans, d / sp[i]);
					}
					if(sa * dx[j] + na * dy[j] > 0) {
						ans = min(ans, d / sp[j]);
					}
				} else {
					if(sa * dx[j] + na * dy[j] < 0) continue;
					ans = min(ans, d / (sp[i] + sp[j]));
				}
			}
		}
	}
	if(ans == INF) cout << "No show :(" << endl;
	else cout << fixed << setprecision(10) << ans << endl;
}