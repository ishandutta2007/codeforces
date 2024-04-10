#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

long long mod = 2147483647;

string S, C[100009]; int N, P[100009]; vector<int>K[100009];
vector<pair<long long, int>> G[1 << 17];

int main() {
	cin >> S >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
		long long hash_val = 0, t = 1;
		for (int j = 0; j < C[i].size(); j++) { hash_val += t * (C[i][j] - 'a' + 1); t *= 311LL; hash_val %= mod; t %= mod; }
		G[C[i].size()].push_back(make_pair(hash_val, i));
	}
	for (int i = 1; i <= S.size(); i++) sort(G[i].begin(), G[i].end());

	for (int i = 1; i <= S.size(); i++) {
		if (G[i].size() == 0) continue;

		long long hash_val = 0, t = 1;
		for (int j = 0; j < i - 1; j++) { hash_val += t * (S[j] - 'a' + 1); t *= 311LL; hash_val %= mod; t %= mod; }
		for (int j = i - 1; j < S.size(); j++) {
			hash_val += t * (S[j] - 'a' + 1); hash_val %= mod;
			int pos1 = lower_bound(G[i].begin(), G[i].end(), make_pair(hash_val, 0)) - G[i].begin();
			if (pos1 < G[i].size() && G[i][pos1].first == hash_val) K[G[i][pos1].second].push_back(j);

			hash_val -= (S[j - (i - 1)] - 'a' + 1);
			hash_val *= 1595076278LL;
			hash_val %= mod;
		}
	}

	for (int i = 1; i <= N; i++) {
		int ans = (1 << 30);
		for (int j = 0; j <= (int)K[i].size() - P[i]; j++) ans = min(ans, (int)C[i].size() + K[i][j + P[i] - 1] - K[i][j]);
		if (ans == (1 << 30)) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}