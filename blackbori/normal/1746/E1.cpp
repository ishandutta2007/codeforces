#include <bits/stdc++.h>

using namespace std;

int B[22];

void guess(int x) {
	printf("! %d\n", x);
	fflush(stdout);

	char S[9];
	scanf("%s", S);
	if (S[1] == ')') exit(0);
}

int ask(vector<int> &X) {
	printf("? %d", X.size());
	for (auto &x: X) printf(" %d", x);
	printf("\n"); fflush(stdout);

	char S[9];
	scanf("%s", S);
	return S[0] == 'Y';
}

void solve(vector<int> V) {
	if (V.empty()) {
		assert(false);
		return;
	}
	if (V.size() == 1) {
		guess(V[0]);
		assert(false);
		return;
	}
	else if (V.size() == 2) {
		guess(V[0]); guess(V[1]);
		assert(false);
		return;
	}

	int b, i, j, n = V.size(), x, y;
	for (b = 0; 1 << b < n; b++);

	for (i = 0; i < b; i++) {
		vector<int> X;
		for (j = 0; j < n; j++) {
			if (j >> i & 1) X.push_back(V[j]);
		}
		x = ask(X); y = ask(X);
		B[i] = x;
		if (x == y) break;
	}

	vector<int> Y;
	int k = i;
	for (i = 0; i < n; i++) {
		if (k < b && (i >> k & 1) != B[k]) continue;
		
		y = 1;
		for (j = 0; j < k; j++) {
			x = (i >> j & 1) ^ B[j];
			if (y == 0 && x == 1) break;
			y = x;
		}
		if (j == k) Y.push_back(V[i]);
	}

	assert(Y.size() < V.size());

	solve(Y);
}

void tc() {
	int n;
	scanf("%d", &n);
	vector<int> V(n);
	iota(V.begin(), V.end(), 1);
	solve(V);
}

int main() {
	tc();

	return 0;
}