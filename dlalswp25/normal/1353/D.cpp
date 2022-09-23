#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

priority_queue<pii> pq;
int N;
int A[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		while(pq.size()) pq.pop();
		scanf("%d", &N);
		pq.push({N, -1});
		for(int i = 1; i <= N; i++) {
			pii x = pq.top(); pq.pop();
			int l = -x.second; int r = x.first + l - 1;
			int m = (l + r) / 2;
			A[m] = i;
			pq.push({m - l, -l});
			pq.push({r - m, -(m + 1)});
		}
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}