#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int T;

vector<pii> adj[301010];
vector<int> ind;
vector<int> ed;
bool chk[301010];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		N *= 3;
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back({b, i});
			adj[b].push_back({a, i});
		}

		for(int i = 1; i <= N; i++) {
			if(chk[i]) continue;
			int x = 0, idx;
			for(pii j : adj[i]) {
				if(chk[j.first]) continue;
				x = j.first; idx = j.second; break;
			}
			chk[i] = true;
			if(!x) ind.push_back(i);
			else {
				chk[x] = true;
				ed.push_back(idx);
			}
		}

		if(ed.size() >= N / 3) {
			puts("Matching");
			for(int i = 0; i < N / 3; i++) printf("%d ", ed[i]); puts("");
		}
		else {
			puts("IndSet");
			for(int i = 0; i < N / 3; i++) printf("%d ", ind[i]); puts("");
		}
		ed.clear();
		ind.clear();
		for(int i = 1; i <= N; i++) adj[i].clear();
		for(int i = 1; i <= N; i++) chk[i] = false;
	}
	return 0;
}