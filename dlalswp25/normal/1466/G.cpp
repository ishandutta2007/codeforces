#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MX = 1000001;

int N, M, Q;
ll pw[101010];
ll tot[101010][30];
int len[101010];

char S0[105];
char T[101010];

char W[1010101];
char S[1010101];
char S2[1010101];
int fail[1010101];
int fail2[1010101];

int fail3[105];

bool L[1010101];
bool R[1010101];
int id;

void f(int x) {
	if(x == 0) {
		for(int i = 1; i <= M; i++) {
			id++;
			if(id > MX) return;
			S[id] = S0[i];
		}
		return;
	}

	if(id > MX) return;
	f(x - 1);
	if(id > MX) return;
	id++;
	if(id > MX) return;
	S[id] = T[x];
	f(x - 1);
}

void g(int x) {
	if(x == 0) {
		for(int i = 1; i <= M; i++) {
			id++;
			if(id > MX) return;
			S2[id] = S0[M - i + 1];
		}
		return;
	}

	if(id > MX) return;
	g(x - 1);
	if(id > MX) return;
	id++;
	if(id > MX) return;
	S2[id] = T[x];
	g(x - 1);
}

int main() {
	scanf("%d%d", &N, &Q);
	scanf("%s", S0 + 1); M = strlen(S0 + 1);
	scanf("%s", T + 1);

	f(30);
	id = 0;
	g(30);

	fail[1] = 1;
	int p = 1;
	for(int i = 2; i <= MX; i++) {
		while(p > 1 && S[p] != S[i]) p = fail[p - 1];
		if(S[p] == S[i]) { fail[i] = ++p; }
		else fail[i] = p = 1;
	}

	fail2[1] = 1;
	p = 1;
	for(int i = 2; i <= MX; i++) {
		while(p > 1 && S2[p] != S2[i]) p = fail2[p - 1];
		if(S2[p] == S2[i]) { fail2[i] = ++p; }
		else fail2[i] = p = 1;
	}

	pw[0] = 1;
	for(int i = 1; i <= N; i++) pw[i] = pw[i - 1] * 2 % MOD;

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 26; j++) tot[i][j] = tot[i - 1][j] * 2 % MOD;
		tot[i][T[i] - 'a'] = (tot[i][T[i] - 'a'] + 1) % MOD;
	}
	len[0] = M;
	for(int i = 1; i <= N; i++) {
		len[i] = 2 * len[i - 1] + 1;
		if(len[i] > MX) len[i] = MX + 1;
	}

	while(Q--) {
		int K; scanf("%d", &K);
		scanf("%s", W + 1);

		int Z = strlen(W + 1);

		for(int i = 0; i <= Z + 1; i++) L[i] = R[i] = false;

		int p = 1;
		for(int i = 1; i <= Z; i++) {
			while(p > 1 && S[p] != W[i]) p = fail[p - 1];
			if(S[p] == W[i]) {
				if(i == Z) {
					while(p > 1) {
						R[i - p + 1] = true;
						p = fail[p] - 1;
					}
					if(S[p] == W[i]) R[i] = true;
					break;
				}
				else p++;
			}
		}

		reverse(W + 1, W + Z + 1);

		p = 1;
		for(int i = 1; i <= Z; i++) {
			while(p > 1 && S2[p] != W[i]) p = fail2[p - 1];
			if(S2[p] == W[i]) {
				if(i == Z) {
					while(p > 1) {
						L[Z - (i - p + 1) + 1] = true;
						p = fail2[p] - 1;
					}
					if(S2[p] == W[i]) L[1] = true;
					break;
				}
				else p++;
			}
		}

		reverse(W + 1, W + Z + 1);
		L[0] = true; R[Z + 1] = true;

		// printf("L : "); for(int i = 1; i <= Z; i++) printf("%d ", L[i]); puts("");
		// printf("R : "); for(int i = 1; i <= Z; i++) printf("%d ", R[i]); puts("");

		ll ans = 0;
		for(int i = 1; i <= Z; i++) {
			if(!L[i - 1] || !R[i + 1]) continue;
			ans = (ans + tot[K][W[i] - 'a']) % MOD;
			// printf("%d %lld\n", i, tot[K][W[i] - 'a']);
			for(int j = 1; j <= K; j++) {
				if(!(i + len[j - 1] < Z || i - len[j - 1] > 1)) break;
				if(T[j] != W[i]) continue;
				ans = (ans + MOD - pw[K - j]) % MOD;
			}
		}

		// printf("%lld\n", ans);

		if(Z <= M) {
			fail3[1] = 1;
			int pp = 1;
			for(int i = 2; i <= Z; i++) {
				while(pp > 1 && W[pp] != W[i]) pp = fail3[pp - 1];
				if(W[pp] == W[i]) { fail3[i] = ++pp; }
				else fail3[i] = pp = 1;
			}

			pp = 1;
			int cnt = 0;
			for(int i = 1; i <= M; i++) {
				while(pp > 1 && W[pp] != S0[i]) pp = fail3[pp - 1];
				if(W[pp] == S0[i]) {
					if(pp == Z) {
						cnt++;
						pp = fail3[pp];
					}
					else pp++;
				}
			}
			ans = (ans + cnt * pw[K]) % MOD;
		}

		printf("%lld\n", ans);
	}

	return 0;
}

/*
31 100
az
azazazazazazazazazazazazazazaza
1 aa
*/