/*  * In the name of GOD 
 	* Thanks God */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 150010;
int a[4][N];
int f[N];
pair <int, int> b[4][N];
vector <int> v[3][N];

void solve() {
	int n[4];
	for (int i = 0; i < 4; i++) {
		scanf("%lld", n + i);
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n[i]; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		int m;
		scanf("%lld", &m);
		for (int j = 0; j < m; j++) {
			int x, y;
			scanf("%lld%lld", &x, &y);
			v[i][x - 1].push_back(y);
		}
	}
	int x[4] = {};
	x[3] = n[3];
	int mnx = LLONG_MAX;
	for (int i = 3; i >= 0; i--) {
		if (i == 3) {
			for (int j = 0; j < n[i]; j++) {
				b[i][j] = {a[i][j], j + 1};
			}
			sort(b[i], b[i] + n[i]);
			continue;
		}
		for (int j = 0; j < n[i]; j++) {
			int mn = a[i][j];
			set <int> st;
			for (auto x : v[i][j]) {
				st.insert(x);
			}
			for (int k = 0; k < x[i + 1]; k++) {
				if (!st.count(b[i + 1][k].S)) {
					mn += b[i + 1][k].F;
					break;
				}
			}
			if (mn == a[i][j]) {
				mn = -1;
				continue;
			}
			if (i == 0) {
				if (mn == -1)
					continue;
				mnx = min(mnx, mn);
			} else {
				b[i][x[i]] = {mn, j + 1};
				x[i]++;
			}
		}
		if (i != 0)
			sort(b[i], b[i] + x[i]);
	}
	printf("%lld", (mnx == LLONG_MAX ? -1 : mnx));
}

int32_t main() {
	solve();
}