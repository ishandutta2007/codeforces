#include <bits/stdc++.h>

using namespace std;

int N, M;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		vector<int> v;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int d1 = dist(i, j, 1, 1);
				int d2 = dist(i, j, 1, M);
				int d3 = dist(i, j, N, 1);
				int d4 = dist(i, j, N, M);
				v.push_back(max({d1, d2, d3, d4}));
			}
		}
		sort(v.begin(), v.end());
		for(int i : v) printf("%d ", i); puts("");
	}
}