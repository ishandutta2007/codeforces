#include <bits/stdc++.h>

using namespace std;

vector<int> V[202020], X, Y;
int XC[202020], YC[202020];
int A[202020], B[202020];
int n;

void tc() {
	int i, a;
	cin >> n;
	fill(XC, XC + n + 1, 0);
	fill(YC, YC + n + 1, 0);
	X.clear(); Y.clear();
	for (i = 1; i <= n; i++) V[i].clear();

	for (i = 1; i <= n; i++) {
		cin >> A[i];
		V[A[i]].push_back(i);
	}
	for (i = 1; i <= n; i++) {
		if (V[i].empty()) {
			XC[i] = 1;
		}
		for (; V[i].size() > 1; V[i].pop_back()) {
			YC[V[i].back()] = 1;
		}
	}

	for (i = 1; i <= n; i++) {
		if (XC[i] && YC[i]) {
			X.push_back(i); Y.push_back(i);
		}
	}
	for (i = 1; i <= n; i++) {
		if (XC[i] && !YC[i]) X.push_back(i);
		if (!XC[i] && YC[i]) Y.push_back(i);
	}

	for (i = 1; i <= n; i++) B[i] = A[i];

	if (X.size() == 1 && X[0] == Y[0]) {
		for (i = 1; i <= n; i++) {
			if (i != X[0] && B[i] == B[X[0]]) break;
		}
		B[i] = X[0];
	}
	else if (!Y.empty()) {
		Y.push_back(Y[0]);
		for (i = 0; i < X.size(); i++) {
			B[Y[i + 1]] = X[i];
		}
	}

	a = 0;
	for (i = 1; i <= n; i++) {
		a += (A[i] == B[i]);
	}
	cout << a << "\n";
	for (i = 1; i <= n; i++) {
		cout << B[i] << " ";
	}
	cout << "\n";
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