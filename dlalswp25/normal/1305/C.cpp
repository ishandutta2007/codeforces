#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[202020];
ll B[202020];
int cnt[1010];

int N, M;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		B[i] = A[i] % M;
		cnt[B[i]]++;
	}

	for(int i = 0; i < M; i++) {
		if(cnt[i] > 1) { puts("0"); return 0; }
	}

	ll ans = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			ans = ans * abs(A[i] - A[j]) % M;
		}
	}
	printf("%lld\n", ans);

	return 0;
}