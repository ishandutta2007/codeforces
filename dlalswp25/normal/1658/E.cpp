#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K;
bool ans[2020][2020];
vector<pair<int, pii>> v;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			int a; scanf("%d", &a);
			v.emplace_back(a, pii(i, j));
		}
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	int mn1 = 1 - N, mx1 = N - 1;
	int mn2 = 2, mx2 = N + N;
	for(auto& i : v) {
		int x, y; tie(x, y) = i.second;
		if(y - x < mn1 || y - x > mx1 || x + y < mn2 || x + y > mx2) continue;
		ans[x][y] = true;
		mn1 = max(mn1, y - x - K);
		mx1 = min(mx1, y - x + K);
		mn2 = max(mn2, x + y - K);
		mx2 = min(mx2, x + y + K);	
	}
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) printf(ans[i][j] ? "M" : "G"); puts("");
	}
	return 0;
}