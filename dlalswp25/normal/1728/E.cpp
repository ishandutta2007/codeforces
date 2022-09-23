#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 1LL << 60;

int N, Q;
pii A[303030];
ll SA[303030];
ll SB[303030];

ll f(ll b) {
	if(b < 0 || b > N) return -INF;
	return SB[b] + SA[N] - SA[b];
}

int egcd(int a, int b, int& s, int& t) {
	s = 1; t = 0;
	int ns = 0, nt = 1;
	while(b) {
		int q = a / b; a %= b; swap(a, b);
		int tmp;
		tmp = ns; ns = s - ns * q; s = tmp;
		tmp = nt; nt = t - nt * q; t = tmp;
	}
	return a;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i].first, &A[i].second);
	sort(A + 1, A + N + 1, [&](pii a, pii b) {
		return a.first - a.second < b.first - b.second;
	});
	for(int i = 1; i <= N; i++) SA[i] = SA[i - 1] + A[i].first;
	for(int i = 1; i <= N; i++) SB[i] = SB[i - 1] + A[i].second;
	int p = 0;
	for(int i = 1; i <= N; i++) if(A[i].first < A[i].second) p++;
	scanf("%d", &Q);
	while(Q--) {
		int x, y; scanf("%d%d", &x, &y);
		int s, t;
		int g = egcd(x, y, s, t);
		if(N % g) { puts("-1"); continue; }
		ll b = (ll)t * (N / g) * y;
		ll d = (ll)x / g * y;
		ll steps = (p - b) / d;
		ll q = b + steps * d;
		ll ans = max({f(q), f(q - d), f(q + d)});
		if(ans == -INF) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}