#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
set<int> S;
vector<pii> E;
int cnt[303030];
int D[303030];
int path[303030];
int ans[303030];
vector<int> adj[303030];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int x, l, r; scanf("%d%d%d", &x, &l, &r);
		E.emplace_back(l, x);
		E.emplace_back(r + 1, -x);
	}

	sort(E.begin(), E.end());

	S.insert(0); S.insert(N + 1);
	adj[N + 1].push_back(0);

	for(auto &i : E) {
		int x = abs(i.second);
		if(i.second > 0) {
			cnt[x]++;
			if(cnt[x] == 1) {
				S.insert(x);
				auto it = S.find(x);
				int y = *(--it);
				adj[max(x, y)].push_back(min(x, y));
				++it; y = *(++it);
				adj[max(x, y)].push_back(min(x, y));
			}
		}
		else {
			cnt[x]--;
			if(!cnt[x]) S.erase(x);
		}
	}

	for(int i = 1; i <= N + 1; i++) D[i] = -10101010;
	for(int i = 1; i <= N + 1; i++) {
		for(int j : adj[i]) {
			if(D[j] + 1 > D[i]) {
				D[i] = D[j] + 1;
				path[i] = j;
			}
		}
	}

	int now = N + 1;
	while(now) {
		ans[now] = 1;
		now = path[now];
	}

	printf("%d\n", N - (D[N + 1] - 1));
	for(int i = 1; i <= N; i++) if(!ans[i]) printf("%d ", i); puts("");

	return 0;
}