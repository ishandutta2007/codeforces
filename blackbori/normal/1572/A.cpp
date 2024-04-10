#include <bits/stdc++.h>

using namespace std;

priority_queue<int> Q;
vector<int> V;
vector<int> G[202020];
int D[202020];

void tc() {
	int n, k, a, i, t;
	cin >> n;

	for (i = 1; i <= n; i++) {
		G[i].clear(); D[i] = 0;
	}
	for(; !Q.empty(); Q.pop());
	V.clear();

	for (i = 1; i <= n; i++) {
		for (cin >> k; k--; ) {
			cin >> t; D[i]++;
			G[t].push_back(i);
		}
		if (D[i] == 0) V.push_back(i);
	}

	a = 0;
	for (i = 0; i < n; i++) {
		if (Q.empty()) {
			a++;
			for (; !V.empty(); V.pop_back()) {
				Q.emplace(-V.back());
			}
		}
		if (Q.empty()) {
			cout << "-1\n";
			return;
		}
		t = -Q.top(); Q.pop();
		for (auto &v: G[t]) {
			D[v]--;
			if (D[v] == 0) {
				if (t < v) Q.emplace(-v);
				else V.push_back(v);
			}
		}
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}