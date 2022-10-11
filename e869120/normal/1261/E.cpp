#include <iostream>
#include <vector>
using namespace std;

int N, A[1 << 18];
int c[1009][1009];
vector<vector<int>> G;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N; j++) c[i][j] = -1;
	}
	
	vector<int> E;
	for (int i = 0; i < N + 1; i++) E.push_back(i);
	G.push_back(E);
	
	for (int i = 0; i < N; i++) {
		int maxn = 0, maxid = 0;
		for (int j = 0; j < G.size(); j++) {
			if (maxn < G[j].size()) { maxn = G[j].size(); maxid = j; }
		}
		for (int j = 0; j <= maxn; j++) {
			if (maxn >= 2 && (j == 0 || j == maxn)) continue;
			int v1 = j, v2 = A[i] - j;
			if (v2 < 0 || v2 >(N + 1) - maxn) continue;
			for (int k = 0; k < v1; k++) c[G[maxid][k]][i] = 1;
			for (int k = v1; k < maxn; k++) c[G[maxid][k]][i] = 0;

			int cnt = 0;
			for (int k = 0; k < N + 1; k++) {
				if (c[k][i] >= 0) continue;
				if (cnt < v2) c[k][i] = 1;
				else c[k][i] = 0;
				cnt++;
			}
			break;
		}

		vector<vector<int>> G2;
		for (int j = 0; j < G.size(); j++) {
			vector<int> H1, H2;
			for (int k : G[j]) {
				if (c[k][i] == 0) H1.push_back(k);
				else H2.push_back(k);
			}
			if (H1.size() >= 1) G2.push_back(H1);
			if (H2.size() >= 1) G2.push_back(H2);
		}
		G = G2;
	}

	printf("%d\n", N + 1);
	for (int i = 0; i < N + 1; i++) {
		for (int j = 0; j < N; j++) {
			if (c[i][j] == 0) printf("0");
			else printf("1");
		}
		printf("\n");
	}
	return 0;
}