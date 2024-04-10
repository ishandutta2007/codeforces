#include <iostream>
#include <vector>
using namespace std;

int n, p[100009], depth[100009], cnt[100009]; vector<int>x[100009];

void dfs(int pos, int dep) {
	depth[pos] = dep; cnt[dep]++;
	for (int i = 0; i < x[pos].size(); i++) dfs(x[pos][i], dep + 1);
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		x[p[i]].push_back(i);
	}
	dfs(1, 0);
	int G = 0;
	for (int i = 0; i <= n; i++) { if (cnt[i] % 2 == 1) G++; }
	cout << G << endl;
	return 0;
}