#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int P[2200];
int n;

void yeah(int p) {
	reverse(P + 1, P + p + 1);
	A.push_back(p);
}

void tc() {
	int i, k, f;
	cin >> n; f = 0;
	for (i = 1; i <= n; i++) {
		cin >> P[i];
		if ((P[i] - i) & 1) f = 1;
	}
	if (f) {
		cout << "-1\n";
		return;
	}
	for (k = n; k > 1; k -= 2) {
		for (i = 1; i <= k && P[i] != k; i++);
		yeah(i);
		for (i = 1; i <= k && P[i] != k - 1; i++);
		yeah(i - 1); yeah(i + 1);
		yeah(3); yeah(k);
	}
	for (i = 1; i <= n; i++) {
		assert(P[i] == i);
	}
	assert(A.size() * 2 <= n * 5);

	cout << A.size() << "\n";
	for (auto &t: A) cout << t << " ";
	cout << "\n";
	A.clear();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}