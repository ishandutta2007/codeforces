#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 7;
int fac[MN], invfac[MN];
int fpow (int base, long long exp) {
	int res = 1;
	while (exp) {
		if (exp & 1) res = (long long) res * base % MOD;
		base = (long long)base * base % MOD;
		exp >>= 1;
	}
	return res;
}
int inv (int base) {
	return fpow(base,MOD-2);
}
int choose (int n, int k) {
	return (long long)fac[n] * invfac[k] % MOD * invfac[n-k] % MOD;
}
void solve () {
	int n,k; scanf ("%d %d",&n,&k);
	if (n % 2 == 1) {
		int ret = 0;
		for (int cnt = 0; cnt <= k; cnt++) {
			ret = (ret + (long long)choose(k,cnt) * fpow(2,(long long)(n-1) * (k-cnt))) % MOD;
		}
		printf ("%d\n",ret);
	} else {
		int ret = 0; //no bits
		int ways = 0;
		for (int i = 0; i < n; i += 2) {
			ways += choose(n,i);
			if (ways >= MOD) ways -= MOD;
		}
		ret = fpow(ways,k);
		for (int first = k-1; first >= 0; first--) {
			int cnt = fpow(ways,k-1-first);
			if (cnt < 0) cnt += MOD;
			ret = (ret + (long long)fpow(2,(long long)n*first) * cnt) % MOD;
		}
		printf ("%d\n",ret);
	}
}
int main() {
	fac[0] = invfac[0] = 1;
	for (int i = 1; i < MN; i++) {
		fac[i] = (long long)fac[i-1] * i % MOD;
		invfac[i] = inv(fac[i]);
	}
	int t; scanf ("%d",&t);
	while (t--) solve();
    return 0;
}