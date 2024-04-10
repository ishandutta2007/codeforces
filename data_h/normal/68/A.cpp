#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int p[5], a, b, visit[5], res = 0;

void dfs(int dep, int now, int source) {
	if (dep > 4) {
		if (now == source)
			res++;
		return ;
	}
	for(int i = 1; i <= 4; i++)
		if (!visit[i]) {
			visit[i] = 1;
			dfs(dep + 1, now % p[i], source);
			visit[i] = 0;
		}
}

int ok(int x) {
	res = 0;
	dfs(1, x, x);
	return res;
}

int main() {

	for(int i = 1; i <= 4; i++) {
		scanf("%d", &p[i]);
	}
	int ans = 0;
	scanf("%d %d", &a, &b);
	for(int i = a; i <= b; i++)
		if (ok(i) >= 7)
			ans++;
	printf("%d\n", ans);
	return 0;
}