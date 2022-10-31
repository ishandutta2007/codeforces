#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
vector<int> cand[2], adj[2 * N];
int chk[2 * N], T, h[2 * N];

void add_edge(int u, int v) {
	h[u] = v, h[v] = u;
}

int find_far(int u) {
	queue<int> Q;
	T++;
	Q.push(u);
	chk[u] = T;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int v : adj[u]) if (chk[v] != T) chk[v] = T, Q.push(v);
	}
	return u;
}

void erase(vector<int> &v, int x) {
	for (int i = 0; i < v.size(); i++) if (v[i] == x) {
		swap(v[i], v.back());
		v.pop_back();
		return;
	}
}

bool solve() {
	int sz = cand[0].size();
	if (sz <= 5) {
		int a[5];
		for (int i = 0; i < sz; i++) a[i] = i;
		while (true) {
			for (int i = 0; i < sz; i++) add_edge(cand[0][i], cand[1][a[i]]);
			bool ok = true;
			for (int u : cand[0]) {
				int v = h[u];
				for (int au : adj[u])
					for (int av: adj[v]) if (h[au] == av) {
						ok = false;
					}
				}
			if (ok) return true;
			else if (!next_permutation(a, a + sz)) break;
		}
		return false;
	} else {
		for (int u : cand[0]) if (adj[u].size() == sz - 1) return false;
		for (int v : cand[1]) if (adj[v].size() == sz - 1) return false;
		for (int m = 0; m < 2; m++) {
			for (int i : cand[m]) if (adj[i].size() == sz - 2) {
				int u = i, v, w, _u, _v, _w;
				for (int j : cand[m]) if (adj[j].size() == 1 && adj[j][0] != i) {
					w = j;
					v = adj[j][0];
					break;
				}
				for (int j : cand[!m]) if (adj[j].size() == 1) {
					_u = j;
					_w = adj[j][0];
					break;
				}
				T++;
				for (int j : adj[_w]) chk[j] = T;
				for (int j : cand[!m]) if (chk[j] != T && j != _w) {
					_v = j;
					break;
				}
				add_edge(u, _u);
				add_edge(v, _v);
				add_edge(w, _w);
				erase(cand[m], u), erase(cand[m], v), erase(cand[m], w);
				erase(cand[!m], _u), erase(cand[!m], _v), erase(cand[!m], _w);
				for (int k = 0; k < cand[m].size(); k++) add_edge(cand[m][k], cand[!m][k]);
				return true;
			}
		}
		int u[2][2], fu[2][2];
		for (int m = 0; m < 2; m++) {
			bool found = 0;
			for (int i : cand[m]) if (adj[i].size() == sz - 3) {
				found = 1;
				for (int j : adj[i]) if (adj[j].size() == 1 && adj[j][0] == i) {
					u[m][0] = j;
					fu[m][0] = i;
					break;
				}
				for (int j : cand[m]) if (adj[j].size() == 1 && adj[j][0] != i && j != i) {
					u[m][1] = j;
					fu[m][1] = adj[j][0];
					break;
				}
				break;
			}
			if (!found) {
				for (int i : cand[m]) if (adj[i].size() == 1) {
					u[m][0] = i;
					break;
				}
				u[m][0] = find_far(u[m][0]);
				u[m][1] = find_far(u[m][0]);
				for (int j = 0; j < 2; j++) fu[m][j] = adj[u[m][j]][0];
			}
		}
		for (int m = 0; m < 2; m++)
			for (int j = 0; j < 2; j++) {
				erase(adj[u[m][j]], fu[m][j]), erase(adj[fu[m][j]], u[m][j]);
				erase(cand[m], u[m][j]);
			}
		if (!solve()) return false;
		if (h[fu[0][0]] == fu[1][0] || h[fu[0][1]] == fu[1][1]) {
			add_edge(u[0][0], u[1][1]);
			add_edge(u[0][1], u[1][0]);
		} else {
			add_edge(u[0][0], u[1][0]);
			add_edge(u[0][1], u[1][1]);
		}
		return true;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cand[0].push_back(i), cand[1].push_back(i + n);
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < n; j++) {
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	if (!solve()) return puts("No"), 0;
	else {
		cout << "Yes\n";
		for (int i = 1; i <= n; i++) cout<<h[i] << " \n"[i == n];
		return 0;
	}
}