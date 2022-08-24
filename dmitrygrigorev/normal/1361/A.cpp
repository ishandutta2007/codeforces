#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;
vector<int> ind;

bool cmp(int a, int b) {
	return (ind[a] < ind[b]);
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	data.assign(n, {});
	ind.assign(n, -1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}

	for (int i = 0; i < n; ++i) {
		cin >> ind[i];
		ind[i]--;
	}

	vector<int> a;
	for (int i = 0; i < n; ++i) a.push_back(i);
	sort(all(a), cmp);

	vector<int> t(n, -1);

	vector<bool> was(n, false);

	for (int i = 0; i < n; ++i) {
		int W = a[i];
		for (auto to : data[W]) {
			if (t[to] >= 0) was[t[to]] = true;
		}

		int u = 0;
		while (was[u]) u++;
		t[W] = u;

		for (auto to : data[W]) {
			if (t[to] >= 0) was[t[to]] = false;
		}		

	}

	if (t != ind) {
		cout << -1;
		exit(0);
	}

	for (int i = 0; i < n; ++i) cout << a[i]+1 << " ";

}