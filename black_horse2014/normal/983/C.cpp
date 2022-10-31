#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
const int INF = 19971021;

int dp[N][770][10];
int a[N], b[N];
vector<int> que[10], vec, cand;
int id[10000];
inline void chkmin(int &x, int y) {
	(x > y) && (x = y);
}

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++)
			for (int k = j; k < 10; k++)
				for (int l = k; l < 10; l++) {
					int cur = i * 1000 + j * 100 + k * 10 + l;
					cand.push_back(cur);
					id[cur] = cand.size() - 1;
				}
	memset(dp, 0x7f7f7f7f, sizeof dp);
	dp[0][0][1] = 0;
	for (int x = 0; x <= n; x++) {
		for (int f = 1; f <= 9; f++) que[f].clear();
		for (int y = x + 1; y <= n; y++) que[a[y]].push_back(y);
		for (int pp = cand.size() - 1; pp >= 0; pp--)
			for (int f = 1; f <= 9; f++) {
				int cvur = cand[pp];
				if (dp[x][pp][f] == 0x7f7f7f7f) continue;
				for (int t = 1; t <= 9; t++) {
					int cur = dp[x][pp][f] + abs(f - t);
					vector<int> vec{cvur / 1000, cvur % 1000 / 100, cvur % 100 / 10, cvur % 10};
					int empty_seat = 0;
					for (int it = 0; it < vec.size(); it++) {
						if (vec[it] == t) vec[it] = 0, cur++;
						if (vec[it] == 0) {
							empty_seat++;
							swap(vec[it], vec.back());
							vec.pop_back();
							it--;
						}
					}
					assert(empty_seat == 4 - vec.size());
					int prv = x, lst = x;
					for (int it = 0; it < que[t].size() && empty_seat && que[t][it] == prv + 1; it++, empty_seat--, prv++) {
						vec.push_back(b[que[t][it]]);
						cur++;
						lst = que[t][it];
					}
					while (vec.size() < 4) vec.push_back(0);
					sort(vec.begin(), vec.end());
					chkmin(dp[lst][id[vec[0] * 1000 + vec[1] * 100 + vec[2] * 10 + vec[3]]][t], cur);
				}
			}
	}
	int dap = INF;
	for (int f = 1; f <= 9; f++) dap = min(dap, dp[n][0][f]);
	cout << dap << endl;
	return 0;
}