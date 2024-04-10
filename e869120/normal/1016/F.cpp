#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A[1 << 19], B[1 << 19], C[1 << 19], dist[1 << 19], par[1 << 19], lens[1 << 19], res[1 << 19], rem = (1LL << 60);
vector<pair<int, int>>G[300009]; vector<int> I;
bool used[1 << 19], forced[1 << 19];
map<pair<int, int>, long long>Map;

void dfs(int pos, long long dep) {
	used[pos] = true; dist[pos] = dep;
	for (int i = 0; i < G[pos].size(); i++) {
		if (used[G[pos][i].first] == true) continue;
		par[G[pos][i].first] = pos;
		dfs(G[pos][i].first, dep + G[pos][i].second);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		G[A[i]].push_back(make_pair(B[i], C[i])); Map[make_pair(A[i], B[i])] = C[i];
		G[B[i]].push_back(make_pair(A[i], C[i])); Map[make_pair(B[i], A[i])] = C[i];
	}
	dfs(1, 0);

	int cx = N;
	while (cx != 0) { I.push_back(cx); forced[cx] = true; cx = par[cx]; }
	reverse(I.begin(), I.end());
	
	bool flag = false;
	for (int i = 0; i < I.size(); i++) lens[i] = 0;
	for (int t = 0; t < I.size(); t++) {
		int cntv = 0, pos = I[t];
		for (int i = 0; i < G[pos].size(); i++) {
			if (forced[G[pos][i].first] == false) {
				cntv++; lens[t] = G[pos][i].second; if (G[G[pos][i].first].size() != 1) flag = true;
			}
		}
		if (cntv >= 2) flag = true;
	}

	long long DetectiveMin = 0;

	if (flag == false) {
		for (int i = 0; i < I.size(); i++) res[i] = -lens[i];
		long long s1 = 0; for (int i = 0; i < I.size() - 1; i++) { s1 += Map[make_pair(I[i], I[i + 1])]; res[i + 1] += s1; }
		for (int i = (int)I.size() - 2; i >= 0; i--) res[i] = min(res[i], res[i + 1]);

		long long s2 = 0; DetectiveMin = (1LL << 60);
		for (int i = 0; i < I.size() - 1; i++) {
			int pars = i + 1; if (lens[i + 1] == 0 && lens[i] == 0) pars = i + 2;
			if (pars >= I.size()) break;

			DetectiveMin = min(DetectiveMin, res[pars] - (s2 + lens[i]));
			s2 += Map[make_pair(I[i], I[i + 1])];
		}
	}

	for (int i = 1; i <= M; i++) {
		long long S; scanf("%lld", &S);
		printf("%lld\n", dist[N] - max(0LL, DetectiveMin - S));
	}
	return 0;
}