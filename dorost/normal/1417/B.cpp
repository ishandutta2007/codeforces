/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], f[N];
map <int, vector <int>> mp;

void solve() {
	int n, t;
	cin >> n >> t;
	mp.clear();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[i] = -1;
		mp[a[i]].push_back(i);
	}
	for (auto x : mp) {
		int k = t - x.F;
		if (k == x.F) {
			for (int i = 0; i < x.S.size() / 2; i++) {
				f[x.S[i]] = 1;
			}
			for (int i = x.S.size() / 2; i < x.S.size(); i++) {
				f[x.S[i]] = 0;
			}
			mp[x.F].clear();
			continue;
		}
		for (int i = 0; i < mp[x.F].size(); i++) {
			f[mp[x.F][i]] = 1;
		}
		for (int i = 0; i < mp[k].size(); i++) {
			f[mp[k][i]] = 0;
		}
		mp[x.F].clear();
		mp[k].clear();
	}
	for (int i = 0; i < n; i++) 
		cout << f[i] << ' ';
	cout << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}