#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int M, K;
int ans[505][505];
pii A[101010];
vector<pii> v;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &M, &K);
		for(int i = 1; i <= K; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + K + 1);
		reverse(A + 1, A + K + 1);
		int l = 1, r = 500;
		while(l <= r) {
			int m = l + r >> 1;
			int t = m * m - (m / 2) * (m / 2);
			if(t < M) { l = m + 1; continue; }
			if(m * ((m + 1) / 2) < A[1].first) { l = m + 1; continue; }
			r = m - 1;
		}

		int N = l;
		int x = 1, y = 2;
		v.clear();
		while(x <= N && y <= N) {
			v.emplace_back(x, y);
			y += 2;
			if(y > N) { x += 2; y = 2; }
		}
		x = 1; y = 1;
		while(x <= N) {
			v.emplace_back(x, y);
			y += 2;
			if(y > N) { x += 2; y = 1; }
		}
		x = 2; y = 1;
		while(x <= N) {
			v.emplace_back(x, y);
			y += 2;
			if(y > N) { x += 2; y = 1; }
		}

		int p = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) ans[i][j] = 0;
		for(int i = 1; i <= K; i++) {
			for(int j = 0; j < A[i].first; j++) {
				ans[v[p].first][v[p].second] = A[i].second;
				p++;
			}
		}

		printf("%d\n", N);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) printf("%d ", ans[i][j]); puts("");
		}
	}
	return 0;
}