/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int c[N], a[N];
bool vis[N], vis2[N];
vector <int> v;

int mn(int x) {
	int mm = INT_MAX;
	bool f = false;
	for (auto e : v) {
		if (x == e)
			f = true;
		if (f)
			mm = min(mm, c[e]);
	}
	return mm;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i])
			continue;
		v = {};
		int x = i;
		while (true) {
			if (!vis2[x]) {
				vis2[x] = true;
				v.push_back(x);
			} else if (vis2[x] && !vis[x] && a[x] != x) {
				vis2[x] = true;
				v.push_back(x);
				ans += mn(a[x]);
				break;
			} else if (vis2[x] && !vis[x] && a[x] == x) {
				vis2[x] = true;
				v.push_back(x);
				ans += c[x];
				break;
			} else {
				break;
			}
			x = a[x];
		}
		for (auto aa : v) {
			vis[aa] = true;
		}
	}
	cout << ans;
}