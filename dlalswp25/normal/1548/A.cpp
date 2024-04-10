#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
int state[202020];
set<int> adj[202020];

int mx(int i) {
	return *(--adj[i].end());
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) adj[i].insert(0);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].insert(b);
		adj[b].insert(a);
	}

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(mx(i) < i) { state[i] = 1; ans++; }
	}

	scanf("%d", &Q);
	while(Q--) {
		int t; scanf("%d", &t);
		if(t == 3) { printf("%d\n", ans); continue; }
		int a, b; scanf("%d%d", &a, &b);
		if(t == 1) {
			adj[a].insert(b); adj[b].insert(a);
		}
		else {
			adj[a].erase(b); adj[b].erase(a);
		}

		int bef = state[a]; state[a] = (mx(a) < a);
		ans += state[a] - bef;
		bef = state[b]; state[b] = (mx(b) < b);
		ans += state[b] - bef;	
	}
	return 0;
}