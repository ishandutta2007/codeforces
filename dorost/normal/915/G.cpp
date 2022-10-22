/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 2012345, M = 1000 * 1000 * 1000 + 7;
int ans[N];
bool bad[N], prime[N], v[N];

int tav(int x, int n) {
	ll ans = 1;
	while (n) {
		if (n & 1) 
			ans = (ans * x) % M;
		n >>= 1;
		x = (x * x) % M;
	}
	return ans;
}
 
int inv(int x) {
	return tav(x, M - 2);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= k; i++)
		prime[i] = true;
	for (int i = 1; i <= k; i++) {
		if (bad[i])
			continue;
		if (i != 1) {
			for (int j = i * 2; j <= k; j += i) {
				if (j % (i * i) == 0) {
					bad[j] = true;
				}
				v[j] ^= prime[i];
				prime[j] = false;
			}
		}
		v[i] ^= prime[i];
		for (int j = i; j <= k; j += i) {
			int l = j;
			int r = min(k, j + i - 1);
			int wef = tav(j / i, n);
			if (!v[i]) {
				ans[l] += wef;
				ans[r + 1] -= wef;
				ans[l] %= M;
				ans[r + 1] %= M;
				ans[r + 1] += M;
				ans[r + 1] %= M;
			} else {
				ans[l] -= wef;
				ans[r + 1] += wef;
				ans[l] %= M;
				ans[l] += M;
				ans[l] %= M;
				ans[r + 1] %= M;
			}
		}
	}
	int answef = 0;
	for (int i = 1; i <= k; i++) {
		ans[i] += ans[i - 1];
		ans[i] %= M;
		ans[i] += M;
		ans[i] %= M;
		answef += (ans[i] ^ i);
		answef %= M;
	}
	cout << answef << endl;
}