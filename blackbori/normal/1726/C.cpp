#include <bits/stdc++.h>

using namespace std;

void tc() {
	vector<int> V;
	string S;
	int n, i, t, f, a, s;
	cin >> n >> S;
	for (i = 0, a = s = 0; i < n + n; i++) {
		if (S[i] == '(') t = a++;
		else t = --a;
		for (f = 0; !V.empty() && V.back() > t; V.pop_back()) f = 1;
		V.push_back(t);
		s += f;
	}
	if (!V.empty()) s++, V.clear();
	cout << s << "\n";
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