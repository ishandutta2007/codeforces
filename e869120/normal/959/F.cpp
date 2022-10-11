#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int dig[1 << 22], power[1 << 17];

void init() {
	dig[0] = 0; dig[1] = 1;
	for (int i = 1; i <= 21; i++) {
		for (int j = (1 << i); j < (2 << i); j++) dig[j] = i + 1;
	}
	power[0] = 1;
	for (int i = 1; i <= 100000; i++) power[i] = (2 * power[i - 1]) % 1000000007;
}

vector<int> calc(vector<int> E) {
	while (true) {
		sort(E.begin(), E.end());
		int id = -1;
		for (int j = (int)E.size() - 1; j >= 1; j--) {
			if (dig[E[j]] == dig[E[j - 1]]) { id = j; break; }
		}
		if (id == -1) break;
		for (int j = id - 1; j >= 0; j--) {
			if (dig[E[j]] != dig[E[id]]) break;
			E[j] ^= E[id];
		}
	}
	return E;
}

bool makeable(vector<int> R, int t) {
	for (int i = R.size() - 1; i >= 0; i--) {
		t = min(t, t^R[i]);
	}
	if (t == 0) return true;
	return false;
}

int N, Q, A[1 << 17];
vector<int> G[1 << 17];

int main() {
	init();
	scanf("%d%d", &N, &Q);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for (int i = 1; i <= N; i++) {
		if (makeable(G[i - 1], A[i]) == false) {
			G[i] = G[i - 1];
			G[i].push_back(A[i]);
			G[i] = calc(G[i]);
		}
		else G[i] = G[i - 1];
	}
	for (int i = 1; i <= Q; i++) {
		int l, x; scanf("%d%d", &l, &x);
		if (makeable(G[l], x) == true) printf("%d\n", power[l - G[l].size()]);
		else printf("0\n");
	}
	return 0;
}