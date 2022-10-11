#include<iostream>
#include<vector>
using namespace std;
int n, a[100009], s, f, p[100009], c[1 << 24], h[100009]; vector<int>x[100009]; long long cnt = 0;
void dfs(int pos) {
	if (x[pos].size() == 0) { h[pos] = 1; return; }
	for (int i = 0; i < x[pos].size(); i++) {
		dfs(x[pos][i]);
		if (h[x[pos][i]] == 0) { h[pos] = 1; }
	}
}
int main() {
	cin >> n; for (int i = 1; i <= n; i++) { cin >> a[i]; }
	for (int i = 2; i <= n; i++) { cin >> p[i]; x[p[i]].push_back(i); }
	dfs(1);
	for (int i = 1; i <= n; i++) { if (h[i] == 0)c[a[i]]++; else { s ^= a[i]; f++; } }
	for (int i = 1; i <= n; i++) { if (h[i] == 1)cnt += c[s^a[i]]; }
	if (s == 0) { cnt += 1LL * f*(f - 1) / 2LL; cnt += 1LL * (n - f)*(n - f - 1) / 2LL; }
	cout << cnt << endl;
	return 0;
}