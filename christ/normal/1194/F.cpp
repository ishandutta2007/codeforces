#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
using ui = unsigned int;
using ull = unsigned long long;
using ui128 = __uint128_t;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 2e5 + 2, LOG = 17, INF = 1e8, MOD = 1e9 + 7;
ll psa[MN]; int fac[MN],invfac[MN],pw2[MN];
int inv (int base) {
	int exp = MOD - 2, res = 1;
	while (exp) {
		if (exp&1) res = res * 1LL * base % MOD;
		base = base * 1LL * base % MOD;
		exp >>= 1;
	}
	return res;
}
int choose (int n, int k) {
	return fac[n] * 1LL * invfac[k] % MOD * invfac[n-k] % MOD;
} 
int main () { 
	int n,least=0,most=0,tot=0; ll t;
	scanf ("%d %lld",&n,&t); fac[0] = invfac[0] = pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf ("%lld",&psa[i]); psa[i] += psa[i-1]; fac[i] = fac[i-1] * 1LL * i % MOD; pw2[i] = pw2[i-1] * 2 % MOD;
		if (psa[i] + i <= t) least = i;
		if (psa[i] <= t) most = i;
	}
	invfac[n] = inv(fac[n]);
	for (int i = n-1; i >= 1; i--) invfac[i] = invfac[i+1] * 1LL * (i+1) % MOD;
	for (int i = least; i <= most; i++) { //psa[i] + x <= t, psa[i+1] + x (+1) > t
		int lx = i == n ? 0 : t - psa[i+1] + 1, rx = t - psa[i]; //special value t - psa[i+1]
		lx = max(lx,0); rx = min(rx,i);
		for (int x = lx; x <= rx; x++) { //i choose x ? 
			tot += choose(i,x) * 1LL * pw2[n-i] % MOD * 1LL * i % MOD;
			if (tot >= MOD) tot -= MOD;
		}
		if (lx && i != n) tot += choose(i,lx-1) * 1LL * pw2[n-i-1] % MOD * 1LL * i % MOD;
		if (tot >= MOD) tot -= MOD; 
	}
	printf ("%lld\n",tot * 1LL * inv(pw2[n]) % MOD);
    return 0;
}