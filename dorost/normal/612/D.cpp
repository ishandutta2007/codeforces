/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
pair <int, int> a[2 * N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		a[i * 2] = {l, -1};
		a[i * 2 + 1] = {r, 1};
	}
	sort(a, a + n * 2);
	vector <pair <int, int>> v;
	int x = 0;
	int aa = -1;
	for (int i = 0; i < 2 * n; i++) {
		x += -a[i].S;
		if (x == k - 1 && a[i].S == 1) {
			v.push_back({aa, a[i].F});
		}
		if (x == k && a[i].S == -1) {
			aa = a[i].F;
		}
	}
	int an = v.size();
	for (int i = 0; i < (int)v.size() - 1; i++) {
		if (v[i].S == v[i + 1].F) {
			v[i + 1].F = v[i].F;
			v[i].F = INT_MAX;
			an--;
		}
	}
	cout << an << '\n';
	for (int i = 0; i < v.size(); i++) {
		if (v[i].F != INT_MAX)
			cout << v[i].F << ' ' << v[i].S << '\n';
	}
}