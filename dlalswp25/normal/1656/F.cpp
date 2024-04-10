#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
const int MX = 2000000;
 
int N;
int A[202020];
 
ll w(int i, int j, int t) {
	return (ll)A[i] * A[j] + (ll)t * (A[i] + A[j]);
}
 
ll f(int t) {
	ll ret = 0;
	if(A[1] + t >= 0) {
		for(int i = 2; i <= N; i++) ret += w(1, i, t);
		return ret;
	}
	if(A[N] + t <= 0) {
		for(int i = 1; i < N; i++) ret += w(i, N, t);
		return ret;
	}
	ret = w(1, N, t);
	for(int i = 2; i < N; i++) {
		if(A[i] + t >= 0) ret += w(1, i, t);
		else ret += w(i, N, t);
	}
	return ret;
}
 
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		ll s = 0;
		for(int i = 1; i < N; i++) s += (A[i] + A[N]);
		if(s < 0) { puts("INF"); continue; }
		s = 0;
		for(int i = 2; i <= N; i++) s += (A[1] + A[i]);
		if(s > 0) { puts("INF"); continue; }

		int l = -MX, r = MX;
		while(r - l > 2) {
			int m1 = (l + l + r) / 3;
			int m2 = (l + r + r) / 3;
			if(f(m1) > f(m2)) r = m2;
			else l = m1;
		}
		ll ans = -1LL << 60;
		for(int i = l; i <= r; i++) ans = max(ans, f(i));
		printf("%lld\n", ans);
	}
	return 0;
}