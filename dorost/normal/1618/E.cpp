/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 401234;
int a[N], b[N];
vector <int> v;

int sum(int x) {
	int s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += ((int)v.size() - i) * (v[i] + x);
	}
	return s;
}

bool is_valid(int x, int s) {
	return sum(x) <= s;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b[0] = a[0] - a[n - 1];
	for (int i = 1; i < n; i++) 
		b[i] = a[i] - a[i - 1];
	int s = *max_element(b, b + n) + n;
	v.clear();
	for (int i = 0; i < n; i++) {
		int w = s - b[i];
		if (w % n) {
			cout << "NO\n";
			return;
		}
		v.push_back(w / n);
	}
	int l = 0, r = INT_MAX;
	if (!is_valid(l, a[n - 1])) {
		cout << "NO\n";
		return;
	}
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid, a[n - 1])) {
			l = mid;
		} else {
			r = mid;
		}
	}
	if (sum(l) == a[n - 1]) {
		cout << "Yes\n";
		for (auto x : v) {
			cout << x + l << ' ';
		}
		cout << '\n';
	} else {
		cout << "NO\n";
		return;
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