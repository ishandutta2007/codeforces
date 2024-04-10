#include <bits/stdc++.h>
using namespace std;

const int N = 2200;
int cnt[N], ban[N], nban[N];
bitset<N> B[N];
vector<pair<int, int>> ans;
char str[N];

void solve() {
	int n, m; scanf("%d%d", &n, &m);
	ans.clear();
	for (int i = 0; i < n; i++) B[i].reset(), ban[i] = nban[i] = 0;
	for (int i = 0; i < m; i++) {
		scanf("%s", str);
		cnt[i] = 0;
		for (int j = 0; j < n; j++) {
			if (str[j] == '1') {
				B[j][i] = 1;
				cnt[i]++;
			}
		}
		if (cnt[i] == 1) {
			cnt[i] = 0;
			for (int j = 0; j < n; j++) B[j][i] = 0;
		}
	}
	while (1) {
		int flg = 0;
		for (int i = 0; i < n; i++) {
			if (ban[i] || nban[i]) continue;
			nban[i] = 1;
			int k = -1;
			for (int j = 0; j < n; j++) {
				if (ban[j] || j == i) continue;
				if ((B[i] & B[j]) == B[i]) {
					k = j;
					break;
				}
			}
			if (k < 0) continue;
			ans.emplace_back(i, k);
			ban[i] = 1;
			for (int j = 0; j < m; j++) {
				if (B[i][j]) cnt[j]--;
				if (cnt[j] == 1) {
					cnt[j] = 0;
					B[k][j] = 0;
					nban[k] = 0;
				}
			}
			flg = 1;
			break;
		}
		if (!flg) break;
	}
	if (ans.size() == n-1) {
		puts("YES");
		for (auto t : ans) printf("%d %d\n", t.first+1, t.second+1);
	} else puts("NO");
}

int main() {
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) solve(); 
}