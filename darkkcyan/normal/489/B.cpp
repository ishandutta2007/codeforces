#include <bits/stdc++.h>
using namespace std;

#define maxn 111
vector<int> b, g;
int n, m;
vector<int> match;
bitset<maxn> vis;

bool bmp(int v) {
	if (vis[v]) return false;
	vis[v] = true;
	for (int i = 0; i < m; ++i) {
		if (abs(g[i] - b[v]) > 1) continue;
		if (!~match[i] or bmp(match[i])) {
			match[i] = v;
			return true;
		}
	}
	
	return false;
}

int main() {
	cin >> n;
	b.resize(n);
	for (int i = 0; i < n; ++i) cin >> b[i];
	cin >> m;;
	g.resize(m);
	for (int i = 0; i < m; ++i) cin >> g[i];
	
	match.resize(m, -1);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		vis.reset();
		ans += bmp(i);
	}
	cout << ans;
	return 0;
}