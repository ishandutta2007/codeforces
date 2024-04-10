#include <bits/stdc++.h>

using namespace std;

int C[222], X[111], Y[111];
int n, k;

void tc() {
	vector<int> V;
	int i, j, x1, x2, y1, y2, a;
	cin >> n >> k;
	fill(C, C + n + n + 1, 0);
	for (i = 0; i < k; i++) {
		cin >> X[i] >> Y[i];
		C[X[i]] = C[Y[i]] = 1;
	}
	for (i = 1; i <= n + n; i++) {
		if (!C[i]) V.push_back(i);
	}
	for (i = k; i < n; i++) {
		X[i] = V[i - k]; Y[i] = V[n - k + i - k];
	}
	for (i = a = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			tie(x1, y1) = minmax(X[i], Y[i]);
			tie(x2, y2) = minmax(X[j], Y[j]);
			if (x1 > x2) swap(x1, x2), swap(y1, y2);
			if (x2 < y1 && y2 > y1) a++;
		}
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; tc());
	
	return 0;
}