/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 31;
int p2[M];

int ans(int n, int m, int k, int m2) {
	if (n > m) {
		return k;
	}
	int in = *(upper_bound(p2, p2 + M, m2) - 1);
	if (in == 0)
		return k;
//	cout << n << ' ' << m << ' ' << in << '\n';
	if ((n / in) % 2) {
		return ans(n | in, m, k, m2 - in);
	}
	return ans(n | in, m, k | in, m2 - in);
}

void solve() {
	int n, m;
	cin >> n >> m;
	int x = ans(n, m + 1, 0, m + 1);
	cout << x << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}