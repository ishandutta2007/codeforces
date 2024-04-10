#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int L[N], R[N];
vector<int> V[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> L[i] >> R[i]; R[i]++;
		V[L[i]].push_back(i);
		V[R[i]].push_back(~i);
	}
	set<pair<int, int> > S;
	vector<int> ans;
	for (int i = 1; i <= 200000; i++) {
		for (int j : V[i]) {
			if (j >= 0) {
				S.emplace(R[j], j);
			} else {
				S.erase({R[~j], ~j});
			}
		}
		while (S.size() > k) {
			auto it = --S.end();
			ans.push_back(it->second);
			S.erase(it);
		}
	}
	cout << ans.size() << "\n";
	for (int x : ans) cout << x + 1 << ' ';
	return 0;
}