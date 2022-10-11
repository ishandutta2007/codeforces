#include <bits/stdc++.h>
using namespace std;

int N, M, t[26][1009][1009]; char c[1009][1009];
vector<int>G[1009];

int ranged(char p, int cx, int cy, int dx, int dy) {
	p -= 'a';
	return t[p][cx - 1][cy - 1] - t[p][cx - 1][dy] - t[p][dx][cy - 1] + t[p][dx][dy];
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> c[i][j];
			t[c[i][j] - 'a'][i][j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (c[i][j] != c[i - 1][j]) G[j].push_back(i);
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= M; k++) t[i][j][k] += t[i][j - 1][k];
		}
		for (int j = 0; j <= N; j++) {
			for (int k = 1; k <= M; k++) t[i][j][k] += t[i][j][k - 1];
		}
	}
	
	long long ans = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			int pos1 = lower_bound(G[i].begin(), G[i].end(), j + 1) - G[i].begin();
			if (pos1 == G[i].size()) continue;
			
			int t1 = j, t2 = G[i][pos1], t3 = t2 + (t2 - t1), t4 = t3 + (t3 - t2);
			if (t4 > N + 1) continue;
			if (c[t1][i] == c[t2][i] || c[t2][i] == c[t3][i]) continue;
			
			int cl = i, cr = M + 2, cm, maxn = i;
			for (int k = 0; k < 12; k++) {
				cm = (cl + cr) / 2;
				int V = (t2 - t1) * (cm - i);
				int D1 = ranged(c[t1][i], t1, i, t2 - 1, cm - 1);
				int D2 = ranged(c[t2][i], t2, i, t3 - 1, cm - 1);
				int D3 = ranged(c[t3][i], t3, i, t4 - 1, cm - 1);
				//cout << cm << " "<< D1 << " " << D2 << " " << D3 << " " << V << endl;
				if (D1 == V && D2 == V && D3 == V) { maxn = max(maxn, cm); cl = cm; }
				else cr = cm;
			}
			//cout << i << " " << t1 << " " << t2 << " " << t3 << " " << t4 << " " << maxn << endl;
			ans += 1LL * (maxn - i);
		}
	}
	cout << ans << endl;
	return 0;
}