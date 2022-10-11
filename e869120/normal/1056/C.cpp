#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, T, p[3009], pre[3009]; bool used[3009];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N * 2; i++) cin >> p[i];
	for (int i = 1; i <= M; i++) {
		int pa, pb; cin >> pa >> pb;
		pre[pa] = pb; pre[pb] = pa;
	}
	cin >> T;

	int forces = -1;
	for (int i = 1; i <= N * 2; i++) {
		if (T == 1) {
			int id = -1;
			if (forces == -1) {
				for (int j = 1; j <= N * 2; j++) {
					if (used[j] == false && pre[j] >= 1 && p[j] >= p[pre[j]]) { id = j; break; }
				}
				if (id == -1) {
					pair<int, int> maxn = make_pair(-1, -1);
					for (int j = 1; j <= N * 2; j++) {
						if (used[j] == false) maxn = max(maxn, make_pair(p[j], j));
					}
					id = maxn.second;
				}
			}
			else {
				id = forces;
			}
			cout << id << endl;
			used[id] = true;
		}
		if (T == 2) {
			int cx; cin >> cx;
			used[cx] = true;
			if (pre[cx] >= 1 && used[pre[cx]] == false) forces = pre[cx];
			else forces = -1;
		}
		if (T == 1) T = 2; else T = 1;
	}
	return 0;
}