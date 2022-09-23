#include <bits/stdc++.h>

using namespace std;

set<int> adj[101010];
vector<int> rev[101010];
int N;

bool ok[101010];
set<int> S;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			ok[i] = false;
			int k; scanf("%d", &k);
			for(int j = 1; j <= k; j++) {
				int x; scanf("%d", &x);
				adj[i].insert(x);
				rev[x].push_back(i);
			}
			S.insert(i);
		}

		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			if(adj[i].size() == 0) continue;
			cnt++;
			int y = *(adj[i].begin());
			ok[i] = true;
			for(int j : rev[y]) {
				adj[j].erase(y);
			}
			S.erase(y);
		}

		if(cnt == N) puts("OPTIMAL");
		else {
			puts("IMPROVE");
			for(int i = 1; i <= N; i++) {
				if(!ok[i]) {
					printf("%d ", i);
					break;
				}
			}
			printf("%d\n", *S.begin());
		}

		for(int i = 1; i <= N; i++) {
			ok[i] = false;
			adj[i].clear();
			rev[i].clear();
		}
		S.clear();
	}
	return 0;
}