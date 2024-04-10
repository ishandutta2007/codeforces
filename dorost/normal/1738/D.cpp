/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int b[N], a[N];
vector <int> v[N];
bool vis[N];
int t = 0;

void dfs(int x) {
	vis[x] = true;
	for (int y : v[x]) {
		if (vis[y] || v[y].size())
			continue;
		a[++t] = y;
	}
	int cnt = 0;
	for (int y : v[x]) {
		if (vis[y] || !v[y].size())
			continue;
		a[++t] = y;
		cnt++;
		dfs(y);
	}
}

void solve() {
	int n, k;
	cin >> n;
	t = 0;
	for (int i = 0; i <= n + 5; i++)
		v[i].clear(), vis[i] = false;
	set <int> st;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		v[b[i]].push_back(i);
	}
	int f = -1, l = -1;
	for (int i = 0; i <= n; i++) {
		for (int j : v[i])
			st.insert(j);
		if (i == n && (int)st.size() == 0) {
			if (f == -1)
				f = i;
			l = i;
			continue;
		}
		if ((int)st.size() == (n - i) && (*st.begin()) == (i + 1)) {
			if (f == -1)
				f = i;
			l = i;
		}
	}
	k = f;
	assert(k != -1);
	bool is0 = (bool)v[0].size();
	bool isn = (bool)v[n + 1].size();
	if (is0)
		dfs(0);
	else
		dfs(n + 1);
	cout << k << '\n';
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
	cout << '\n';
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		assert(a[i] == i);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}