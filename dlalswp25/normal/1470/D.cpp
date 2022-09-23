#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[303030];
vector<int> ans;
queue<int> q;
bool chk[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans.clear();
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) { adj[i].clear(); chk[i] = false; }
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		while(q.size()) q.pop();

		int tot = 1;
		chk[1] = true;
		ans.push_back(1);

		for(int i : adj[1]) {
			chk[i] = true;
			q.push(i);
			tot++;
		}

		while(q.size() && tot < N) {
			int x = q.front(); q.pop();
			for(int i : adj[x]) {
				if(chk[i]) continue;
				chk[i] = true;
				tot++;
				ans.push_back(i);
				for(int j : adj[i]) {
					if(chk[j]) continue;
					chk[j] = true;
					tot++;
					q.push(j);
				}
			}
		}
		if(tot < N) puts("NO");
		else {
			puts("YES");
			printf("%d\n", ans.size());
			for(int i : ans) printf("%d ", i); puts("");
		}
	}
	return 0;
}