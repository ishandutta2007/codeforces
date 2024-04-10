#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

db tfirst(vector<int> &v, db x, int tet) {

	db tm = 0;
	db last = 0;
	db speed = 1;

	for (int i = 0; i < v.size(); ++i) {
		if ((db) v[i] > x) break;
		tm += ((db) v[i] - last) / speed;
		speed += 1;
		last = v[i];
	}

	tm += (x - last) / speed;
	return tm;

}

db tsecond(vector<int> v, db x, int tet) {

	for (auto &x : v) x = tet - x;
	reverse(all(v));
	x = (db) tet - x;

	return tfirst(v, x, tet);

}

void solve() {
	int n, l;
	cin >> n >> l;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	db L = 0, R = l;
	while (R-L >= 1e-9) {
		db M = (L+R)/2;

		db A = tfirst(v, M, l);
		db B = tsecond(v, M, l);

		//cout << M << " " << A << " " << B << endl;

		if (A < B) L = M;
		else R = M;

	}

	cout << fixed << tfirst(v, L, l) << '\n';

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout.precision(10);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}