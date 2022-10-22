/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], p[N], sz[N];
pair <int, int> b[N];
ll mst;
int num;

int get_root (int x) {
	if (p[x] == x)
		return x;
	return p[x] = get_root(p[x]);
}

void merge (int x, int y, int w) {
	x = get_root(x);
	y = get_root(y);
	if (x == y)
		return;
	if (sz[x] > sz[y])
		swap(x, y);
	p[x] = y;
	sz[y] += sz[x];
	sz[x] = 0;
	mst += w;
	num--;
}

void solve() {
	int n, wef;
	cin >> n >> wef;
	mst = 0;
	num = n - 1;
	for (int i = 0; i <= n + 10; i++) {
		sz[i] = 1;
		p[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = {a[i], i};
	}
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		if (b[i].F >= wef)
			break;
		int in = b[i].S;
		for (int j = in + 1; j < n && (a[j] % a[in] == 0) && p[in] != p[j]; j++) {
			merge(in, j, a[in]);
		}
		for (int j = in - 1; j >= 0 && (a[j] % a[in] == 0) && p[in] != p[j]; j--) {
			merge(in, j, a[in]);
		}
	}
	cout << mst + (ll)wef * (ll)num << '\n';
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