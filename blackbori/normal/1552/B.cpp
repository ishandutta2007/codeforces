#include <bits/stdc++.h>

using namespace std;

int D[50505][5];
int n;

void tc() {
	int i, j, t, c;
	cin >> n;
	for (i = t = 1; i <= n; i++) {
		for (j = 0; j < 5; j++) {
			cin >> D[i][j];
		}

		for (j = c = 0; j < 5; j++) {
			c += (D[t][j] > D[i][j]);
		}
		if (c >= 3) t = i;
	}
	for (i = 1; i <= n; i++) {
		for (j = c = 0; j < 5; j++) {
			c += (D[t][j] > D[i][j]);
		}
		if (c >= 3) break;
	}
	if (i <= n) cout << "-1\n";
	else cout << t << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; tc());
	
	return 0;
}