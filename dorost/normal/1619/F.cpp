/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202344;
int t[N];
bool f[N];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int x = (n / m) + 1, y = n / m;
	int a = n % m, b = m - n % m;
	set <pair <int, int>> st;
	for (int i = 1; i <= (a * k * x) % n; i++) {
		t[i] = (a * k * x) / n + 1;
		st.insert({t[i], i});
	} 
	for (int i = (a * k * x) % n + 1; i <= n; i++) {
		t[i] = (a * k * x) / n;
		st.insert({t[i], i});
	}
	for (int i = 0; i < k; i++) {
		vector <pair <int, int>> v;
		while (v.size() < (a * x)) {
			auto x2 = st.end();
			x2--;
			v.push_back(*x2);
			assert(v.back().F);
			st.erase(x2);
		}
		for (int i = 1; i <= n; i++)
			f[i] = true;
		for (int j = 0; j < a; j++) {
			cout << x << ' ';
			for (int l = 0; l < x; l++) {
				cout << v[j * x + l].S << ' ';
				f[v[j * x + l].S] = false;
				st.insert({v[j * x + l].F - 1, v[j * x + l].S});
			}
			cout << '\n';
		}
		vector <int> w;
		for (int i = 1; i <= n; i++) {
			if (f[i])
				w.push_back(i);
		}
		assert(w.size() == b * y);
		for (int j = 0; j < b; j++) {
			cout << y << ' ';
			for (int l = 0; l < y; l++) {
				cout << w[j * y + l] << ' ';
			}
			cout << '\n';
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}