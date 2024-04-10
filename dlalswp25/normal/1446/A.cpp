#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

int N;
ll W;
pii A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &W);
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + N + 1);
		ll s = 0;
		vector<int> ans;
		for(int i = N; i >= 1; i--) {
			if(A[i].first > W) continue;
			s += A[i].first;
			ans.push_back(A[i].second);
			if(s >= (W + 1) / 2) break;
		}
		if(s < (W + 1) / 2) puts("-1");
		else {
			printf("%d\n", ans.size());
			for(int i : ans) printf("%d ", i); puts("");
		}
	}
	return 0;
}