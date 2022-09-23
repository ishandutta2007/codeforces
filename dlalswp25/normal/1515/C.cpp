#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N, M, X;
int A[101010];
int ans[101010];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		while(pq.size()) pq.pop();
		scanf("%d%d%d", &N, &M, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) pq.emplace(0, i);
		for(int i = 1; i <= N; i++) {
			pii t = pq.top(); pq.pop();
			ans[i] = t.second;
			t.first += A[i];
			pq.emplace(t);
		}
		puts("YES");
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}