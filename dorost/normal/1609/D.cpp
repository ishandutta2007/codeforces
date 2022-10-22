/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
vector <int> m[N];
int w[N];

void solve() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		w[i] = i;
		m[i] = {i};
	}
	int ans = 0;
	for (int i = 0; i < d; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (w[x] != w[y]) {
			int wy = w[y];
			for (auto k : m[wy]) {
				m[w[x]].push_back(k);
				w[k] = w[x];
			}
			m[wy].clear();
		} else {
			ans++;
		}
		vector <int> v;
		int mx = 0;
		for (int j = 0; j < n; j++) {
			v.push_back((int)m[j].size());
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int j = 0; j < ans + 1; j++) 
			mx += v[j];
		cout << mx - 1 << '\n';
	}
}

int32_t main() {
	int t = 1;
	while (t--) {
		solve();
	}
}