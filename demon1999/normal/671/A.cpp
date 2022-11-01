#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1000 * 1000 * 1000, mod = inf + 7, ma = 1024 * 128;

ld ax, ay, bx, by, tx, ty, delta[2 * ma], ans = ld(inf) * ld(inf), sum = 0.00000000;
int n;
vector<ld> x, y;

ld dist(ld x, ld y, ld xx, ld yy) {
	re sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
}

ld minn(int l, int r) {
	//cout << l << " " << r << endl;
	if (l > r) re 0.000000000;
	if (l % 2 == 1) 
		re min(delta[l], minn(l + 1, r));
	if (r % 2 == 0) re min(delta[r], minn(l, r - 1));
	re minn(l / 2, r / 2);
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
	x.resize(n);
	y.resize(n);
	forn (i, n) {
		cin >> x[i] >> y[i];
		sum += 2.00000000 * dist(tx, ty, x[i], y[i]);
		delta[i + ma] = dist(bx, by, x[i], y[i]) - dist(tx, ty, x[i], y[i]);
		//cout << delta[i + ma] << " " << dist(ax, ay, x[i], y[i]) - dist(tx, ty, x[i], y[i]) << endl;
	}
	for (int i = ma - 1; i; i--)
		delta[i]= min(delta[2 * i], min(delta[2 * i + 1], delta[i]));
	//cout << sum << endl;
	forn (i, n) {
		//cout << min(minn(ma, i + ma - 1), minn(i + ma + 1, n - 1 + ma)) << endl;
		ans = min(ans, sum - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]) + 
			min(minn(ma, i + ma - 1), minn(i + ma + 1, n - 1 + ma)));
		//cout << endl;
		ans = min(ans, sum - dist(tx, ty, x[i], y[i]) + dist(ax, ay, x[i], y[i]));
		ans = min(ans, sum - dist(tx, ty, x[i], y[i]) + dist(bx, by, x[i], y[i]));
	}
	cout.precision(32);
	cout << ans;
	re 0;
}