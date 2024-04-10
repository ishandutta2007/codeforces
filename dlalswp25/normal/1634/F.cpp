#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q, MOD;
int F[303030];
int add[303030];
int A[303030];
int B[303030];
int cnt;

int main() {
	scanf("%d%d%d", &N, &Q, &MOD);
	F[1] = 1;
	for(int i = 2; i <= N + 1; i++) F[i] = (F[i - 1] + F[i - 2]) % MOD;
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
	for(int i = 1; i <= N; i++) A[i] = (A[i] + MOD - B[i]) % MOD;
	for(int i = 1; i <= N; i++) {
		int t = A[i - 1];
		if(i > 1) t = (t + A[i - 2]) % MOD;
		add[i] = (A[i] + MOD - t) % MOD;
		cnt += !!add[i];
	}
	while(Q--) {
		char c; int l, r;
		scanf(" %c%d%d", &c, &l, &r);
		int t = (c == 'A' ? 1 : -1);

		cnt -= !!add[l];
		add[l] = (add[l] + MOD + t * 1) % MOD;
		cnt += !!add[l];

		if(r < N) {
			cnt -= !!add[r + 1];
			add[r + 1] = ((ll)add[r + 1] + MOD - t * F[r - l + 2]) % MOD;
			cnt += !!add[r + 1];
		}
		if(r < N - 1) {
			cnt -= !!add[r + 2];
			add[r + 2] = ((ll)add[r + 2] + MOD - t * F[r - l + 1]) % MOD;
			cnt += !!add[r + 2];
		}
		puts(cnt ? "NO" : "YES");
		// for(int i = 1; i <= N; i++) printf("%d ", add[i]); puts("");
	}

	return 0;
}