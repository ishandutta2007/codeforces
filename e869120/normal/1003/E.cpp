#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, D, K, dist[400009], r[400009]; bool flag = false; vector<int>X[400009];

int main() {
	cin >> N >> D >> K;
	if (N == 2 && D == 1) {
		cout << "YES" << endl;
		cout << "1 2" << endl;
		return 0;
	}
	if (D % 2 == 1) { N--; D--; flag = true; }
	if (N <= D || K <= 1) { cout << "NO" << endl; return 0; }

	for (int i = 1; i <= N; i++) { dist[i] = -1; r[i] = -1; }
	for (int i = 0; i <= D; i++) {
		dist[i + 1] = abs((D / 2) - i);
		if (i < D) {
			X[i + 1].push_back(i + 2);
			X[i + 2].push_back(i + 1);
		}
	}
	for (int i = 0; i < D / 2; i++) r[i + 1] = (D / 2);
	for (int i = (D / 2) + 1; i <= D; i++) r[i + 1] = (D / 2) + 2;

	int cnt = D + 1;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == -1 || dist[i] == D / 2) continue;
		while (X[i].size() < K && cnt < N) {
			cnt++; X[i].push_back(cnt); X[cnt].push_back(i);
			dist[cnt] = dist[i] + 1; if (r[i] >= 1) r[cnt] = r[i];

			if (dist[cnt] == 1) r[cnt] = cnt;
		}
	}
	if (flag == true) {
		N++; D++;
		if (D >= 2) {
			for (int i = 1; i <= N; i++) {
				if (r[i] != X[(D / 2) + 1][0]) continue;
				while (X[i].size() < K && cnt < N) {
					cnt++; X[i].push_back(cnt); X[cnt].push_back(i);
				}
			}
		}
	}
	if (cnt < N) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < X[i].size(); j++) {
				if (i < X[i][j]) printf("%d %d\n", i, X[i][j]);
			}
		}
	}
	return 0;
}