//started coding on 2.54pm;
#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

vector<int> vec[N], t[N];
int a[N], b[N], w[N];
void update(vector<int> &v, int p, int x) {
	for (; p < v.size(); p += p & -p) v[p] = max(v[p], x);
}

int get(vector<int> &v, int p) {
	int ret = 0;
	for (; p; p -= p & -p) ret = max(ret, v[p]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i] >> b[i] >> w[i];
		vec[b[i]].push_back(w[i]);
	}
	for (int i = 1; i <= n; i++) sort(vec[i].begin(), vec[i].end()), t[i].resize(vec[i].size() + 1);
	int dap = 0;
	for (int i = 1; i <= m; i++) {
		int p = lower_bound(vec[a[i]].begin(), vec[a[i]].end(), w[i]) - vec[a[i]].begin();
		int x = get(t[a[i]], p) + 1;
		p = upper_bound(vec[b[i]].begin(), vec[b[i]].end(), w[i]) - vec[b[i]].begin();
		update(t[b[i]], p, x);
		dap = max(dap, x);
	}
	cout << dap << endl;
	return 0;
}
//ended coding on 3.00pm;