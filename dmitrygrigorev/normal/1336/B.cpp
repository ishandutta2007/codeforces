#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> mr(int n) {


	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	sort(all(v));
	return v;

}


ll get(vector<int> &a, vector<int> &b, vector<int> &c) {

	int d = 0, e = 0;
	ll ans = 5e18;
	for (int i = 0; i < b.size(); ++i) {
		while (d+1 < a.size() && a[d+1] <= b[i]) d++;
		while (e+1 < c.size() && c[e] < b[i]) e++;
		ll x = abs(b[i]-a[d]), y = abs(b[i]-c[e]), z = abs(c[e]-a[d]);
		ans = min(ans, x*x+y*y+z*z);
	}

	return ans;

}

void solve() {
	int e, f,g ;
	cin >> e >> f >> g;
	vector<int> a = mr(e);
	vector<int> b = mr(f);
	vector<int> c = mr(g);

	ll res = 5e18;
	res = min(res, get(a, b, c));
	res = min(res, get(a, c, b));
	res = min(res, get(b, a, c));
	res = min(res, get(b, c, a));
	res = min(res, get(c, a, b));
	res = min(res, get(c, b, a));

	cout << res<< "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();


}