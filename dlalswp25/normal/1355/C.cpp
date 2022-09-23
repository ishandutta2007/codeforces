#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll X[1010101];
ll S[1010101];

int A, B, C, D;

int main() {
	scanf("%d%d%d%d", &A, &B, &C, &D);
	int mn = min(B - A, C - B);
	X[A + B] = X[B + C] = 1;
	for(int i = 1; i <= mn; i++) X[A + B + i] = X[A + B + i - 1] + 1;
	for(int i = mn + 1; A + B + i < B + C; i++) X[A + B + i] = X[A + B + mn];
	for(int i = 1; i <= mn; i++) X[B + C - i] = X[B + C - i + 1] + 1;

	// for(int i = 1; i <= B + C; i++) printf("%d ", X[i]); puts("");

	for(int i = 1000000; i >= 0; i--) S[i] = S[i + 1] + X[i];

	ll ans = 0;
	for(int i = C; i <= D; i++) {
		ans += S[i + 1];
	}
	printf("%lld\n", ans);

	return 0;
}