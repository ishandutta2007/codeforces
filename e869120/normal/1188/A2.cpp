#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

int N, deg[1 << 10];
int par[1 << 10][1 << 10], leafs[1 << 10];
int P[1 << 10][1 << 10], W[1 << 10][1 << 10];
vector<int>X[1 << 10], I;
bool used[1 << 10];

void dfs(int root, int pos, int pre) {
	par[root][pos] = pre;
	for (int i = 0; i < X[pos].size(); i++) {
		if (par[root][X[pos][i]] != 0) continue;
		dfs(root, X[pos][i], pos);
	}
}

void dels(int u1, int u2, int pos) {
	int cx = u2;
	while (cx != u1) {
		int v1 = cx, v2 = par[u1][cx];
		W[v1][v2] -= pos; W[v2][v1] -= pos;
		cx = par[u1][cx];
	}
}

void subtree(int pos, int banned) {
	if (used[pos] == true) return;
	used[pos] = true; if (deg[pos] == 1) I.push_back(pos);
	for (int i = 0; i < X[pos].size(); i++) {
		if (X[pos][i] == banned) continue;
		subtree(X[pos][i], banned);
	}
}

vector<int> find_subtree(int pos, int banned) {
	I.clear(); for (int i = 1; i <= N; i++) used[i] = false;
	subtree(pos, banned);
	return I;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int pa, pb, val; cin >> pa >> pb >> val;
		P[pa][pb] = 1; W[pa][pb] = val; X[pa].push_back(pb); deg[pa]++;
		P[pb][pa] = 1; W[pb][pa] = val; X[pb].push_back(pa); deg[pb]++;
	}
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 2) {
			printf("NO\n");
			return 0;
		}
	}
	if (N == 2) {
		cout << "YES" << endl;
		cout << "1" << endl;
		cout << "1 2 " << W[1][2] << endl;
		return 0;
	}

	for (int i = 1; i <= N; i++) dfs(i, i, -1);

	vector<tuple<int, int, int>> G;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (P[i][j] == 0 || W[i][j] == 0) continue;

			int u1 = i, u2 = j; if (deg[u2] == 1) swap(u1, u2);
			if (deg[u1] == 1) {
				vector<int> L; for (int k = 0; k < X[u2].size(); k++) { if (X[u2][k] != u1) L.push_back(X[u2][k]); }
				vector<int> D1 = vector<int>{ u1 };
				vector<int> D2 = find_subtree(L[0], u2);
				vector<int> D3 = find_subtree(L[1], u2);

				int x = W[i][j];
				G.push_back(make_tuple(D2[0], D3[0], -x / 2)); dels(D2[0], D3[0], -x / 2);
				G.push_back(make_tuple(D1[0], D2[0], +x / 2)); dels(D1[0], D2[0], +x / 2);
				G.push_back(make_tuple(D1[0], D3[0], +x / 2)); dels(D1[0], D3[0], +x / 2);
			}
			else {
				vector<int> LA; for (int k = 0; k < X[u1].size(); k++) { if (X[u1][k] != u2) LA.push_back(X[u1][k]); }
				vector<int> LB; for (int k = 0; k < X[u2].size(); k++) { if (X[u2][k] != u1) LB.push_back(X[u2][k]); }
				vector<int> D1 = find_subtree(LA[0], u1);
				vector<int> D2 = find_subtree(LA[1], u1);
				vector<int> D3 = find_subtree(LB[0], u2);
				vector<int> D4 = find_subtree(LB[1], u2);

				int x = W[i][j];
				G.push_back(make_tuple(D1[0], D2[0], -x / 2)); dels(D1[0], D2[0], -x / 2);
				G.push_back(make_tuple(D3[0], D4[0], -x / 2)); dels(D3[0], D4[0], -x / 2);
				G.push_back(make_tuple(D1[0], D3[0], +x / 2)); dels(D1[0], D3[0], +x / 2);
				G.push_back(make_tuple(D2[0], D4[0], +x / 2)); dels(D2[0], D4[0], +x / 2);
			}
		}
	}

	printf("YES\n");
	printf("%d\n", (int)G.size());
	for (int i = 0; i < G.size(); i++) printf("%d %d %d\n", get<0>(G[i]), get<1>(G[i]), get<2>(G[i]));
	return 0;
}