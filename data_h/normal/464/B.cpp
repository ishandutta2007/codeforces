#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const long long INF = (1LL << 60);

struct Node {
	int d[3];
	Node (int x = 0, int y = 0, int z = 0) {
		d[0] = x;
		d[1] = y;
		d[2] = z;
	}
};

vector<Node> points;
Node s[8];

__inline long long sqr(long long x) {
	return x * x;
}

__inline long long calc(const Node &a, const Node &b) {
	return sqr(a.d[0] - b.d[0]) + sqr(a.d[1] - b.d[1]) + sqr(a.d[2] - b.d[2]);
}


long long ds[30];

bool check() {
	int tot = 0;
	long long delta = INF;
	for(int i = 0; i < 8; i++)
		for(int j = i + 1; j < 8; j++) {
			ds[tot++] = calc(s[i], s[j]);
			delta = min(delta, ds[tot - 1]);
		}
	if (delta == 0) {
		return false;
	}
	sort(ds, ds + tot);
	long long a = ds[0], b = ds[12], c = ds[24];
	if (!(a * 2 == b && a * 3 == c)) {
		return false;
	}
	for(int i = 0; i < 12; i++) {
		if (ds[i] != a) {
			return false;
		}
	}
	for(int i = 12; i < 24; i++) {
		if (ds[i] != b) {
			return false;
		}
	}
	for(int i = 24; i < 28; i++) {
		if (ds[i] != c) {
			return false;
		}
	}
	return true;
}

int dfs(int d) {
	if (d == 8) {
		return check();
	}
	
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if (i != j) {
				for(int k = 0; k < 3; k++) {
					if (k != i && k != j) {
						s[d] = Node(points[d].d[i], points[d].d[j], points[d].d[k]);
						if (dfs(d + 1)) {
							return 1;
						}
					}
				}
			}
	return 0;
}

int main() {
	
	for(int i = 0; i < 8; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		points.push_back(Node(x, y, z));
	}
	s[0] = points[0];
	if (dfs(1)) {
		puts("YES");
		for(int i = 0; i < 8; i++) {
			printf("%d %d %d\n", s[i].d[0], s[i].d[1], s[i].d[2]);
		}
	} else {
		puts("NO");
	}
	return 0;
}