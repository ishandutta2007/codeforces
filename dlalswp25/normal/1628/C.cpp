#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) scanf("%d", &A[i][j]);
		if(N == 2) { printf("%d\n", A[1][1] ^ A[1][2]); continue; }
		vector<pii> v;
		for(int i = 1; i <= N; i++) v.emplace_back(1, i);
		int x = 1, y = N;

		int dir = 0;
		for(int l = N; l >= 4; ) {
			for(int i = 0; i < l - 1; i++) {
				x += dx[dir]; y += dy[dir];
				v.emplace_back(x, y);
			}
			dir = (dir + 1) % 4;
			if(dir % 2 == 0) l -= 2;
		}

		// for(pii i : v) printf("%d %d\n", i.first, i.second);
		int ans = 0;
		for(int i = 0; i < v.size(); i++) {
			if(i % 4 < 2) ans ^= A[v[i].first][v[i].second];
		}
		printf("%d\n", ans);
	}
	return 0;
}