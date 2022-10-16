#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int n, w, v, u;
	cin >> n >> w >> v >> u;
	double mn = 1e18, mx = 0, start;
	for(int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		double cur = x / v - y / u;
		mn = min(mn, cur);
		mx = max(mx, cur);
	}
	if(mn >= -1e-12) start = 0;
	else start = mx;
	cout << fixed << setprecision(10) << start + (double) w / u << endl;
}