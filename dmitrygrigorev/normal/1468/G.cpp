#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

db pi = acos(-1);

db ttt(db x) {
	while (x < 0) x += 2.*pi;
	while (x >= 2.*pi) x -= 2.*pi;
	return x;
}

db eps = 1e-15;

db process(pair<db, db> a, pair<db, db> b, pair<db, db> c, db angle) {

	angle += eps;

	pair<db, db> fv = mp(a.x - c.x, a.y - c.y);
	pair<db, db> sv = mp(b.x - c.x, b.y - c.y);

	if (ttt(atan2(fv.y, fv.x)) < ttt(atan2(sv.y, sv.x))) swap(fv, sv);

	db L = 0, R = 1;
	while (R-L>eps) {
		db M = (L+R)/2;
		auto Q = mp(M * sv.x + (1. - M) * fv.x, M * sv.y + (1. - M) * fv.y);

		db tangle = ttt(atan2(Q.y, Q.x));
		if (tangle < angle) {
			R = M;
		}
		else L = M;

	}

	auto Q = mp(R * sv.x + (1. - R) * fv.x, R * sv.y + (1. - R) * fv.y);
	db dx = Q.x - sv.x, dy = Q.y - sv.y;
	return sqrt(dx*dx + dy*dy);

}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, h;
	cin >> n >> h;

	vector<pair<int, int> > v(n);
	for (auto &x : v) {
		cin >> x.x >> x.y;
	}

	db angle = 3. * pi / 2;

	db ans = 0;

	for (int i = n-2; i >= 0; --i) {
		pair<db, db> W = mp(v.back().x, v.back().y+h);
		ans += process(v[i], v[i+1], W, angle);
		angle = min(angle, ttt(atan2(v[i].y - (v.back().y + h), v[i].x - v.back().x)));
	}

	cout.precision(10);
	cout << fixed << ans;



}