#include <iostream>
#include <vector>
using namespace std;

int a[5][59], N, K, c[105], p[105], used[105];
vector<pair<int, int>>vec;

int main() {
	cin >> N >> K;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j]; if (a[i][j] == 0) continue;
			if (i == 1) p[a[i][j]] = (j - 1);
			if (i == 2) c[a[i][j]] = (j - 1);
			if (i == 3) c[a[i][j]] = N * 2 - j;
			if (i == 4) p[a[i][j]] = N * 2 - j;
		}
	}
	int S = K;
	for (int i = 1; i <= K; i++) {
		if (c[i] == p[i]) { vec.push_back(make_pair(i, -1)); c[i] = -1; S--; }
	}
	if (S == 2 * N) { cout << "-1" << endl; return 0; }

	while (true) {
		for (int i = 0; i < 2 * N; i++) used[i] = -1;
		for (int i = 1; i <= K; i++) { if (c[i] != -1) used[c[i]] = i; }
		for (int i = 0; i < 2 * N; i++) {
			if (used[i] >= 0 && used[(i + 1) % (2 * N)] == -1) {
				vec.push_back(make_pair(used[i], (i + 1) % (2 * N))); int num = used[i];
				c[num] = (i + 1) % (2 * N); swap(used[i], used[(i + 1) % (2 * N)]);

				if (c[num] == p[num]) {
					vec.push_back(make_pair(num, -1)); c[num] = -1; used[(i + 1) % (2 * N)] = -1; S--;
				}
			}
		}
		if (S == 0) break;
	}
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		int cur = vec[i].first, pos = vec[i].second;
		if (pos == -1) {
			if (p[cur] < N) cout << cur << " 1 " << p[cur] + 1 << endl;
			else cout << cur << " 4 " << N * 2 - p[cur] << endl;
		}
		else {
			if (pos < N) cout << cur << " 2 " << pos + 1 << endl;
			else cout << cur << " 3 " << N * 2 - pos << endl;
		}
	}
	return 0;
}