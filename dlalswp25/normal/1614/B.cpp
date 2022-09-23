#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
pii A[202020];
int B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + N + 1);
		reverse(A + 1, A + N + 1);
		ll ans = 0;
		int p = 1;
		for(int i = 1; i <= N; i++) {
			if(i & 1) B[A[i].second] = p;
			else B[A[i].second] = -p;
			ans += (ll)A[i].first * p;
			if(~i & 1) p++;
		}
		printf("%lld\n", ans * 2);
		printf("0 ");
		for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");
	}
	return 0;
}