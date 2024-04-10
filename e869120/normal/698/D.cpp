#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
using namespace std;

long long N, K, ax[9], ay[9], px[1009], py[1009]; bool ok = false;
vector<int>vec[9][1009];

void dfs(int pos, int dep, vector<int>Todo) {
	if (ok == true) return;
	if (Todo.size() == 0) { ok = true; return; }

	for (int i = 1; i <= K; i++) {
		if ((pos / (1 << i)) % 2 == 1) continue;

		for (int j = 0; j < Todo.size(); j++) {
			if (vec[i][Todo[j]].size() >= K - dep) continue;

			vector<int>C;
			for (int k = 0; k < Todo.size(); k++) { if (j != k) C.push_back(Todo[k]); }

			int pp = Todo[j];
			for (int k = 0; k < vec[i][pp].size(); k++) {
				bool flag = false;
				for (int l = 0; l < C.size(); l++) {
					if (C[l] == vec[i][pp][k]) { flag = true; break; }
				}
				if (flag == false) C.push_back(vec[i][pp][k]);
			}

			if (C.size() >= K - dep) continue;
			dfs(pos + (1 << i), dep + 1, C);
		}
	}
}

int main() {
	cin >> K >> N; vector<pair<int, int>>G;
	for (int i = 1; i <= K; i++) cin >> ax[i] >> ay[i];
	for (int i = 1; i <= N; i++) { cin >> px[i] >> py[i]; G.push_back(make_pair(px[i], py[i])); }
	sort(G.begin(), G.end());
	for (int i = 1; i <= N; i++) { px[i] = G[i - 1].first; py[i] = G[i - 1].second; }

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			vector<tuple<int, int, int>>V; bool ok1 = false;
			for (int k = 1; k <= N; k++) {
				pair<long long, long long> F1 = make_pair(px[k] - ax[i], py[k] - ay[i]);
				pair<long long, long long> F2 = make_pair(px[j] - ax[i], py[j] - ay[i]);
				long long S = F1.first * F2.second - F1.second * F2.first;
				if (S == 0) V.push_back(make_tuple(px[k], py[k], k));
			}
			V.push_back(make_tuple(ax[i], ay[i], 0));
			sort(V.begin(), V.end());
			int pos1 = lower_bound(V.begin(), V.end(), make_tuple(ax[i], ay[i], 0)) - V.begin();
			int pos2 = lower_bound(V.begin(), V.end(), make_tuple(px[j], py[j], j)) - V.begin();
			for (int k = pos1 + 1; k < pos2; k++) vec[i][j].push_back(get<2>(V[k]));
			for (int k = pos1 - 1; k > pos2; k--) vec[i][j].push_back(get<2>(V[k]));
			reverse(vec[i][j].begin(), vec[i][j].end());
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		ok = false;
		dfs(0, 0, { i });
		if (ok == true) cnt++;
	}
	cout << cnt << endl;
	return 0;
}