#include <iostream>
#include <vector>
using namespace std;

long long n, d[109]; vector<int>x[109], G, O; bool used[109];

void dfs(int pos) {
	if (O.size() >= 1) return;
	used[pos] = true; G.push_back(pos);
	if (G.size() == n) {
		O = G; return;
	}
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == false) dfs(x[pos][i]);
	}
	used[pos] = false; G.pop_back();
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[j] * 3 == d[i]) x[i].push_back(j);
			if (d[j] == d[i] * 2) x[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) dfs(i);
	for (int i = 0; i < O.size(); i++) { if (i)cout << " "; cout << d[O[i]]; }cout << endl;
	return 0;
}