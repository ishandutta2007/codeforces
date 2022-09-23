#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll B[202020];
int A[202020];

int cnt[70];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &B[i]);

	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 62; j++) {
			if(B[i] & (1LL << j)) break;
			A[i]++;
		}
	}

	for(int i = 1; i <= N; i++) cnt[A[i]]++;

	int mx = 0, mxi;
	for(int i = 0; i < 62; i++) if(mx < cnt[i]) { mx = cnt[i]; mxi = i; }

	printf("%d\n", N - mx);
	for(int i = 1; i <= N; i++) if(A[i] != mxi) printf("%lld ", B[i]);
	puts("");

	return 0;
}