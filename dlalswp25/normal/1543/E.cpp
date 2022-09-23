#include <bits/stdc++.h>

using namespace std;

int N;
int A[65656];
int pos[65656];
bool chk[65656];
vector<int> adj[65656];
queue<int> q;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < 1 << N; i++) {
			adj[i].clear();
			A[i] = 0;
			chk[i] = false;
		}

		for(int i = 0; i < N * (1 << N - 1); i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		chk[0] = true;
		int b = 0;
		for(int i : adj[0]) {
			A[i] = 1 << b;
			q.push(i);
			b++;
		}

		while(q.size()) {
			int x = q.front(); q.pop();
			if(chk[x]) continue;
			chk[x] = true;
			for(int i : adj[x]) {
				if(chk[i]) continue;
				A[i] |= A[x];
				q.push(i);
			}
		}

		for(int i = 0; i < 1 << N; i++) pos[A[i]] = i;

		for(int i = 0; i < 1 << N; i++) printf("%d ", pos[i]); puts("");
		bool ok = true;
		int tmp = N;
		while(tmp) {
			if(tmp & 1) {
				if(tmp > 1) ok = false;
			}
			tmp >>= 1;
		}
		if(!ok) puts("-1");
		else {
			for(int i = 0; i < 1 << N; i++) {
				int c = 0;
				for(int j = 0; j < N; j++) {
					if(A[i] & 1 << j) c ^= j;
				}
				printf("%d ", c);
			}
			puts("");
		}
	}
	return 0;
}