#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


const int N = 1000000 + 10;

vector<int> e[N][2];

int child[N][2];
int n, c, pt = 2;
int forbid[N];

void dead() {
	puts("IMPOSSIBLE");
	exit(0);
}

void dfs(int x, int final) {
	int lc = x;
	for(int i = 0; i < (int)e[x][0].size(); i++) {
		int y = e[x][0][i];
		if (y < pt) {
			dead();
		}

		lc = max(lc, y);
	}
	if (lc > x) {
		child[x][0] = pt++;
		dfs(pt - 1, lc);
	}
	int rc = x;
	for(int i = 0; i < (int)e[x][1].size(); i++) {
		int y = e[x][1][i];
		if (y < pt) {
			dead();
		}
		rc = max(rc, y);
	}
	if (max(final, rc) >= pt) {
		child[x][1] = pt++;
		dfs(pt - 1, max(rc, final)); 
	}
}

void go(int x) {
	if (child[x][0]) {
		go(child[x][0]);
	}
	printf("%d ", x);
	if (child[x][1]) {
		go(child[x][1]);
	}
}

int main() {
	scanf("%d %d", &n, &c);
	forbid[n + 1] = 1;
	for(int i = 1; i <= c; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (b <= a) {
			dead();
		}
		static char buffer[100];
		scanf("%s", buffer);
		if (buffer[0] == 'L') {
			e[a][0].push_back(b);
		} else {
			e[a][1].push_back(b);
		}
	}
	dfs(1, n);
	go(1);
	puts("");
	return 0;
}