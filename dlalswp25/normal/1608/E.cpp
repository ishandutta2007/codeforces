#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> VX[5];
vector<pii> VY[5];
int X[101010];
int Y[101010];
int C[101010];

void ref() {
	for(int i = 1; i <= N; i++) swap(X[i], Y[i]);
}

bool f(int m, int a, int b, int c) {
	int x1 = VX[a][m - 1].first + 1;
	int x2 = VX[c][N / 3 - m].first - 1;
	int cnt = 0;
	for(auto& i : VX[b]) {
		if(x1 <= i.first && i.first <= x2) cnt++;
	}
	return cnt >= m;
}

bool g(int m, int a, int b, int c) {
	int y = VY[c][m - 1].second + 1;
	int x;
	int cnt = 0;
	for(auto& i : VX[a]) {
		if(i.second < y) continue;
		cnt++;
		if(cnt >= m) { x = i.first + 1; break; }
	}
	if(cnt < m) return false;
	cnt = 0;
	for(auto& i : VX[b]) {
		if(i.second >= y && i.first >= x) cnt++;
	}
	return cnt >= m;
}

bool h(int m, int a, int b, int c) {
	int y = VY[c][N / 3 - m].second - 1;
	int x;
	int cnt = 0;
	for(auto& i : VX[a]) {
		if(i.second > y) continue;
		cnt++;
		if(cnt >= m) { x = i.first + 1; break; }
	}
	if(cnt < m) return false;
	cnt = 0;
	for(auto& i : VX[b]) {
		if(i.second <= y && i.first >= x) cnt++;
	}
	return cnt >= m;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &X[i], &Y[i], &C[i]);
	}

	int l = 1, r = N / 3;
	while(l <= r) {
		int m = l + r >> 1;

		bool ok = false;
		for(int z = 0; z < 2; z++) {
			for(int i = 1; i <= 3; i++) {
				VX[i].clear(); VY[i].clear();
			}

			for(int i = 1; i <= N; i++) {
				VX[C[i]].emplace_back(X[i], Y[i]);
				VY[C[i]].emplace_back(X[i], Y[i]);
			}

			for(int i = 1; i <= 3; i++) {
				sort(VX[i].begin(), VX[i].end());
				sort(VY[i].begin(), VY[i].end(), [&](const pii a, const pii b) {
					return a.second < b.second;
				});
			}

			if(f(m, 1, 2, 3)) { ok = true; break; }
			if(f(m, 1, 3, 2)) { ok = true; break; }
			if(f(m, 2, 1, 3)) { ok = true; break; }
			if(f(m, 2, 3, 1)) { ok = true; break; }
			if(f(m, 3, 1, 2)) { ok = true; break; }
			if(f(m, 3, 2, 1)) { ok = true; break; }

			if(g(m, 1, 2, 3)) { ok = true; break; }
			if(g(m, 1, 3, 2)) { ok = true; break; }
			if(g(m, 2, 1, 3)) { ok = true; break; }
			if(g(m, 2, 3, 1)) { ok = true; break; }
			if(g(m, 3, 1, 2)) { ok = true; break; }
			if(g(m, 3, 2, 1)) { ok = true; break; }

			if(h(m, 1, 2, 3)) { ok = true; break; }
			if(h(m, 1, 3, 2)) { ok = true; break; }
			if(h(m, 2, 1, 3)) { ok = true; break; }
			if(h(m, 2, 3, 1)) { ok = true; break; }
			if(h(m, 3, 1, 2)) { ok = true; break; }
			if(h(m, 3, 2, 1)) { ok = true; break; }

			ref();
		}
		if(ok) l = m + 1;
		else r = m - 1;
	}
	printf("%d\n", r * 3);
	return 0;
}