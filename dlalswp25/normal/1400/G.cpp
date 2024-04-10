#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
typedef pair<int, int> pii;

ll F[303030];
ll I[303030];

int N, M;
int L[303030];
int R[303030];
int A[30];
int B[30];

int C[303030];
int delta[303030];

int D[303030][50];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

ll ncr(int n, int r) {
	if(n < r || r < 0 || n < 0) return 0;
	return F[n] * I[r] % MOD * I[n - r] % MOD;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &L[i], &R[i]);
		delta[L[i]]++;
		delta[R[i] + 1]--;
	}
	for(int i = 0; i < M; i++) scanf("%d%d", &A[i], &B[i]);

	F[0] = 1;
	for(int i = 1; i <= N; i++) F[i] = F[i - 1] * i % MOD;
	I[N] = pw(F[N], MOD - 2);
	for(int i = N - 1; i >= 0; i--) I[i] = I[i + 1] * (i + 1) % MOD;

	for(int i = 1; i <= N; i++) {
		C[i] = C[i - 1] + delta[i];
	}

	ll ans = 0;
	for(int i = 1; i <= N; i++) ans = (ans + ncr(C[i], i)) % MOD;

	for(int i = 1; i < 1 << M; i++) {
		vector<int> v;
		int l = 1, r = N;

		int b = 0;
		for(int j = 0; j < M; j++) if(i & 1 << j) {
			v.push_back(A[j]);
			v.push_back(B[j]);
			l = max(l, max(L[A[j]], L[B[j]]));
			r = min(r, min(R[A[j]], R[B[j]]));
			b ^= 1;
		}

		if(r < l) continue;
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int x = v.size();

		if(b) { D[l][x]--; D[r + 1][x]++; }
		else { D[l][x]++; D[r + 1][x]--; }
	}

	// for(int i = 1; i <= N; i++) printf("%d ", C[i]); puts("");
	// printf("%lld\n", ans);

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j <= 2 * M; j++) {
			D[i][j] += D[i - 1][j];

			// printf("%d %d %d\n", i, j, D[i][j]);

			ll t = (D[i][j] >= 0 ? D[i][j] : MOD + D[i][j]);
			ans = (ans + ncr(C[i] - j, i - j) * t) % MOD;
			// printf("%lld\n", ans);
		}
	}
	printf("%lld\n", ans);

	return 0;
}