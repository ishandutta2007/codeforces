#include <bits/stdc++.h>

using namespace std;

int N, M, K, W;
int pos[535353];
int A[101010];
vector<int> adj[535353];
int indeg[535353];
char S[10];
char X[130];
int pw[10];
vector<int> ans;
queue<int> q;

void add_edge(int a, int b) {
	// printf("%d->%d\n", a, b);
	adj[a].push_back(b);
	indeg[b]++;
}

int cvt() {
	int ret = 0;
	for(int i = 0; i < K; i++) {
		ret += X[S[i]] * pw[i];
	}
	return ret;
}

int main() {
	pw[0] = 1; for(int i = 1; i <= 4; i++) pw[i] = pw[i - 1] * 27;
	for(int i = 'a'; i <= 'z'; i++) X[i] = i - 'a' + 1;
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%s", S);
		A[i] = cvt();
		// printf("%d\n", A[i]);
		pos[A[i]] = i;
	}

	for(int i = 1; i <= M; i++) {
		scanf("%s", S);
		int p; scanf("%d", &p);
		int t = cvt();
		bool ok = false;
		for(int j = 0; j < 1 << K; j++) {
			for(int k = 0; k < 4; k++) if(1 << k & j) t -= pw[k] * X[S[k]];
			if(t == A[p]) ok = true;
			else if(pos[t]) add_edge(A[p], t);
			for(int k = 0; k < 4; k++) if(1 << k & j) t += pw[k] * X[S[k]];
		}
		if(!ok) { puts("NO"); return 0; }
	}

	for(int i = 0; i < pw[K]; i++) {
		if(!pos[i]) continue;
		if(!indeg[i]) q.push(i);
	}

	while(q.size()) {
		int x = q.front(); q.pop();
		ans.push_back(x);
		for(int i : adj[x]) {
			indeg[i]--;
			if(!indeg[i]) q.push(i);
		}
	}

	if(ans.size() < N) puts("NO");
	else {
		puts("YES");
		for(int i : ans) printf("%d ", pos[i]);
	}

	return 0;
}