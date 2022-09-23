#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, K;
int A[202020];
bool chk[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		priority_queue<pii> pq;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			pq.emplace(A[i] + i, i);
		}
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 1; i <= K; i++) {
			pii t = pq.top(); pq.pop();
			chk[t.second] = true;
		}
		ll ans = 0;
		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			if(chk[i]) { cnt++; continue; }
			ans += A[i] + cnt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}