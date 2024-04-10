#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
vector<int> A[303030];
vector<int> U[303030];
vector<int> L[303030];
char S[303030];
ll D[303030];
ll pw[303030];

int main() {
	pw[0] = 1;
	for(int i = 1; i <= 300000; i++) pw[i] = pw[i - 1] * 2 % MOD;

	scanf("%d%d", &N, &M);
	int W = 0;

	U[0].resize(M + 1);
	L[0].resize(M + 1);

	for(int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		A[i].push_back(0);
		for(int j = 1; j <= M; j++) {
			if(S[j] == 'o') { A[i].push_back(1); W++; }
			else A[i].push_back(0);
		}
		U[i].resize(M + 1);
		L[i].resize(M + 1);
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] == 1) {
				U[i][j] = U[i - 1][j] + 1;
				L[i][j] = L[i][j - 1] + 1;
				D[U[i][j]]++;
				D[L[i][j]]++;
			}
			else U[i][j] = L[i][j] = 0;
		}
	}

	for(int i = max(N, M); i >= 1; i--) D[i] = (D[i] + D[i + 1]) % MOD;
	ll ans = 0;
	for(int i = 2; i <= max(N, M); i++) {
		if(i > W) break;
		ll t = pw[W - i] * D[i] % MOD;
		if(i & 1) t = MOD - t;
		ans = (ans + t) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}