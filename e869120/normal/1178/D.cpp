#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
#pragma warning (disable: 4996)

bool isprime(int x) {
	if (x == 1) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

int N;

void solve() {
	for (int i = N; i <= N * 3 / 2; i++) {
		if (isprime(i) == false) continue;

		vector<pair<int, int>> G;
		for (int j = 0; j < N; j++) {
			G.push_back(make_pair(j + 1, ((j + 1) % N) + 1));
		}

		vector<int> L1, L2;
		for (int j = 1; j <= N / 2; j++) L1.push_back(j);
		for (int j = (N / 2) + 1; j <= N; j++) L2.push_back(j);

		for (int j = 1; j <= i - N; j++) {
			G.push_back(make_pair(L1[j - 1], L2[j - 1]));
		}

		cout << G.size() << endl;
		for (int j = 0; j < G.size(); j++) cout << G[j].first << " " << G[j].second << endl;
		return;
	}
	assert(N == 1);
}

int main() {
	cin >> N;
	solve();
	return 0;
}