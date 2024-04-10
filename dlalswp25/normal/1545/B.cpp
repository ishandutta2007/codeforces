#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MX = 100000;

int N;
char A[101010];
ll F[101010];
ll I[101010];

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

ll ncr(ll n, ll r) { return F[n] * I[r] % MOD * I[n - r] % MOD; }

ll nhr(ll n, ll r) { return ncr(n + r - 1, r); }

int main() {
	F[0] = 1;
	for(int i = 1; i <= MX; i++) F[i] = F[i - 1] * i % MOD;
	I[MX] = inv(F[MX]);
	for(int i = MX - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);

		int zero = 0;
		for(int i = 1; i <= N; i++) if(A[i] == '0') zero++;

		int x = 0, y = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') y = 0;
			else {
				if(y == 1) { x++; y = 0; }
				else y = 1;
			}
		}
		printf("%lld\n", nhr(zero + 1, x));
	}
	return 0;
}