#include <iostream>
#include <string>
#include <vector>
using namespace std;

string S; long long ans = 0, teisuu = 1, mod = 998244353;
vector<pair<int, int>>X[1009]; int dep[1009]; bool flag = false;

void dfs(int pos, int rec) {
	if (dep[pos] >= 0) {
		if (dep[pos] != rec) flag = true;
		return;
	}
	dep[pos] = rec;
	for (int i = 0; i < X[pos].size(); i++) {
		dfs(X[pos][i].first, rec ^ X[pos][i].second);
	}
}

long long solve(int cl, int cr) {
	flag = false;
	for (int i = 0; i < S.size(); i++) X[i].clear();

	for (int i = cl; i <= cr; i++) {
		int u1 = i, u2 = cr - (i - cl);
		if (u1 < u2) { X[u1].push_back(make_pair(u2, 0)); X[u2].push_back(make_pair(u1, 0)); }
	}
	for (int i = 0; i < S.size(); i++) {
		int u1 = i, u2 = S.size() - 1 - i;
		if (u1 < u2 && S[u1] != '?' && S[u2] != '?') {
			if (S[u1] == S[u2]) { X[u1].push_back(make_pair(u2, 0)); X[u2].push_back(make_pair(u1, 0)); }
			if (S[u1] != S[u2]) { X[u1].push_back(make_pair(u2, 1)); X[u2].push_back(make_pair(u1, 1)); }
		}
	}
	for (int i = 0; i < S.size(); i++) dep[i] = -1;
	
	long long rem = 1;
	for (int i = 0; i < S.size(); i++) {
		if (dep[i] >= 0) continue;

		int V = 0; if (i == cl) V = 1;
		dfs(i, V);

		if (i > cl) rem *= 2;
		rem %= mod;
	}
	if (flag == true) return 0;
	for (int i = 0; i < cl; i++) {
		if (dep[i] == 1) return 0;
	}
	if (dep[cl] == 0) return 0;

	return rem;
}

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		int u1 = i, u2 = S.size() - 1 - i;
		if (u1 <= u2 && S[u1] == '?' && S[u2] == '?') { teisuu *= 2; teisuu %= mod; }
	}
	for (int i = 1; i < S.size(); i++) {
		ans += solve(i, S.size() - 1);
		ans %= mod;
	}
	cout << (ans * teisuu) % mod << endl;
	return 0;
}