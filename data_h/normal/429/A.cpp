#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 111111;

int n;
int init[N], goal[N];
vector<int> e[N];
int opt[2], ans = 0;
vector<int> result;

void dfs(int x, int dep, int fa) {
	init[x] ^= opt[dep];
	if (init[x] != goal[x]) {
		ans++;
		result.push_back(x);
		opt[dep] ^= 1;
	}
	
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == fa)
			continue;
		dfs(y, dep ^ 1, x);
	}
	if (init[x] != goal[x]) {
		opt[dep] ^= 1;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &init[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &goal[i]);
	}
	dfs(1, 0, 0);
	printf("%d\n", ans);
	sort(result.begin(), result.end());
	for(int i = 0; i < ans; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}