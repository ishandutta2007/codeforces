// Debugging submission #66656367

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1100000;

class CatowiseCityDefender {
public:
	vector<set<int>> v;
	vector<int> vt, ans_a, ans_b;
	int in[MAX_N];
	bool cyc[MAX_N];
	set<int> s;

	void init(int n) {
		v.clear(); vt.clear(); s.clear(); ans_a.clear(); ans_b.clear();
		for (int i = 0; i <= n; i++) {
			in[i] = 0; cyc[i] = false;
		}
	}

	void vreset(int p) {
		v.clear();
		v.resize(p);
		vt.clear();
		s.clear();
		vt.push_back(0);
		fill(in, in + p, 0);
		fill(cyc, cyc + p, false);
		in[0] = 1;
	}

	void dfs(int last) {
		int n = *(vt.rbegin() + last);

		if (!v[n].empty()) {
			int a = *v[n].begin();
			v[n].erase(v[n].begin());
			if (in[a] == 0) {
				vt.push_back(a);
				in[a] = vt.size();
				last = 0;
			}
			else {
				for (int i = in[a]; i < vt.size(); ++i) {
					cyc[vt[i]] = true;
				}
			}
			dfs(last);
		}
		else if (cyc[n]) {
			dfs(last + 1);
		}
	}

	void rdfs(int p) {
		dfs(0);
		if (find(cyc + 1, cyc + p, false) == cyc + p) {
			return;
		}
		for (auto itv = vt.rbegin(); itv != vt.rend(); ++itv) {
			s.insert(*itv);
			if (cyc[*itv] == false) break;
		}

		// Yes
		for (int j : s) ans_a.push_back(j + 1);
		set<int>::iterator its = s.begin();
		for (int j = 0; j < p; ++j) {
			if (its != s.end() && j == *its) ++its;
			else ans_b.push_back(j + 1);
		}
	}

	pair<vector<int>, vector<int>> getAnswer(int N, int M, vector<int> A, vector<int> B) {
		init(max(N, M));
		vreset(N);
		for (int i = 0; i < M; i++) {
			if (A[i] != B[i]) v[A[i] - 1].insert(B[i] - 1);
		}

		rdfs(N);
		return make_pair(ans_a, ans_b);
	}
};

class CatowiseCityAttacker {
public:
	int col[MAX_N], cnts, deg[MAX_N];
	vector<int> G[MAX_N], H[MAX_N], I;
	bool used[MAX_N];

	void init(int n) {
		cnts = 0; I.clear();
		for (int i = 0; i <= n; i++) {
			col[i] = 0; deg[i] = 0;
			G[i].clear(); H[i].clear();
			used[i] = false;
		}
	}

	void dfs(int pos) {
		used[pos] = true;
		for (int i = 0; i < G[pos].size(); i++) {
			if (used[G[pos][i]] == true) continue;
			dfs(G[pos][i]);
		}
		I.push_back(pos);
	}

	void dfs2(int pos) {
		col[pos] = cnts;
		for (int i = 0; i < H[pos].size(); i++) {
			if (col[H[pos][i]] >= 1) continue;
			dfs2(H[pos][i]);
		}
	}

	pair<vector<int>, vector<int>> getAnswer(int N, int M, vector<int> A, vector<int> B) {
		init(max(N, M));

		for (int i = 0; i < M; i++) {
			if (A[i] == B[i]) continue;
			G[A[i]].push_back(B[i]);
			H[B[i]].push_back(A[i]);
		}

		for (int i = 1; i <= N; i++) {
			if (used[i] == false) dfs(i);
		}

		reverse(I.begin(), I.end());
		for (int pos : I) {
			if (col[pos] == 0) {
				cnts++; dfs2(pos);
			}
		}

		if (cnts == 1) {
			return make_pair(vector<int>{}, vector<int>{});
		}

		for (int i = 0; i < M; i++) {
			int u1 = col[A[i]], u2 = col[B[i]];
			if (u1 != u2) deg[u2]++;
		}

		for (int i = 1; i <= cnts; i++) {
			if (deg[i] == 0) {
				vector<int> V1, V2;
				for (int j = 1; j <= N; j++) {
					if (col[j] == i) V2.push_back(j);
					else V1.push_back(j);
				}

				return make_pair(V1, V2);
			}
		}

		return make_pair(vector<int>{}, vector<int>{});
	}
};

int main() {
	int T; cin >> T;

	CatowiseCityAttacker Z;
	for (int t = 1; t <= T; t++) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<int> a(m, 0), b(m, 0);
		for (int i = 0; i < m; i++) scanf("%d%d", &a[i], &b[i]);

		pair<vector<int>, vector<int>> R = Z.getAnswer(n, m, a, b);

		if (R.first.size() == 0) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
			printf("%d %d\n", (int)R.first.size(), (int)R.second.size());
			for (int i = 0; i < R.first.size(); i++) { if (i) printf(" "); printf("%d", R.first[i]); } printf("\n");
			for (int i = 0; i < R.second.size(); i++) { if (i) printf(" "); printf("%d", R.second[i]); } printf("\n");
		}
	}
	return 0;
}