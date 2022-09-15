#include <bits/stdc++.h>

#define pb push_back
#define ld double
#define ll long long
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int nm = 200010;

int n, a[nm];
vector<int> adj[nm];
int total;
set<int> bad;
int cha[nm][20], d[nm];

void add(int x) {
	cout << x << " ";
	a[x] = -a[x];
	if (a[x] == 1)
		bad.erase(x);
	else
		bad.insert(x);
}

void dfs(int i, int p) {
	cha[i][0] = p;
	for (int j = 1; d[i] - (1 << j) >= 1; ++j)
		cha[i][j] = cha[cha[i][j - 1]][j - 1];
	for (int k = 0; k < adj[i].size(); ++k) {
		int j = adj[i][k];
		if (j != p) {
			d[j] = d[i] + 1;
			dfs(j, i);
		}
	}
}

int jump(int u, int n) {
	for (int i = 0; n; ++i) {
		if ((n >> i) & 1) {
			u = cha[u][i];
			n = ((~(1 << i)) & n);
		}
	}
	return u;
}

int anc(int i, int j) {
	if (d[j] <= d[i])
		return -1;
	int tmp = jump(j, d[j] - d[i]);
	if (tmp == i)
		return jump(j, d[j] - d[i] - 1);
	return -1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	a[1] = -a[1];
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	d[1] = 1;
	dfs(1, -1);
	for (int i = 1; i <= n; ++i)
		if (a[i] == -1)
			bad.insert(i);
	int cur = 1;
	add(1);
	while (bad.size()) {
		int i = *(bad.begin());
		if (i == cur) {
			if (bad.size() >= 2) {
				set<int>::iterator it = bad.begin();
				it++;
				i = *it;
			} else {
				int u = adj[i][0];
				add(u);
				add(i);
				continue;
			}
		}
		int tmp = anc(cur, i);
		if (tmp == -1) {
			cur = cha[cur][0];
			add(cur);
		} else {
			cur = tmp;
			add(tmp);
		}
	}
}