#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;		
	
const ld pi = acos(-1);

void solve() {
	int n;
	scanf ("%d", &n);n *= 2;
	ld alfa = 2 * pi / n;
	ld R = sqrtl(1 / (2 * (1 - cos(alfa))));
	vector <pair<ld, ld>> vec;
	rep(i, 0, n - 1) {
		ld x = R * cos(alfa * i);
		ld y = R * sin(alfa * i);
		vec.pb({x, y});
	}
	ld ans = 0.0;
	rep(i, 2, n - 1) {
		ld x1 = vec[1].fi - vec[0].fi;
		ld y1 = vec[1].se - vec[0].se;
		ld x2 = vec[i].fi - vec[0].fi;
		ld y2 = vec[i].se - vec[0].se;
		ld pole = x1 * y2 - x2 * y1;
		ld dis = 1;
		ld h = pole / dis;
		ans = max(ans, h);
	}
	printf ("%.10Lf\n", ans);	
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
			
	return 0;
}