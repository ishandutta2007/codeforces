#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[3030];

vector<int> v[3030];
queue<int> q;

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", A + 1);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < N; j++) {
			if(A[j] == 'R' && A[j + 1] == 'L') {
				v[i].push_back(j);
				q.push(j);
			}
		}
		if(v[i].size() == 0) break;

		while(q.size()) {
			int x = q.front(); q.pop();
			// printf("%d %d\n", i, x);
			swap(A[x], A[x + 1]);
		}

		// for(int j = 1; j <= N; j++) printf("%c", A[j]); puts("");
	}

	int M = 0;
	int s = 0;
	for(int i = 1; i <= N; i++) {
		if(v[i].size() == 0) break;
		s += v[i].size();
		M = i;
	}

	// printf("%d %d\n", M, s);

	if(M > K || s < K) { puts("-1"); return 0; }

	int rem = K - M;
	for(int i = 1; i <= M; i++) {
		if(!rem) {
			printf("%d ", v[i].size());
			for(int j : v[i]) printf("%d ", j); puts("");
		}
		else {
			int p = 0;
			while(rem && p < v[i].size()) {
				printf("1 %d\n", v[i][p]);
				p++; if(p < v[i].size()) rem--;
			}
			if(!rem && p < v[i].size()) {
				printf("%d ", (int)v[i].size() - p);
				for(int j = p; j < v[i].size(); j++) printf("%d ", v[i][j]); puts("");
			}
		}
	}

	return 0;
}