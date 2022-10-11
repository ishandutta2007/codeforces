#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int>J[2000], x[2000], r; int n, m, k, a, b, used[2000]; bool T[2000];
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) { cin >> a; r.push_back(a); T[a] = true; }
	for (int i = 0; i < m; i++) {
		cin >> a >> b; x[a].push_back(b); x[b].push_back(a);
	}
	queue<int>Q; int cnt1 = 0; for (int i = 0; i < 2000; i++)used[i] = -1;
	for (int i : r) {
		Q.push(i); used[i] = cnt1;
		while (!Q.empty()) {
			int a1 = Q.front(); Q.pop(); J[cnt1].push_back(a1);
			for (int j = 0; j < x[a1].size(); j++) {
				if (used[x[a1][j]] == -1) { Q.push(x[a1][j]); used[x[a1][j]] = cnt1; }
			}
		}
		cnt1++;
	}
	int cnt2 = n - r.size(), cnt4 = 0, cnt5 = 0;
	for (int i = 1; i <= n; i++) { if (T[i] == false && used[i] >= 0) { cnt2--; } }
	for (int i = 0; i < cnt1; i++) { cnt4 += (J[i].size() - 1)*((int)J[i].size() - 2) / 2; }
	vector<int>G; for (int i = 0; i < cnt1; i++)G.push_back(J[i].size() - 1);
	sort(G.begin(), G.end());
	cnt5 = G[G.size() - 1] * cnt2;
	cout << (cnt5 + (cnt2*(cnt2 - 1) / 2) + (n - (int)r.size()) + cnt4) - m << endl;
	return 0;
}