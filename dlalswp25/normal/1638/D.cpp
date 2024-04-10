#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> piii;

int N, M;
int A[1010][1010];

int color(int x, int y) {
	if(x < 1 || y < 1 || x >= N || y >= M) return -1;
	set<int> S;
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 2; j++) {
			if(A[x + i][y + j] != -1) S.insert(A[x + i][y + j]);
		}
	}
	if(S.size() != 1) return -1;
	return *S.begin();
}

int main() {
	int tc = 1;
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				scanf("%d", &A[i][j]);
			}
		}

		vector<piii> ans;
		queue<piii> q;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int c = color(i, j);
				if(c != -1) {
					q.emplace(i, j, c);
				}
			}
		}

		while(q.size()) {
			int x, y, c; tie(x, y, c) = q.front();
			q.pop();
			if(color(x, y) != c) continue;
			ans.emplace_back(x, y, c);
			A[x][y] = A[x][y + 1] = A[x + 1][y] = A[x + 1][y + 1] = -1;
			for(int i = -1; i <= 1; i++) {
				for(int j = -1; j <= 1; j++) {
					int t = color(x + i, y + j);
					if(t != -1) q.emplace(x + i, y + j, t);
				}
			}
		}

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] != -1) ok = false;
			}
		}
		if(!ok) puts("-1");
		else {
			reverse(ans.begin(), ans.end());
			printf("%d\n", ans.size());
			for(auto& i : ans) {
				int x, y, c; tie(x, y, c) = i;
				printf("%d %d %d\n", x, y, c);
			}
		}
	}
	return 0;
}