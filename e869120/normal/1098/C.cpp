#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, M, dep[200009], par[200009], cnt[200009];
pair<int, vector<int>> V;

vector<int> solve(int rep) {
	for (int i = 1; i <= N; i++) { dep[i] = i - 1; par[i] = i - 1; cnt[i] = 1; }

	long long K = N * (N + 1LL) / 2LL - M;
	if (rep == 1 && K != 0) return vector<int>{-1};
	if (K < 0) return vector<int>{-1};

	if (rep >= 2) {
		int cr = N;
		for (int i = 0; i <= 18; i++) {
			vector<int>E; for (int j = 1; j <= N; j++) { if (dep[j] == i) E.push_back(j); }

			int cp = 0;
			while (cr >= 1) {
				long long desired_dep = dep[cr] - K; if (dep[cr] <= i + 1) break;
				if (desired_dep > i + 1) {
					for (int j = 1; j <= N; j++) {
						if (dep[j] == desired_dep - 1) { dep[cr] = desired_dep; cnt[cr] = 0; par[cr] = j; K = 0; break; }
					}
					if (K != 0) {
						K += 0;
					}
				}
				else {
					while (cp < E.size() && cnt[E[cp]] == rep) cp++;
					if (cp == E.size()) break;
					K -= (dep[cr] - (i + 1));
					par[cr] = E[cp]; cnt[E[cp]]++; cnt[cr] = 0; dep[cr] = dep[E[cp]] + 1;
				}
				if (K == 0) break;
				cr--;
			}
			if (K == 0) break;
		}
	}

	if (K != 0) return vector<int>{-1};

	vector<int>R;
	for (int i = 2; i <= N; i++) R.push_back(par[i]);
	return R;
}

int main() {
	cin >> N >> M; V.first = 100000000;
	
	int cl = 1, cr = 1000000, cm = 1;
	for (int i = 0; i < 25; i++) {
		cm = (cl + cr) / 2;
		vector<int> I = solve(cm);
		if (I == vector<int>{-1}) { cl = cm; }
		else { cr = cm; V = min(V, make_pair(cm, I)); }
	}
	if (V.second.size() == 0) printf("No\n");
	else {
		printf("Yes\n");
		for (int i = 0; i < V.second.size(); i++) { if (i) printf(" "); printf("%d", V.second[i]); }
		printf("\n");
	}
	return 0;
}