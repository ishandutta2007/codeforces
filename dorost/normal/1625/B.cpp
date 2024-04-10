/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 150123;
int a[N];
vector <int> v[N];

void solve() {
	int n;
	cin >> n;
	int mx = -1;
	set <int> st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.insert(a[i]);
		v[a[i]].push_back(i);
	}
	for (auto x : st) {
		for (int i = 0; i < (int)v[x].size() - 1; i++) {
			mx = max(mx, n - v[x][i + 1] + v[x][i]);
		}
	}
	cout << mx << ' ';
	for (auto x : st) {
		v[x].clear();
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