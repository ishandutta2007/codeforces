#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int cnt[105][105];
int ans[10101][105];
set<pii> S;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int a; scanf("%d", &a);
			cnt[i][a]++;
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(cnt[i][j] > 1) S.insert({i, j});
		}
	}

	int q;
	for(q = 1; ; q++) {
		if(!S.size()) break;
		int x, y; tie(x, y) = *S.begin();
		for(int i = 0; i < N; i++) {
			auto it = S.lower_bound({x, 0});
			y = it->second;
			ans[q][x] = y;
			cnt[x][y]--;
			if(cnt[x][y] == 1) S.erase({x, y});
			x++; if(x > N) x = 1;
			cnt[x][y]++;
			if(cnt[x][y] == 2) S.insert({x, y});
		}
	}

	printf("%d\n", q - 1 + N * (N - 1) / 2);
	for(int i = 1; i < q; i++) {
		for(int j = 1; j <= N; j++) printf("%d ", ans[i][j]); puts("");
	}
	for(int i = 2; i <= N; i++) {
		for(int j = i; j >= 2; j--) {
			for(int k = 1; k <= N; k++) printf("%d ", (j + k - 2) % N + 1); puts("");
		}
	}
	return 0;
}