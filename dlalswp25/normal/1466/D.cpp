#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

priority_queue<int> pq;

int N;
int deg[101010];
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) deg[i] = 0;
		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			deg[a]++; deg[b]++;
		}

		ll ans = 0;
		for(int i = 1; i <= N; i++) ans += A[i];

		while(pq.size()) pq.pop();
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < deg[i] - 1; j++) {
				pq.push(A[i]);
			}
		}

		for(int i = 1; i < N; i++) {
			printf("%lld ", ans);
			if(pq.size()) {
				ans += pq.top(); pq.pop();
			}
		}
		puts("");
	}
	return 0;
}