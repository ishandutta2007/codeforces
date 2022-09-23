#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
ll A[303030];
int type[303030];

int get_type(int i) {
	if(i < 1 || i > N) return 0;
	if(i == 1) return A[1] > A[2];
	if(i == N) return A[N] > A[N - 1];
	if(A[i - 1] < A[i] && A[i] > A[i + 1]) return 1;
	else if(A[i - 1] > A[i] && A[i] < A[i + 1]) return -1;
	return 0;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i <= N; i++) type[i] = get_type(i);
		ll ans = 0;
		for(int i = 1; i <= N; i++) ans += type[i] * A[i];
		type[N + 1] = 0;
		printf("%lld\n", ans);

		while(Q--) {
			int l, r; scanf("%d%d", &l, &r);
			if(N == 1) { printf("%lld\n", A[1]); continue; }
			set<int> S;
			for(int i = l - 1; i <= l + 1; i++) S.insert(i);
			for(int i = r - 1; i <= r + 1; i++) S.insert(i);
			for(int i : S) ans -= type[i] * A[i];

			swap(A[l], A[r]);

			for(int i : S) {
				type[i] = get_type(i);
				ans += type[i] * A[i];
			}

			printf("%lld\n", ans);
		}
	}
	return 0;
}