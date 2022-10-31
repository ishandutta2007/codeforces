#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bitset<1010> a[1010], graph[1010], non_leaf;
set<pii> edge;

inline int nextInt() {
	int x;
	scanf("%d", &x);
	return x;
}

inline int addEdge (int x, int y) {
	printf("%d %d\n", x, y);
}

int main() {
	int n = nextInt();
	for (int i=0; i<n; i++) {
		int ncase = nextInt();
		for (int j=0; j<ncase; j++) {
			a[i].set(nextInt());
		}
	}
	int u, v;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			auto tmp = a[i] & a[j];
			if (tmp.count() != 2) continue;
			u = tmp._Find_first();
			v = tmp._Find_next(u);
			if (!graph[u][v]) {
				graph[u][u] = graph[u][v] = graph[v][u] = graph[v][v] = 1;
				non_leaf[u] = non_leaf[v] = 1;
				addEdge(u, v);
			}
		}
	}
	if (non_leaf.count() == 0) {
		for (int i=2; i<=n; i++) {
			addEdge(1, i);
		}
	} else if (non_leaf.count() == 2) {
		for (int i=0; i<n; i++) {
			if (a[i].count() == n) continue;
			for (int j=1; j<=n; j++) {
				if (!non_leaf[j]) {
					addEdge(j, a[i][j] ? u : v);
				}
			}
			break;
		}
	} else {
		for (int leaf=1; leaf<=n; leaf++) {
			if (non_leaf[leaf]) continue;
			auto min_set = non_leaf;
			for (int i=0; i<n; i++) if(a[i][leaf]) min_set &= a[i];
			for (int i=1; i<=n; i++) {
				if (min_set == graph[i]) {
					addEdge(leaf, i);
					break;
				}
			}
		}
	}
}