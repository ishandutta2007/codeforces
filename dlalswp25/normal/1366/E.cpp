#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
int A[202020];
int B[202020];

void no() {
	puts("0");
	exit(0);
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= M; i++) scanf("%d", &B[i]);

	int p = N;
	ll ans = 1;
	for(int i = M; i > 1; i--) {
		int c = 0;
		bool f = false;
		for(int j = p; j >= 1; j--) {
			if(A[j] < B[i]) { p = j; break; }
			if(A[j] == B[i]) f = true;
			if(f) c++;
		}
		ans = ans * c % MOD;
		// printf("%d %d %lld\n", i, p, ans);
	}

	bool ok = false;
	for(int i = p; i >= 1; i--) {
		if(B[1] > A[i]) no();
		if(B[1] == A[i]) ok = true;
	}

	if(!ok) no();
	printf("%lld\n", ans);

	return 0;
}