#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

db gs(vector<pair<db, db> > v) {

	db ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		auto a = v[(i+1)%v.size()], b = v[i];
		db lowy = min(a.y, b.y), highy = max(a.y, b.y);

		db lowx = min(a.x, b.x), highx = max(a.x, b.x);

		db M = 1;
		if (a.x < b.x) M = -1;

		ans += M*(lowy * (highx - lowx) + (highy - lowy) * (highx - lowx) / 2.);
		//cout << lowy * (highx - lowx) + (highy - lowy) * (highx - lowx) / 2. << endl;
	}

	return ans;
}

const int K = 300007;
const int T = K/2;

db quadro[K];
db uno[K];
db zero[K];

db tadd[K];

db ans[K];

db eps = 1e-10;

void add(int L, int R, db a, db b, db c, db d, db tet) {
	a *= d; 
	b *= d;
	c *= d;

	//cout << L << " " << R << " " << a << " " << b << " " << c << " " << d << endl;

	R++;

	quadro[L+T] += a, quadro[R+T] -= a;
	uno[L+T] += b, uno[R+T] -= b;
	zero[L+T] += c, zero[R+T] -= c;
	tadd[R+T] += a*tet*tet + b*tet + c;

}


void process(vector<pair<db, db> > v, bool minus_left) {

	for (int i = 0; i < v.size(); ++i) {
		auto a = v[(i+1)%v.size()], b = v[i];

		db M = 1;
		if (a.x < b.x) M = -1;
		if (minus_left) M *= -1;

		if (abs(a.x - b.x) <= eps) continue;

		if (a.x > b.x) swap(a, b);

		int L = ceil(a.x - eps), R = floor(b.x + eps);

		db slope = (b.y - a.y) / (b.x - a.x);

		db lowy = min(a.y, b.y), highy = max(a.y, b.y);
		db lowx = min(a.x, b.x), highx = max(a.x, b.x);

		add(L, R, slope / 2, a.y - slope*a.x, -a.y*a.x + slope*a.x*a.x/2., M, b.x);
	}

}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<pair<int, int> > v;

	map<int, db> a;
	map<int, db> b;

	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (!a.count(y)) a[y] = x;
		else b[y] = x;
		v.pb(mp(x, y));
	}

	for (int i = 0; i < n; ++i) {
		auto f = v[i], s = v[(i+1)%n];

		if (f.second > s.second) swap(f, s);
		auto it = a.upper_bound(f.second);

		while (true) {

			if (it == a.end()) continue;
			auto el = (*it).first;

			if (el < s.second) {
				db ratio = (db) (el - f.second) / (db) (s.second - f.second);
				db X = ratio * s.first + (1. - ratio) * f.first;
				b[el] = X;
			}	
			else break;
			it++;
		}
	}

	for (auto p : a) {
		if (!b.count(p.first)) b[p.first] = p.second;
	}

	vector<tuple<int, db, db> > sit;
	for (auto p : a) {
		//cout << p.first << " " << min(b[p.first],p.second) << " " << max(b[p.first],p.second) << endl;
		sit.pb(make_tuple(p.first, min(b[p.first],p.second), max(b[p.first],p.second)));
	}

	db Ans = 0;

	for (int i = 0; i + 1 < sit.size(); ++i) {

		vector<pair<db, db> > pts;
		pts.pb(mp(get<0>(sit[i]), get<1>(sit[i])));
		pts.pb(mp(get<0>(sit[i]), get<2>(sit[i])));
		pts.pb(mp(get<0>(sit[i]), (get<1>(sit[i]) + get<2>(sit[i])) / 2.));

		pts.pb(mp(get<0>(sit[i+1]), get<1>(sit[i+1])));
		pts.pb(mp(get<0>(sit[i+1]), get<2>(sit[i+1])));
		pts.pb(mp(get<0>(sit[i+1]), (get<1>(sit[i+1]) + get<2>(sit[i+1])) / 2.));

		for (auto &t : pts) swap(t.first, t.second);

		vector<pair<db, db> > ltrap = {pts[0], pts[3], pts[5], pts[2]};
		vector<pair<db, db> > rtrap = {pts[1], pts[4], pts[5], pts[2]};

		db A = gs(ltrap), B = gs(rtrap);
		if (A < 0) reverse(all(ltrap));
		if (B < 0) reverse(all(rtrap));

		process(ltrap, true);
		process(rtrap, false);

		Ans += abs(A) + abs(B);
	}

	db e = 0, f = 0, g=0;
	for (int i = 0; i < K; ++i) {
		e += quadro[i], f += uno[i], g += zero[i] + tadd[i];
		db X = i - T;

		ans[i] = e*X*X + f*X + g;
	}

	cout.precision(10);

	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;

		cout << fixed << Ans + ans[t+T] << "\n";
	}

	

}