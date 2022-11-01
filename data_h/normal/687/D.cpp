#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int father[N], dis[N];

struct Edge {
	int id, u, v, w;
	Edge(int id, int u, int v, int w) : id(id), u(u), v(v), w(w) {}
	bool friend inline operator <(const Edge &a, const Edge &b) {
		return a.w > b.w;
	}
};

vector<Edge> edges;

int n, m, q;

int get_father(int x) {
	int t = x, tot = 0;
	while (father[t] != t) {
		tot ^= dis[t];
		t = father[t];
	}
	while (father[x] != x) {
		int tmp = father[x];
		tot ^= dis[x];
		dis[x] ^= tot;
		father[x] = t;
		x = tmp;
	}
	return x;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back(Edge(i, u, v, w));
	}
	sort(edges.begin(), edges.end());

	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		bool exist = false;

		for (int j = 1; j <= n; j++) {
			father[j] = j;
			dis[j] = 0;
		}

		for (int j = 0; j < edges.size(); j++) {
			if (l <= edges[j].id && edges[j].id <= r) {
				int u = edges[j].u, v = edges[j].v;
				//cout << u << " " << v << endl;
				if (get_father(u) == get_father(v)) {
					//cout << father[u] << " father " << father[v] << endl;
					//cout << dis[u] << " dis " << dis[v] << endl;
					if ((dis[u] ^ dis[v]) != 1) {
						printf("%d\n", edges[j].w);
						exist = true;
						break;
					}
				} else {
					dis[father[u]] = (1 ^ dis[u]);
					father[father[u]] = v;
				}
			}
		}
		if (!exist) {
			printf("-1\n");
		}
	}
	return 0;
}