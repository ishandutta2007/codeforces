#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll K;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ll L = A[1], R = A[1];
		bool ok = true;
		for(int i = 2; i <= N; i++) {
			ll l = A[i], r = (1LL << 60);
			r = min(r, A[i] + K - 1);
			l = max(l, L - K + 1);
			r = min(r, R + K - 1);
			if(r < l) { ok = false; break; }
			L = l; R = r;
		}
		if(!ok) puts("NO");
		else if(L != A[N]) puts("NO");
		else puts("YES");
	}
	return 0;
}