/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5001, inf = 101010;
int n, q, a[N], ps[N];
pair <int, int> l[N];

int32_t main() {
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		cin >> l[i].F >> l[i].S;
		for (int j = l[i].F; j <= l[i].S; j++) {
			a[j]++;
		}
	}
	int mx = 0;
	for (int i = 0; i < q; i++) {
		for (int j = l[i].F; j <= l[i].S; j++) {
			a[j]--;
		}
		int x = 0;
		ps[0] = 0;
		for (int j = 1; j <= n; j++) {
			ps[j] = ps[j - 1] + (a[j] == 1);
			if (a[j] == 0)
				x++;
		}
		for (int j = 0; j < q; j++) {
			if (i == j) {
				continue;
			}
			mx = max(mx, n - x - (ps[l[j].S] - ps[l[j].F - 1]));
		}
		for (int j = l[i].F; j <= l[i].S; j++) {
			a[j]++;
		}
	}
	cout << mx;
}