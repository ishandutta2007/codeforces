#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, K, A[16], t[2009];
vector<tuple<int, int, int, int>> dp[1 << 16];
tuple<int, int, int> G[2009];
vector<pair<int, int>> ans;

void synchronize(int p1, int p2) {
	if (dp[p1].size() * dp[p2].size() <= 5) {
		for (int i = 0; i < dp[p1].size(); i++) {
			for (int j = 0; j < dp[p2].size(); j++) {
				int c1 = get<0>(dp[p1][i]);
				int c2 = get<0>(dp[p2][j]);
				G[t[c1 + c2]] = make_tuple(c1, c2, p1);
			}
		}
	}

	else {
		int cnt = 1;
		if (p1 + p2 == (1 << N) - 1) cnt = 30;

		int D = rand();
		for (int tt = 0; tt < cnt; tt++) {
			int i = D % dp[p1].size(), j = D % dp[p2].size();
			int c1 = get<0>(dp[p1][i]);
			int c2 = get<0>(dp[p2][j]);
			G[t[c1 + c2]] = make_tuple(c1, c2, p1);
			D++;
		}
	}
}

void dfs(int pos, int u) {
	for (int i = 0; i < dp[pos].size(); i++) {
		if (get<0>(dp[pos][i]) == u && get<1>(dp[pos][i]) != -1) {
			dfs(get<3>(dp[pos][i]), get<1>(dp[pos][i]));
			dfs(pos - get<3>(dp[pos][i]), get<2>(dp[pos][i]));
			ans.push_back(make_pair(get<1>(dp[pos][i]), get<2>(dp[pos][i])));
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 1; i <= 2000; i++) { t[i] = i; while (t[i] % K == 0) t[i] /= K; }
	
	for (int i = 1; i < (1 << N); i++) {
		vector<int> V;
		for (int j = 0; j < N; j++) { if ((i / (1 << j)) % 2 == 1) V.push_back(j); }
		for (int j = 0; j <= 2000; j++) G[j] = make_tuple(-1, -1, -1);

		if (V.size() == 1) {
			dp[i].push_back(make_tuple(A[V[0]], -1, -1, -1));
		}
		else {
			int m = 0;
			for (int j = 0; j < (1 << V.size()) - 1; j++) {
				if (j >= 1) synchronize(m, i - m);

				int f = j, c = 0; while ((f & 1) == 1) { m -= (1 << V[c]); f >>= 1; c++; }
				m += (1 << V[c]);
			}
			for (int j = 0; j <= 2000; j++) {
				if (G[j] != make_tuple(-1, -1, -1)) dp[i].push_back(make_tuple(j, get<0>(G[j]), get<1>(G[j]), get<2>(G[j])));
			}
		}
	}

	dfs((1 << N) - 1, 1);

	if (ans.size() != N - 1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 0; i < N - 1; i++) cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}