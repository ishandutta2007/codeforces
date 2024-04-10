#include <bits/stdc++.h>

using namespace std;

vector<int> V[202];
vector<int> rev[202];
int N;

int ans[202];
int cnt[202];
bool chk[202];
int pos[202];

queue<int> q;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i < N; i++) {
			int K; scanf("%d", &K);
			for(int j = 0; j < K; j++) {
				int x; scanf("%d", &x);
				V[i].push_back(x);
				rev[x].push_back(i);
			}
		}
		// puts("input");

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				cnt[j] = pos[j] = 0;
			}
			while(q.size()) q.pop();

			ans[1] = i;
			pos[i] = 1;
			for(int j : rev[i]) {
				cnt[j]++;
				if(V[j].size() == cnt[j] + 1) {
					q.push(j);
				}
			}

			bool ok = true;
			for(int j = 2; j <= N; j++) {
				if(q.size() != 1) {
					ok = false; break;
				}
				int v = q.front(); q.pop();

				for(int k : V[v]) {
					if(!pos[k]) continue;
					if(pos[k] && pos[k] <= j - (int)V[v].size()) {
						ok = false; break;
					}
				}
				if(!ok) break;

				for(int k : V[v]) {
					if(!pos[k]) {
						pos[k] = j;
						ans[j] = k;
						for(int l : rev[k]) {
							cnt[l]++;
							if(V[l].size() == cnt[l] + 1) {
								q.push(l);
							}
						}

						break;
					}
				}
			}

			if(!ok) continue;
			for(int j = 1; j <= N; j++) printf("%d ", ans[j]); puts("");
			break;
		}

		for(int i = 1; i <= N; i++) {
			V[i].clear();
			rev[i].clear();
		}
	}

	return 0;
}