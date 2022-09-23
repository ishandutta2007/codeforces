#include <bits/stdc++.h>

using namespace std;

pair<int, int> A[505050];
vector<int> adj[505050];

set<int> s[505050];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i].first);
		A[i].second = i;
	}

	// sort(A + 1, A + N + 1);

	for(int i = 1; i <= N; i++) {
		for(int j : adj[i]) {
			s[i].insert(A[j].first);
			if(A[i].first == A[j].first) {
				puts("-1");
				return 0;
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		int a = 1, b = A[i].first;
		for(int j : s[i]) {
			// printf("%d %d %d\n", i, a, j);
			if(a == b) break;
			if(a == j) a++;
			else if(a < j) {
				puts("-1");
				return 0;
			}
		}
		if(a < b) {
		    puts("-1");
		    return 0;
		}
	}

	sort(A + 1, A + N + 1);

	for(int i = 1; i <= N; i++) printf("%d ", A[i].second); puts("");

	return 0;
}