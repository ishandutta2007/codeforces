#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;


const int MOD = 1000000007;

int powmod (int a, int b) {
	int res = 1;
	while (b)
		if (b & 1)
			res = res * 1ll * a % MOD,  --b;
		else
			a = a * 1ll * a % MOD,  b >>= 1;
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	int ans = 1;
	for (int i=1; i<=2*n; ++i)
		ans = ans * 1ll * i % MOD;
	for (int i=1; i<=n; ++i) {
		int j = powmod (i, MOD-2);
		ans = ans * 1ll * j % MOD;
		ans = ans * 1ll * j % MOD;
	}
	ans = ans * 1ll * powmod (2, MOD-2) % MOD;

	ans = ((ans-n) * 2 + n) % MOD;
	ans = (ans + MOD) % MOD;
	cout << ans;

}