#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

int N, Q; short dp[10009][10009]; bool used[10009];
vector<tuple<int, int, int>> G;

int main() {
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < Q; i++) { int l, r, x; scanf("%d%d%d", &l, &r, &x); G.push_back(make_tuple(l, r, x)); }
	sort(G.begin(), G.end());
	
	for (int i = 0; i < G.size(); i++) {
		dp[i + 1][get<2>(G[i])] = get<1>(G[i]);

		for (int j = 0; j <= N; j++) {
			if (dp[i][j] < get<0>(G[i]) || dp[i][j] == 0) continue;
			if (j + get<2>(G[i]) <= N) dp[i + 1][j + get<2>(G[i])] = max((int)dp[i + 1][j + get<2>(G[i])], min((int)dp[i][j], get<1>(G[i])));
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
		for (int j = 0; j <= N; j++) {
			if (dp[i + 1][j] != 0) used[j] = true;
		}
	}

	vector<int>vec;
	for (int i = 0; i <= N; i++) { if (used[i] == true) vec.push_back(i); }

	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) { if (i) printf(" "); printf("%d", vec[i]); }
	printf("\n");
	return 0;
}