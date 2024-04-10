#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
pii A[202020];
vector<int> L, R;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		L.clear(); R.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &A[i].first, &A[i].second);
			L.push_back(A[i].first);
			R.push_back(A[i].second);
		}
		sort(L.begin(), L.end());
		sort(R.begin(), R.end());
		int ans = N;
		for(int i = 1; i <= N; i++) {
			int l, r; tie(l, r) = A[i];
			int t1 = N - (lower_bound(L.begin(), L.end(), r + 1) - L.begin());
			int t2 = lower_bound(R.begin(), R.end(), l) - R.begin();
			ans = min(ans, t1 + t2);
		}
		printf("%d\n", ans);
	}
	return 0;
}