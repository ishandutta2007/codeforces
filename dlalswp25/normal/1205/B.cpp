#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll A[101010];
int N;

vector<int> adj[101010];
vector<int> v;
queue<int> q;

int d[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);

	for(int i = 0; i <= 60; i++) {
		vector<int> tmp;
		for(int j = 1; j <= N; j++) {
			if(A[j] & ((1LL) << i)) tmp.push_back(j);
		}
		if(tmp.size() >= 3) { puts("3"); return 0; }
		if(tmp.size() == 2) {
			adj[tmp[0]].push_back(tmp[1]);
			adj[tmp[1]].push_back(tmp[0]);
		}
	}

	for(int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	for(int i = 1; i <= N; i++) if(adj[i].size() > 1) v.push_back(i);

	int ans = 987654321;

	for(int s : v) {
		for(int j = 1; j <= N; j++) d[j] = 0;
		d[s] = 1; q.push(s);
		while(q.size()) {
			int now = q.front(); q.pop();
			for(int i : adj[now]) {
				if(d[i]) {
					if(d[i] >= d[now]) ans = min(ans, d[i] + d[now] - 1);
				}
				else {
					d[i] = d[now] + 1;
					q.push(i);
				}
			}
		}
	}
	if(ans == 987654321) puts("-1");
	else printf("%d\n", ans);

	return 0;
}