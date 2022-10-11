#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)
vector<pair<int, int>>X[200009]; int n, a, b, maxn; bool used[200009]; vector<int>ret[200009];
void dfs(int pos, int t) {
	if (used[pos] == true)return;
	used[pos] = true;
	int G = 1;
	for (pair<int, int> i: X[pos]) {
		if (used[i.first] == true)continue;
		if (G == t)G++; ret[G].push_back(i.second); maxn = max(maxn, G);
		dfs(i.first, G);
		G++;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) { cin >> a >> b; X[a].push_back(make_pair(b, i)); X[b].push_back(make_pair(a, i)); }
	dfs(1, 0);
	cout << maxn << endl;
	for (int i = 1; i <= maxn; i++) {
		cout << ret[i].size();
		for (int j = 0; j < ret[i].size(); j++)cout << " " << ret[i][j] + 1; cout << endl;
	}
	return 0;
}