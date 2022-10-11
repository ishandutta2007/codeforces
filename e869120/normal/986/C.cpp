#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int n, m, a[1 << 23], col[1 << 23], cnts; bool used[1 << 23];

void dfs(int pos) {
	if (col[pos] >= 1) return;
	col[pos] = cnts;
	for (int i = 0; i < n; i++) {
		if ((pos&(1 << i)) == 0) continue;
		dfs(pos - (1 << i));
	}
	if (used[pos] == true) dfs((1 << n) - 1 - pos);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) { scanf("%d", &a[i]); used[a[i]] = true; }
	for (int i = 0; i < m; i++) {
		if (col[a[i]] >= 1) continue;
		cnts++; dfs(a[i]);
	}
	cout << cnts << endl;
	return 0;
}