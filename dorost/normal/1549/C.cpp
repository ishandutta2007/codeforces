/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i] = 0;
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		if (a[u] == 0)
			ans++;
		a[u]++;
	}
	int q;
	cin >> q;
	while (q--) {
		int a1, u, v;
		cin >> a1;
		if (a1 == 3) {
			cout << n - ans << ' ';
		} else if (a1 == 2) {
			cin >> u >> v;
			if (u > v){ 
				swap(u, v);
			}
			if (a[u] == 1)
				ans--;
			a[u]--;
		} else {
			cin >> u >> v;
			if (u > v){ 
				swap(u, v);
			}
			if (a[u] == 0)
				ans++;
			a[u]++;
		}
	}
}