/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
ll dpd[N], dpu[N];
int s[N];
vector <int> g[N];
int n;

void dfsd(int x, int p) {
	s[x] = 1;
	for (auto y : g[x]) {
		if (y != p) {
			dfsd(y, x);
			s[x] += s[y];
		}
	}
	dpd[x] = s[x];
	for (auto y : g[x]) {
		if (y != p) {
			dpd[x] += dpd[y];
		}
	}
}

void dfsu(int x, int p) {
	ll sum = dpu[x];
	for (auto y : g[x]) {
		if (y != p) {
			sum += dpd[y];
		}
	}
	for (auto y : g[x]) {
		if (y != p) {
			dpu[y] = sum - dpd[y] + (n - s[y]);
		}
	}
	for (auto y : g[x]) {
		if (y != p)
			dfsu(y, x);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	dfsd(0, -1);
	dpu[0] = n;
	dfsu(0, -1);
	ll mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, dpu[i] + dpd[i] - s[i]);
	}
	cout << mx;
}