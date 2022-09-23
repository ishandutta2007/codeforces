#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N, W;
ll D[1010101];
int A[1010101];

set<int> S;
priority_queue<pii> pq;

int main() {
	scanf("%d%d", &N, &W);

	for(int i = 1; i <= N; i++) {
		int k; scanf("%d", &k);
		while(pq.size()) pq.pop();
		S.clear();

		for(int j = 1; j <= k; j++) {
			scanf("%d", &A[j]);
			pq.push({A[j], j});
		}

		while(pq.size()) {
			pii t = pq.top(); pq.pop();
			int idx = t.second;
			int l, r;

			auto it = S.lower_bound(idx);
			if(it != S.end()) r = min((*it), idx + W - k + 1);
			else r = idx + W - k + 1;

			it = S.lower_bound(idx);
			if(it == S.begin()) l = idx;
			else {
				it--;
				l = max((*it) + W - k + 1, idx);
			}

			if(t.first < 0) {
				l = max(l, W - k + 1);
				r = min(r, k + 1);
			}

			if(l <= r) {
				D[r] -= t.first;
				D[l] += t.first;
			}
			S.insert(idx);
			//printf("%d %d\n", l, r);
		}
	}

	for(int i = 1; i <= W; i++) D[i] += D[i - 1];
	for(int i = 1; i <= W; i++) printf("%lld ", D[i]); puts("");

	return 0;
}