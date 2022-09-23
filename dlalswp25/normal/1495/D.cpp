#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
ll ans[404][404];
vector<int> adj[404];
queue<int> q;
int DX[404];
int DY[404];
int DZ[404];
int in[404];

vector<int> W[808];

void bfs(int s, int *D) {
	while(q.size()) q.pop();
	q.push(s);
	for(int i = 1; i <= N; i++) D[i] = 0;
	D[s] = 1;
	while(q.size()) {
		int x = q.front(); q.pop();
		for(int i : adj[x]) {
			if(!D[i]) {
				D[i] = D[x] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) {
		for(int j = i; j <= N; j++) {
			bfs(i, DX); bfs(j, DY);
			int v = i;
			bool ok = true;
			while(v != j) {
				int nxt = 0;
				for(int k : adj[v]) {
					if(DY[k] == DY[v] - 1) {
						if(nxt) ok = false;
						else nxt = k;
					}
				}
				if(!ok) break;
				v = nxt;
			}
			if(!ok) continue;

			for(int k = 1; k <= N; k++) W[DX[k] + DY[k]].push_back(k);
			int d = DX[j] + DY[j];

			ans[i][j] = 1;
			for(int k = d + 1; k <= 2 * N + 2; k++) {
				for(int l : W[k]) {
					int deg = 0;
					for(int m : adj[l]) {
						if(DX[m] == DX[l] - 1 && DY[m] == DY[l] - 1) deg++;
					}
					ans[i][j] = ans[i][j] * deg % MOD;
				}
			}

			for(int k = 1; k <= N; k++) W[DX[k] + DY[k]].clear();
		}
	}

	for(int i = 1; i <= N; i++) for(int j = 1; j < i; j++) ans[i][j] = ans[j][i];
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%lld ", ans[i][j]);
		}
		puts("");
	}

	return 0;
}