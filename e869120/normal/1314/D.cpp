#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, K, Answer = 2000000000;
int C[90][90];
int SZ[90][90];
pair<int, int> D[90][90][90];

int used[90];
vector<int> vec;

void dfs(int dep) {
	if (dep == 0) {
		int sum = 0;
		for (int i = 0; i < vec.size(); i++) {
			int c1 = vec[i], c2 = 1; if (i + 1 < vec.size()) c2 = vec[i + 1];
			bool flag = false;
			for (int j = 0; j < SZ[c1][c2]; j++) {
				if (used[D[c1][c2][j].second] == 0) { sum += D[c1][c2][j].first; flag = true; break; }
			}
			if (flag == false) return;
		}
		Answer = min(Answer, sum);
		return;
	}
	for (int i = 1; i <= N; i++) {
		vec.push_back(i); used[i]++;
		dfs(dep - 1);
		vec.pop_back(); used[i]--;
	}
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) { cin >> C[i][j]; }
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 1; k <= N; k++) {
				if (i == k || j == k) continue;
				D[i][j][cnt] = make_pair(C[i][k] + C[k][j], k);
				cnt++;
			}
			SZ[i][j] = cnt;
			sort(D[i][j], D[i][j] + cnt);
		}
	}
	
	vec.push_back(1); used[1] = 1;
	dfs((K - 2) / 2);

	cout << Answer << endl;
	return 0;
}