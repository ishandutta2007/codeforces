/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int cnt[N], pow2[N];

int32_t main() {
	pow2[0] = 1;
	for (int i = 1; i < N; i++) {
		pow2[i] = pow2[i - 1] * 2;
		if (pow2[i] >= M)
			pow2[i] -= M;
	}
	int n;
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		cnt[u - 1]++;
		cnt[v - 1]++;
	}
	for (int i = 0; i < n; i++) {
		if (cnt[i] != 1) 
			x++;
		else
			y++;
	}
	ll ans = (ll)y * (ll)pow2[x + 1] + (ll)x * (ll)pow2[x];
	ans %= M;
	cout << ans;
}