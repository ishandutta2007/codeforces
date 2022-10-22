/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int ps[N], M, ans2[N], b[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	M = m;
	ans2[1] = 1;
	ans2[2] = 2;
	b[2] = 1;
	for (int i = 3; i <= n; i++) {
		int x = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j)
				continue;
			x += ans2[i / j] - ans2[(i - 1) / (j)];
			if (x < 0)
				x += M;
			if (j * j == i)
				continue;
			x += ans2[j] - ans2[(i - 1) / (i / j)];
			if (x < 0)
				x += M;
			x %= M;
		}
		ans2[i] = ans2[i - 1] * 2 + x;
		ans2[i] %= M;
		b[i] = b[i - 1] + x;
		b[i] %= M;
	}
	cout << ans2[n];
}