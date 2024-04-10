#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long H, W, K, a[100][100]; vector<long long>vec[2][20][20];

void dfs(int px, int py, int dep, int ty, long long val) {
	if (px < 0 || py < 0 || px >= H || py >= W) return;
	if (dep == 0) {
		if (ty == 0) vec[ty][px][py].push_back(val ^ a[px][py]);
		if (ty == 1) vec[ty][px][py].push_back(val);
		return;
	}
	if (ty == 0) {
		dfs(px + 1, py, dep - 1, ty, val^a[px][py]);
		dfs(px, py + 1, dep - 1, ty, val^a[px][py]);
	}
	if (ty == 1) {
		dfs(px - 1, py, dep - 1, ty, val^a[px][py]);
		dfs(px, py - 1, dep - 1, ty, val^a[px][py]);
	}
}

int main() {
	cin >> H >> W >> K;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> a[i][j];
	}
	if (H == 1 && W == 1) {
		if (a[0][0] == K) cout << "1" << endl;
		else cout << "0" << endl;
		return 0;
	}
	long long mid = (H + W - 2) / 2;
	dfs(0, 0, mid, 0, 0);
	dfs(H - 1, W - 1, (H + W - 2) - mid, 1, 0);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			sort(vec[0][i][j].begin(), vec[0][i][j].end());
			sort(vec[1][i][j].begin(), vec[1][i][j].end());
		}
	}

	long long ans = 0;
	for (int px = 0; px < H; px++) {
		for (int py = 0; py < W; py++) {
			for (int i = 0; i < vec[0][px][py].size(); i++) {
				long long V = (K^vec[0][px][py][i]);
				int pos1 = lower_bound(vec[1][px][py].begin(), vec[1][px][py].end(), V) - vec[1][px][py].begin();
				int pos2 = lower_bound(vec[1][px][py].begin(), vec[1][px][py].end(), V + 1) - vec[1][px][py].begin();
				ans += (pos2 - pos1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}