#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[201010];
ll B[201010];
int N, M, K;
int ta, tb;

int main() {
	scanf("%d%d%d%d%d", &N, &M, &ta, &tb, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for(int i = 1; i <= M; i++) scanf("%lld", &B[i]);
	for(int i = 1; i <= N; i++) A[i] += ta;
	A[N + 1] = A[N] + 2000000000;

	int p = M + 1;
	if(K > N) {
		puts("-1");
		return 0;
	}

	ll ans = 0;

	for(int i = K; i >= 0; i--) {
		while(p > 1 && B[p - 1] >= A[i + 1]) p--;
		int nxt = p + (K - i);
		if(nxt > M) {
			puts("-1");
			return 0;
		}
		ans = max(ans, tb + B[nxt]);
	}
	printf("%lld\n", ans);

	return 0;
}