#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

multiset<pii> y;
vector<pii> v[202020];
int N;
int H[202020];
int W[202020];
int ans[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		y.clear();
		scanf("%d", &N);

		vector<int> tmp;
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &W[i], &H[i]);
			if(W[i] < H[i]) swap(W[i], H[i]);
			tmp.push_back(W[i]);
		}
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		for(int i = 1; i <= N; i++) W[i] = lower_bound(tmp.begin(), tmp.end(), W[i]) - tmp.begin() + 1;

		for(int i = 1; i <= N; i++) {
			v[i].clear();
			ans[i] = -1;
		}
		for(int i = 1; i <= N; i++) v[W[i]].emplace_back(H[i], i);

		for(int i = 1; i <= N; i++) {
			for(pii j : v[i]) {
				auto it = y.lower_bound(pii(j.first, 0));
				if(it == y.begin()) continue;
				it--;
				ans[j.second] = it -> second;
			}
			for(pii j : v[i]) {
				y.insert(j);
			}
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}