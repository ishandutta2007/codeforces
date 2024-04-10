#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 200000;

int N;
int A[101010];
ll F[202020];
ll I[202020];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll inv(ll x) { return pw(x, MOD - 2); }

ll ncr(int n, int r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		ll tot = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			tot += A[i];
		}
		if(!tot) { printf("%lld\n", pw(2, N - 1)); continue; }

		ll s = 0;
		map<ll, int> L, R;
		for(int i = 1; i <= N; i++) {
			s += A[i]; L[s]++;
		}
		s = 0;
		for(int i = N; i >= 1; i--) {
			s += A[i]; R[s]++;
		}

		s = 0;
		int z = 0;
		ll ans = 1;
		ll d = 1;
		ll curs = 0, td = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 0) z++;
			else z = 0;
			s += A[i];
			if(s > curs) {
				curs = s; d = (d + td) % MOD;
				td = 0;
			}
			if(s + s > tot) break;
			if(R.find(s) == R.end()) continue;
			int tz = R[s] - 1;
			if(!s) tz++;
			if(s * 2 == tot) tz -= z;
			ll t;
			if(s) t = ncr(z + tz + 1, tz) * d % MOD;
			else t = ncr(z + tz - 1, tz - 1) * d % MOD;
			td = (td + t) % MOD;
			ans = (ans + t) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}