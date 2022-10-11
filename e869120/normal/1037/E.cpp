#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#pragma warning (disable: 4996)

int n, m, k, c[200009], x[200009], y[200009], cnt, u[200009], ans[200009];
set<int>S[200009];

void calc(vector<int>B) {
	queue<int>Q;
	for (int i = 0; i < B.size(); i++) {
		if (u[B[i]] == 1 && c[B[i]] < k) { Q.push(B[i]); u[B[i]] = 0; }
	}
	while (!Q.empty()) {
		int pos = Q.front(); Q.pop();
		cnt--;
		auto itr = S[pos].begin();

		while (itr != S[pos].end()) {
			S[*itr].erase(pos); c[*itr]--;
			if (u[*itr] == 1 && c[*itr] < k) { Q.push(*itr); u[*itr] = 0; } itr++;
		}
		S[pos].clear(); c[pos] = 0;
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		c[x[i]]++; S[x[i]].insert(y[i]);
		c[y[i]]++; S[y[i]].insert(x[i]);
	}
	vector<int>Z; for (int i = 1; i <= n; i++) { u[i] = 1; Z.push_back(i); }
	calc(Z); cnt = 0;
	for (int i = 1; i <= n; i++) cnt += u[i];

	for (int i = m; i >= 1; i--) {
		ans[i] = cnt;
		if (S[x[i]].find(y[i]) != S[x[i]].end()) { c[x[i]]--; c[y[i]]--; S[x[i]].erase(y[i]); S[y[i]].erase(x[i]); }
		calc(vector<int>{x[i], y[i]});
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}