#include<iostream>
#include<vector>
using namespace std;
int power[100009], col[100009], n, m, a, b, c, cnt, mod = 1000000007; bool OK = false; vector<pair<int, int>>v[100009];
void dfs(int pos, int dep) {
	if (col[pos] >= 0) {
		if (col[pos] != dep)OK = true;
		return;
	}
	col[pos] = dep;
	for (int i = 0; i < v[pos].size(); i++)dfs(v[pos][i].first, dep^v[pos][i].second);
}
int main() {
	power[0] = 1; for (int i = 1; i <= 100008; i++) { power[i] = power[i - 1] * 2; power[i] %= mod; }
	cin >> n >> m; for (int i = 1; i <= n; i++)col[i] = -1;
	for (int i = 0; i < m; i++) { cin >> a >> b >> c; c ^= 1; v[a].push_back(make_pair(b, c)); v[b].push_back(make_pair(a, c)); }
	for (int i = 1; i <= n; i++) { if (col[i] == -1) { cnt++; dfs(i, 0); } }
	if (OK == false)cout << power[cnt - 1] << endl;
	else cout << "0" << endl;
	return 0;
}