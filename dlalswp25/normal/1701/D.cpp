#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> E[505050];
int ans[505050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) E[i].clear();
		for(int i = 1; i <= N; i++) {
			int b; scanf("%d", &b);
			if(!b) {
				E[i + 1].emplace_back(N, i);
			}
			else {
				E[i / (b + 1) + 1].emplace_back(i / b, i);
			}
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for(int i = 1; i <= N; i++) {
			for(auto& j : E[i]) pq.push(j);
			pii t = pq.top(); pq.pop();
			ans[t.second] = i;
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}