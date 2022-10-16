#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<int> T1[303030], T2[303030];
set<pii> S;
int L[303030], R[303030];
int n, dn, a;

void dfs2(int u) {
	L[u] = ++dn;
	for (int &v: T2[u]) {
		dfs2(v);
	}
	R[u] = dn;
}

void dfs1(int u) {
	auto it = S.lower_bound(pii(L[u], R[u]));
	pii p(-1, -1);
	if (it != S.begin() && prev(it)->second >= R[u]) {
		p = *prev(it);
		S.erase(prev(it));
	}
	S.insert(pii(L[u], R[u]));
	a = max(a, (int)S.size());

	for (int &v: T1[u]) {
		dfs1(v);
	}

	if (p.first != -1) {
		S.insert(p);
	}
	S.erase(S.find(pii(L[u], R[u])));
}


void tc() {
	int i, t;
	cin >> n;

	for (i = 1; i <= n; i++) {
		T1[i].clear(); T2[i].clear();
	}

	for (i = 2; i <= n; i++) {
		cin >> t; T1[t].push_back(i);
	}
	for (i = 2; i <= n; i++) {
		cin >> t; T2[t].push_back(i);
	}

	dn = a = 0; dfs2(1);
	dfs1(1);
	
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}