#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll L, R;

pii next_pair(pii x) {
	int a = x.first, b = x.second;
	if(a == N - 1 && b == N) return {-1, -1};
	if(b == N) return {a + 1, a + 2};
	return {a, b + 1};
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%lld%lld", &N, &L, &R);

		L--; R--;
		ll K = L;

		ll X = R - L + 1;

		int sa = 1, sb = 2;

		for(int i = 1; i < N; i++) {
			if(K < 2 * (N - i)) break;
			K -= 2 * (N - i);
			sa = i + 1;
		}

		if(sa >= N) {
			printf("1\n");
			continue;
		}

		sb = sa + 1;
		for(int i = sa + 1; i < N; i++) {
			if(K < 2) break;
			K -= 2;
			sb = i + 1;
		}

		// printf("%d %d\n", sa, sb);

		if(K == 1) {
			printf("%d ", sb); X--;
			tie(sa, sb) = next_pair({sa, sb});
		}

		while(X >= 2) {
			X -= 2;
			printf("%d %d ", sa, sb);
			tie(sa, sb) = next_pair({sa, sb});
		}

		if(X == 1) {
			if(sa == -1) printf("1\n");
			else printf("%d\n", sa);
		}
		else puts("");
	}
	return 0;
}