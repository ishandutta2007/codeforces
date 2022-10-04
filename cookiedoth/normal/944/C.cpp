#include <bits/stdc++.h>
#define ll long long
#define null null

using namespace std;

const int mx = 3e5;
int n, p[mx], t[mx];
vector<int> children[mx];

void dfs(int v, int h) {
	t[h] = (t[h] + 1) % 2;
	for (auto v1 : children[v]) {
		dfs(v1, h + 1);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		children[p[i]].push_back(i);
	}
	dfs(0, 0);
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans += t[i];
	}
	cout << ans << endl;
}