#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int F[101010];
int N, M;
int A[101010];
int pos[101010];

void upd(int x, int v) {
	for(int i = x; i <= N; i += i&-i) F[i] += v;
}
int query(int x) {
	int ret = 0;
	for(int i = x; i; i -= i&-i) ret += F[i];
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) { scanf("%d", &A[i]); pos[A[i]] = i; }

		ll ans = 0;
		for(int i = 1; i <= M; i++) {
			int b; scanf("%d", &b);
			b = pos[b];
			if(query(N) - query(b) > 0) ans++;
			else ans += (2 * (b - query(b - 1)) - 1);
			upd(b, 1);
			// printf("%d %lld\n", i, ans);
		}
		printf("%lld\n", ans);
		for(int i = 1; i <= N; i++) F[i] = 0;
	}
	return 0;
}