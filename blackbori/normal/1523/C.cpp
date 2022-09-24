#include <bits/stdc++.h>

using namespace std;

void tc() {
	vector<int> S;
	int n, i, a;

	cin >> n;

	auto print = [&](vector<int> &S) {
		int i;
		for (i = 0; i < S.size(); i++) {
			if (i) cout << ".";
			cout << S[i];
		}
		cout << "\n";
	};

	for (i = 1; i <= n; i++) {
		cin >> a;
		if (a == 1) {
			S.push_back(1);
			print(S);
			continue;
		}
		for (; !S.empty(); ) {
			if (S.back() + 1 == a) break;
			S.pop_back();
		}
		S.back() ++;
		print(S);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}