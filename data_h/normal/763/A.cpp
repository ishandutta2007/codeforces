#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

const int N = 1e5 + 7;

int down[N], up[N];
int color[N], n;
vector<int> adj[N];

bool ok;

void check(int u, int from, int c) {
	if (color[u] != c) ok = false;
	for (auto v : adj[u]) {
		if (v != from) {
			check(v, u, c);
		}
	}
}

int test(int u) {
	ok = true;
	for (auto v : adj[u]) {
		check(v, u, color[v]);
	}
	return ok;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
	}
	for (int u = 1; u <= n; u++) {
		for (auto v : adj[u]) {
			if (color[u] != color[v]) {
				if (test(u) || test(v)) {
					puts("YES");
					if (test(u)) {
						printf("%d\n", u);
					} else {
						printf("%d\n", v);
					}
					return 0;
				} else {
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	printf("1\n");
	return 0;
}