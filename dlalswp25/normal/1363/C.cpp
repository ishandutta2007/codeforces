#include <bits/stdc++.h>

using namespace std;

int N, X;
vector<int> adj[1010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) adj[i].clear();

		for(int i = 1; i < N; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if(N == 1 || adj[X].size() == 1) {
			puts("Ayush");
			continue;
		}

		int t = N;
		if(t & 1) puts("Ashish");
		else puts("Ayush");
	}
	return 0;
}