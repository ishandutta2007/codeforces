#include <iostream>

using namespace std;

int n, b, c = 0;
int p[1005];
int col[1005];
int pos[1005];
int camt[1005];

void fcp(int i) {
	if (col[i] != -1)
		return;
	if (p[i] == 0) {
		col[i] = c++;
		camt[col[i]] = pos[i] = 1;
	} else {
		fcp(p[i]);
		col[i] = col[p[i]];
		pos[i] = 1 + pos[p[i]];
		++camt[col[i]];
	}
}

bool ans[1005];

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> b;
	fill(col, col + n + 1, -1);
	fill(pos, pos + n + 1, -1);
	for (int i = 1; i <= n; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i)
		fcp(i);
	fill(ans, ans + 1005, 0);
	ans[0] = 1;
	for (int i = 0; i < c; ++i) {
		if (i == col[b]) continue;
		for (int j = 1004; j >= camt[i]; --j)
			ans[j] |= ans[j - camt[i]];
	}
	for (int i = 0; i < 1005; ++i)
		if (ans[i]) cout << pos[b] + i << '\n';

	return 0;
}