#include <bits/stdc++.h>
using namespace std;

const int M = 7;
const int N = 1000;

vector<int> on[M][N];

int sx[M], sy[M], mx[N], my[N], ban[N], id[M];
int L[N];

bool ison(int l, int i, int j) {
	return 1ll * (sx[i] - mx[l]) * (my[j] - my[l]) == 1ll * (sy[i] - my[l]) * (mx[j] - mx[l]) &&
		   1ll * (sx[i] - mx[l]) * (mx[j] - mx[l]) + 1ll * (sy[i] - my[l]) * (my[j] - my[l]) < 0;
}

bool dfs(int k, vector<int> v) {
	if (v.empty()) return 1;
	if (v.size() > k+1) return 0;
	int who = id[k];
	vector<int> vn, vv;
	for (int i = 0; i < v.size(); i++) {
		int flg = 0;
		for (int j : on[who][v[i]]) {
			if (L[j] < 0 || L[j] > k) {
				flg = 1;
				break;
			}
		}
		if (flg) continue;
		vn = v;
		for (int j = i; j+1 < v.size(); j++) swap(vn[j], vn[j+1]);
		vn.pop_back();
		vv.resize(on[who][v[i]].size() + vn.size());
		merge(vn.begin(), vn.end(), on[who][v[i]].begin(), on[who][v[i]].end(), vv.begin());
		vv.erase(unique(vv.begin(), vv.end()), vv.end());
		if (dfs(k-1, vv)) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	memset(L, -1, sizeof L);
	int k, n; cin >> k >> n;
	for (int i = 0; i < k; i++) cin >> sx[i] >> sy[i];
	for (int i = 0; i < n; i++) cin >> mx[i] >> my[i];
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				if (ison(l, i, j)) {
					on[i][j].push_back(l);
				}
			}
		}
	}
	int ans = 0;
	for (int x = 1; x <= k; x++) {
		for (int i = 0; i < k; i++) id[i] = i;
		set<int> SE;
		do {
			if (x < k) {
				int state = 0, pw = 1;
				for (int i = 0; i < x; i++) {
					state += pw * id[i];
					pw *= 7;
				}
				if (SE.count(state)) continue;
				SE.insert(state);
			}
			for (int i = 0; i < n; i++) {
				if (L[i] >= 0) continue;
				vector<int> v;
				v.push_back(i);
				if (dfs(x-1, v)) {
					L[i] = x, ans++;
				}
			}
		} while (next_permutation(id, id + k));
	}
	cout << ans << endl;
}