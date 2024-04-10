#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D[3030][3030];
int N;
int S[3030];
int T[3030];

int Z[3030];
int mlen[3030];
ll ans[3030];

const ll MOD = 1000000007;

bool valid(int i) {
	if(i <= 3) return true;
	int a = S[i - 3], b = S[i - 2], c = S[i - 1], d = S[i];
	if(!a && !b && c && d) return false;
	if(!a && b && !c && d) return false;
	if(a && b && c && !d) return false;
	if(a && b && c && d) return false;
	return true;
}

void fz(int n) {
	for(int i = 0; i < n; i++) Z[i] = -1;
	int l = -1, r = -1;
	for(int i = 1; i < n; i++) {
		if(i <= r) Z[i] = min(r - i, Z[i - l]);
		while(i + Z[i] + 1 < n && T[i + Z[i] + 1] == T[Z[i] + 1]) Z[i]++;
		if(r < i + Z[i]) { r = i + Z[i]; l = i; }
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &S[i]);

	for(int i = 0; i <= N; i++) D[i][0] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= 4; j++) {
			for(int k = j; k <= i; k++) {
				if(j == 4 && !valid(i)) break;
				D[i][k] = (D[i][k] + D[i - j][k - j]) % MOD;
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= i; j++) T[j - 1] = S[j];
		reverse(T, T + i);
		fz(i);
		// printf("%d\n", i);
		// for(int j = 1; j <= i; j++) printf("%d ", Z[j]); puts("");
		mlen[i] = 1;
		for(int j = 1; j < i; j++) mlen[i] = max(mlen[i], Z[j] + 2);
	}

	//for(int i = 1; i <= N; i++) printf("%d ", mlen[i]);

	for(int i = 1; i <= N; i++) {
		ans[i] = ans[i - 1];
		for(int j = mlen[i]; j <= i; j++) ans[i] = (ans[i] + D[i][j]) % MOD;
	}
	for(int i = 1; i <= N; i++) printf("%lld\n", ans[i]);

	return 0;
}