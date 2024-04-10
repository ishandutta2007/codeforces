#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, p, q, dp[100009], r[100009], par[100009], power[1000009], mod = 1000000007;
vector<int>x[100009]; bool used[100009];

long long dfs1(int pos) {
	used[pos] = true;
	long long ret = 0; bool P = false;
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == true)continue;
		ret += dfs1(x[pos][i]); P = true; par[x[pos][i]] = pos;
	}
	if (P == true)ret += 1;
	dp[pos] = ret;
	return ret;
}
void dfs2(int pos, int pars) {
	used[pos] = true;
	if (pars == -1)r[pos] = 1;
	else {
		int G = 0; if (pars == 1 && x[pars].size() >= 2)G = 1;
		r[pos] = r[pars] * power[dp[pars] - dp[pos] + G]; r[pos] %= mod;
	}
	for (int i = 0; i < x[pos].size(); i++) {
		if (used[x[pos][i]] == true)continue;
		dfs2(x[pos][i], pos);
	}
}
int main() {
	cin >> n; power[0] = 1; for (int i = 1; i < 1000000; i++)power[i] = (power[i - 1] * 2) % mod;
	for (int i = 0; i < n - 1; i++) {
		cin >> p >> q; x[p].push_back(q); x[q].push_back(p);
	}
	dfs1(1); for (int i = 0; i < 100009; i++)used[i] = false;
	dfs2(1, -1); r[0] = 1;
	long long T = 0; for (int i = 1; i <= n; i++) { int V = 0; if (i >= 2 && dp[i] >= 1)V = 1; T += power[dp[i] - V] * r[i]; T %= mod; }
	cout << T << endl;
	return 0;
}