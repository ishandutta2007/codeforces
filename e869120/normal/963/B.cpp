#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

int N, par[1 << 18], dp[1 << 18], nums[1 << 18], colors[1 << 18], cnt[1 << 18], cnts = 2;
vector<int>X[1 << 18];
vector<pair<int, int>>Y[1 << 18];

void dfs(int pos) {
	dp[pos] = 1;
	for (int i = 0; i < X[pos].size(); i++) { dfs(X[pos][i]); dp[pos] += dp[X[pos][i]]; }
}

void dfs2(int pos, int num) {
	colors[pos] = num;
	for (int i = 0; i < X[pos].size(); i++) {
		if (dp[X[pos][i]] % 2 == 1) {
			nums[X[pos][i]] = num;
			int id = cnts; cnts++;
			dfs2(X[pos][i], id);
		}
		else {
			int id = cnts; cnts++;
			nums[X[pos][i]] = id;
			dfs2(X[pos][i], nums[X[pos][i]]);
		}
	}
}

int main() {
	scanf("%d", &N); int root = 0;
	for (int i = 1; i <= N; i++) { scanf("%d", &par[i]); if (par[i] >= 1) X[par[i]].push_back(i);  else root = i; }

	if (N % 2 == 0) {
		printf("NO\n");
		return 0;
	}

	dfs(root);
	dfs2(root, 1);

	for (int i = 1; i <= N; i++) { if (nums[i] != 0) { Y[i].push_back(make_pair(par[i], nums[i])); Y[par[i]].push_back(make_pair(i, nums[i])); } }
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Y[i].size(); j++) { if (Y[i][j].second != colors[i]) cnt[i]++; }
	}

	queue<int>Q;
	for (int i = 1; i <= N; i++) { if (cnt[i] == 0) Q.push(i); }

	vector<int>L;
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop(); L.push_back(pos);

		for (int i = 0; i < Y[pos].size(); i++) {
			if (Y[pos][i].second != colors[Y[pos][i].first]) {
				cnt[Y[pos][i].first]--;
				if (cnt[Y[pos][i].first] == 0) Q.push(Y[pos][i].first);
			}
		}
	}

	printf("YES\n");
	for (int i = 0; i < L.size(); i++) printf("%d\n", L[i]);
	return 0;
}