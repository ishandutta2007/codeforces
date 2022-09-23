#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int INF = 1010101010;

int N, M;
int D[505050];
int A[505050];

vector<int> adj[505050];
queue<int> q;
map<pii, int> mp;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		adj[b].push_back(a);
		mp[{a, b}] |= (1 << c);
	}

	for(int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	for(int i = 1; i <= N; i++) A[i] = -1;
	q.push(N); A[N] = 0;
	for(int i = 1; i < N; i++) D[i] = INF;

	while(q.size()) {
		int x = q.front(); q.pop();
		// printf("%d\n", x);
		for(int i : adj[x]) {
			if(D[i] != INF) continue;
			int t = mp[{i, x}];
			// printf("%d %d %d\n", x, i, t);
			// printf("%d\n", A[i]);
			if(A[i] != -1) {
				if(t & 1 << A[i]) {
					D[i] = D[x] + 1;
					q.push(i);
				}
			}
			else if(t == 3) {
				A[i] = 0;
				D[i] = D[x] + 1;
				q.push(i);
			}
			else {
				if(t == 1) A[i] = 1;
				else A[i] = 0;
			}
		}
	}

	if(D[1] == INF) puts("-1");
	else printf("%d\n", D[1]);
	for(int i = 1; i <= N; i++) printf("%d", A[i] == -1 ? 0 : A[i]); puts("");
	return 0;
}