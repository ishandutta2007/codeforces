/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], ans[N];

void solve() {
	int n;
	cin >> n;
	string s;
	vector <pair <int, int>> v, w;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			v.push_back(make_pair(a[i], i));
		} else {
			w.push_back(make_pair(a[i], i));
		}
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for (int i = 0; i < v.size(); i++) {
		ans[v[i].S] = i + 1;
	}
	for (int i = 0; i < w.size(); i++) {
		ans[w[i].S] = i + 1 + v.size();
	}
	for (int i = 0; i < n; i++) 
		cout << ans[i] << ' ';
	cout << '\n';
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