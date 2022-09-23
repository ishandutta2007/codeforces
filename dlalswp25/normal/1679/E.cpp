#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int K = 17;
const ll MOD = 998244353;

int N, Q, M;
char A[1010];

ll X[18][131313];
ll pw[18][1010];
char S[20];

void f(int l, int r) {
	int s = 0;
	int cnt = M;
	for(; 1 <= l && r <= N; l--, r++) {
		cnt -= (A[l] == '?') + (l != r && A[r] == '?');
		if(A[l] != '?' && A[r] != '?') {
			if(A[l] != A[r]) return;
		}
		else if(A[l] == '?' && A[r] == '?') cnt++;
		else if(A[l] == '?') s |= 1 << A[r] - 'a';
		else s |= 1 << A[l] - 'a';

		for(int i = 1; i <= K; i++) {
			X[i][s] = (X[i][s] + pw[i][cnt]) % MOD;
		}
	}
}

int main() {
	scanf("%d", &N);
	scanf("%s", A + 1);

	for(int i = 1; i <= N; i++) M += A[i] == '?';

	for(int i = 1; i <= K; i++) {
		pw[i][0] = 1;
		for(int j = 1; j <= N; j++) {
			pw[i][j] = pw[i][j - 1] * i % MOD;
		}
	}

	for(int i = 1; i <= N; i++) f(i, i);
	for(int i = 1; i < N; i++) f(i, i + 1);

	for(int k = 1; k <= K; k++) {
		for(int i = 0; i < K; i++) {
			for(int j = 0; j < 1 << K; j++) {
				if(j & 1 << i) {
					X[k][j] = (X[k][j] + X[k][j ^ 1 << i]) % MOD;
				}
			}
		}
	}

	scanf("%d", &Q);
	while(Q--) {
		scanf("%s", S);
		int T = strlen(S);
		int s = 0;
		for(int i = 0; i < T; i++) {
			if(S[i] == '?') continue;
			s |= 1 << S[i] - 'a';
		}
		printf("%lld\n", X[T][s]);
	}
	return 0;
}