/* 	* In the name of GOD  */

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,lzcnt,popcnt")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mk make_pair
const int N = 2012345;
int a[N / 2], b[N / 2], n, ans = 0;
vector <int> wef;
bool vis[N];
vector <int> g[N];

void dfs (int v, int x) {
	if (wef[v] > x) {
		ans++;
		return;
	}
	vis[v] = true;
	ans -= 2;
	for (int u : g[v]) {
		ans++;
		if (!vis[u])
			dfs(u, x);
	}
}

bool is_valid (int x) {
	for (int i = 0; i < N; i++)
		vis[i] = false;
	bool f = true;
	for (int i = 0; i < n; i++) {
		f &= (a[i] <= x);
	}
	if (!f)
		return false;
	for (int i = 0; i < wef.size() && f; i++) {
		if (!vis[i] && wef[i] <= x) {
			ans = 0;
			dfs(i, x);
			f &= (ans <= 0);
		}
	}
	return f;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		wef.push_back(a[i]);
		wef.push_back(b[i]);
	}
	sort(wef.begin(), wef.end());
	wef.resize(unique(wef.begin(), wef.end()) - wef.begin());
	for (int i = 0; i < n; i++) {
		int wa = lower_bound(wef.begin(), wef.end(), a[i]) - wef.begin();
		int wb = lower_bound(wef.begin(), wef.end(), b[i]) - wef.begin();
		g[wa].push_back(wb);
		g[wb].push_back(wa);
	}
	int l = -1, r = wef.size();
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (is_valid(wef[mid]))
			r = mid;
		else
			l = mid;
	}
	cout << (r >= wef.size() ? -1 : wef[r]) << '\n';
}