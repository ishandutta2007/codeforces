#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, ll> llll;

int W, H, N;
ii B[2100];		//(r, c)
ll dp[2100];

ll fac[201000], invfac[201000];
int fast_exp(ll b, ll e) {
	ll ans = 1;
	while(e) {
		if(e & 1)
			ans = (ans * b) % MOD;
		b = (b * b) % MOD;
		e >>= 1;
	}
	return ans;
}
inline int inv(int n) {
	return fast_exp(n, MOD - 2);
}
void prec_fac() {
	fac[0] = invfac[0] = 1;
	for(int i = 1; i < W + H + 100; ++i) {
		fac[i] = (fac[i - 1] * i) % MOD;
		invfac[i] = inv(fac[i]);
	}
}

int binom(int n, int k) {
	return (((fac[n] * invfac[k]) % MOD) * invfac[n - k]) % MOD;
}

int distbin(ii a, ii b) {
	return binom(b.first - a.first + b.second - a.second, b.first - a.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> H >> W >> N;
	for(int n = 0; n < N; ++n)
		cin >> B[n].first >> B[n].second;
	B[N] = ii(1, 1);
	++N;
	
	sort(B, B + N, greater<ii>());
	prec_fac();
	
	for(int n = 0; n < N; ++n) {
		ll tmp = 0;
		for(int m = 0; m < n; ++m)
			if(B[n].second <= B[m].second)
				tmp = (tmp + ll(distbin(B[n], B[m])) * dp[m]) % MOD;
		dp[n] = distbin(B[n], ii(H, W)) - tmp;
		dp[n] = (dp[n] + MOD) % MOD;
	}
	
	cout << dp[N - 1];
}