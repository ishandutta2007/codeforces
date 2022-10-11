#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n, m, k, a, b; vector<int>x[210000], G; bool used[210000];
int dfs(int pos) {
	if (used[pos] == true)return 0;
	G.push_back(pos); used[pos] = true;
	int sum = 0;
	for (int i = 0; i < x[pos].size(); i++) {
		sum = dfs(x[pos][i]);
		if (sum == 1)G.push_back(pos);
	}
	return 1;
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) { cin >> a >> b; x[a].push_back(b); x[b].push_back(a); }
	dfs(1);
	for (int i = 0; i < k; i++) {
		int S = min((2 * n + k - 1) / k, max(0, (int)G.size() - i*((2 * n + k - 1) / k)));
		if (S >= 1) {
			cout << S;
			for (int j = i*((2 * n + k - 1) / k); j < i*((2 * n + k - 1) / k) + S; j++) {
				printf(" %d", G[j]);
			}
			cout << endl;
		}
		else {
			printf("1 1\n");
		}
	}
	return 0;
}