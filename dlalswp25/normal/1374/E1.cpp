#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll T[202020];
int X[202020];
int Y[202020];

int an, bn, cn;
ll A[202020];
ll B[202020];
ll C[202020];

int main() {
	int N, K; scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
		if(X[i] && Y[i]) C[++cn] = T[i];
		else if(X[i]) A[++an] = T[i];
		else if(Y[i]) B[++bn] = T[i];
	}

	if(an + cn < K || bn + cn < K) {
		puts("-1");
		return 0;
	}

	sort(A + 1, A + an + 1);
	sort(B + 1, B + bn + 1);
	sort(C + 1, C + cn + 1);

	ll ans = 1LL << 60;
	ll sa = 0, sb = 0, sc = 0;

	for(int i = 1; i <= K; i++) sa += A[i];
	for(int i = 1; i <= K; i++) sb += B[i];

	for(int i = K; i >= 0; i--) {
		bool ok = true;
		if(i > an || i > bn) ok = false;
		if(K - i > cn) ok = false;
		if(ok) ans = min(ans, sa + sb + sc);
		sa -= A[i];
		sb -= B[i];
		sc += C[K - i + 1];
	}
	printf("%lld\n", ans);
	return 0;
}