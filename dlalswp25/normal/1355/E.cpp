#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll A, R, M;
ll H[101010];
ll S[101010];

ll ans;

ll f(ll x) {
	return S[N] - x * N;
}

void g1(int i, ll l, ll r) {
	if(l > r) return;
	ll x;
	if(M * i - R * N > 0) {
		x = l;
	}
	else x = r;

	ans = min(ans, M * (i * x - S[i]) + R * (S[N] - x * N));
}

void g2(int i, ll l, ll r) {
	if(l > r) return;
	ll x;
	if(A * N - (N - i) * M > 0) {
		x = l;
	}
	else x = r;

	ans = min(ans, M * (S[N] - S[i] - (N - i) * x) + A * (N * x - S[N]));	
}

int main() {
	scanf("%d%lld%lld%lld", &N, &A, &R, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &H[i]);
	}
	sort(H + 1, H + N + 1);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + H[i];

	M = min(M, A + R);

	ans = A * (N * H[N] - S[N]);

	for(int i = 1; i < N; i++) {
		if(f(H[i + 1] - 1) >= 0) {
			g1(i, H[i], H[i + 1] - 1);
		}
		else if(f(H[i]) < 0) {
			g2(i, H[i], H[i + 1] - 1);
		}
		else {
			ll t = S[N] / N;
			g1(i, H[i], t);
			g2(i, t + 1, H[i + 1] - 1);
		}
	}
	printf("%lld\n", ans);

	return 0;
}