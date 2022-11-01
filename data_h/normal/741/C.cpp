#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 7;

int n;
int go[N], visit[N], val[N], boy[N], girl[N];

void dfs(int x) {
	val[x] = 1;
	val[go[x]] = 2;
	visit[x] = visit[go[x]] = 1;
	if (!visit[go[x] ^ 1]) {
		dfs(go[x] ^ 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		boy[i] = --a;
		girl[i] = --b;
		go[a] = b;
		go[b] = a;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (!visit[i]) {
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", val[boy[i]], val[girl[i]]);
	}
	return 0;
}