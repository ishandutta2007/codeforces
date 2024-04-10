#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

int N, Q, A[300009], cp[190][300009];
int id[19][19], ar[190], br[190];

void init() {
	int cntv = 0;
	for (int i = 0; i < 19; i++) {
		for (int j = i + 1; j < 19; j++) {
			id[i][j] = cntv; ar[cntv] = i; br[cntv] = j;
			cntv++;
		}
	}
}

bool query(int u, int v) {
	queue<int>que;
	int dp[19]; for (int i = 0; i < 19; i++) { if ((A[u] & (1 << i)) != 0) { dp[i] = u; que.push(i); } else dp[i] = N + 1; }

	while (!que.empty()) {
		int pos = que.front(); que.pop();
		for (int i = 0; i < 19; i++) {
			if (pos == i) continue;
			int E = max(id[pos][i], id[i][pos]);
			int cost = cp[E][dp[pos]];
			if (dp[i] > cost) {
				dp[i] = cost;
				que.push(i);
			}
		}
	}

	int res = 0; for (int i = 0; i < 19; i++) { if (dp[i] < v) res += (1 << i); }
	if ((A[v]&res) == 0) return false;
	return true;
}

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	init();
	for (int i = 1; i <= N + 1; i++) { for (int j = 0; j < 171; j++) cp[j][i] = N + 1; }

	for (int i = 1; i <= N; i++) {
		int bit[19]; for (int j = 0; j < 19; j++) bit[j] = (A[i] / (1 << j)) % 2;
		for (int j = 0; j < 19; j++) { for (int k = j + 1; k < 19; k++) { if (bit[j] == 1 && bit[k] == 1) cp[id[j][k]][i] = i; } }
	}
	for (int i = N; i >= 1; i--) { for (int j = 0; j < 171; j++) cp[j][i] = min(cp[j][i], cp[j][i + 1]); }

	for (int i = 1; i <= Q; i++) {
		int p1, p2; scanf("%d%d", &p1, &p2);
		bool T = query(p1, p2);
		if (T == true) printf("Shi\n");
		else printf("Fou\n");
	}
	return 0;
}