/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 31;
int a[M], p2[M];

int32_t main() {
	p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[lower_bound(p2, p2 + M, x) - p2]++;
	}
	while (q--) {
		int b;
		cin >> b;
		int ans = 0;
		for (int i = M - 1; i >= 0; i--) {
			int x = min(b / p2[i], a[i]);
			b -= (x * p2[i]);
			ans += x;
		}
		cout << (b == 0 ? ans : -1) << ' ';
	}
}