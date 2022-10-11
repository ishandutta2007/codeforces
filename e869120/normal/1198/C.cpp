#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 19);

int N, M, A[MAX_N], B[MAX_N];
vector<pair<int, int>> G[MAX_N];
bool used[MAX_N];

void init() {
	for (int i = 1; i <= M; i++) { A[i] = 0; B[i] = 0; }
	for (int i = 1; i <= 3 * N; i++) { G[i].clear(); used[i] = false; }
}

void solve() {
	init();

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(make_pair(B[i], i));
		G[B[i]].push_back(make_pair(A[i], i));
	}

	vector<int> E;
	for (int i = 1; i <= 3 * N; i++) {
		if (used[i] == true) continue;

		for (int j = 0; j < G[i].size(); j++) {
			if (used[G[i][j].first] == false) {
				E.push_back(G[i][j].second);
				used[G[i][j].first] = true;
				used[i] = true;
				break;
			}
		}
	}

	if (E.size() >= N) {
		printf("Matching\n");
		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("%d", E[i]);
		}
		printf("\n");
	}
	else {
		printf("IndSet\n");

		vector<int> G;
		for (int i = 1; i <= 3 * N; i++) {
			if (used[i] == false) G.push_back(i);
		}

		for (int i = 0; i < N; i++) {
			if (i) printf(" ");
			printf("%d", G[i]);
		}
		printf("\n");
	}
}

int main() {
	int T; scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		solve();
	}
	return 0;
}