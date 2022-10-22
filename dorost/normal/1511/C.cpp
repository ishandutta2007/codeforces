/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N], pos[54];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < 54; i++)
		pos[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (pos[a[i]] == -1)
			pos[a[i]] = i;
	}
	for (int i = 0; i < q; i++) {
		int t;
		cin >> t;
		cout << pos[t] + 1 << ' ';
		for (int i = 0; i < 54; i++) {
			if (pos[i] < pos[t]) {
				pos[i]++;
			}
		}
		pos[t] = 0;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}