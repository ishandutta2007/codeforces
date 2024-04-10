#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[1010];
int C[1010][1010];
vector<int> qv;
int Eid;
int now;
int cnt;
int ansX, ansY;

int query() {
	sort(qv.begin(), qv.end());
	qv.erase(unique(qv.begin(), qv.end()), qv.end());
	printf("? %d ", qv.size());
	for(int i : qv) printf("%d ", i); puts("");
	fflush(stdout);
	qv.clear();
	int ret; scanf("%d", &ret);
	return ret;
}

void dfs(int v, int p) {
	for(int i : adj[v]) {
		if(i == p) continue;
		if(C[v][i] == Eid && cnt) {
			C[v][i] = now;
			ansX = v; ansY = i;
			qv.push_back(v); qv.push_back(i);
			cnt--;
		}
		dfs(i, v);
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for(int i = 1; i <= N; i++) qv.push_back(i);
	int M = query();

	int left = N - 1;
	while(left > 1) {
		++now;
		int t = left / 2; cnt = t;
		dfs(1, 0);
		int m = query();
		if(m == M) {
			left = t;
			Eid = now;
		}
		else {
			left -= t;
		}
	}

	++now;
	cnt = 1;
	dfs(1, 0);
	printf("! %d %d\n", ansX, ansY);
	fflush(stdout);

	return 0;
}