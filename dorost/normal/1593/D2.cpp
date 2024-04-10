/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 41, M = 1012345;
int a[N], b[N];
map <int, int> cnt;
vector <int> v, w;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	bool f = true;
	int x = 0;
	for (int i = 0; i < n; i++) {
		x++;
		if (a[i] == n - 1 || a[i] != a[i + 1]) {
			if (x >= (n + 1) / 2) {
				f = false;
			}
			x = 0;
		}
	}
	if (!f) {
		cout << -1 << ' ';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i != 0)
			b[i - 1] = a[i] - a[i - 1];
	}
//	cout << b[0] << ' ';
	for (int i = 1; i < n - 1; i++) {
//		cout << b[i] << ' ';
		b[i] += b[i - 1];
	}
//	cout << '\n';
	int mx = 0;
	for (int i = 0; i <= (n + 1) / 2; i++) {
		v.clear();
		w.clear();
		int t0 = 1;
		for (int j = i; j < n - 1; j++) {
			v.push_back(b[j] - (i == 0 ? 0 : b[i - 1]));
			if (v.back() == 0)
				t0++;
		}	
		for (int i = 0; i < v.size(); i++) {
//			cout << v[i] << ' ';
			for (int j = 1; j * j <= v[i]; j++) {
				if (v[i] % j)
					continue;
				cnt[j]++;
				if (cnt[j] == 1)
					w.push_back(j);
				if (j * j == v[i])
					continue;
				cnt[v[i] / j]++;
				if (cnt[v[i] / j] == 1)
					w.push_back(v[i] / j);
			}
		}
//		cout << '\n';
		for (int i = 0; i < w.size(); i++) {
			if (cnt[w[i]] + t0 >= (n + 1) / 2) {
				mx = max(mx, w[i]);
			}
			cnt[w[i]] = 0;
		}
	}
	cout << mx << ' ';
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