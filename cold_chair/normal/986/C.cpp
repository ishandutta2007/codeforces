#include<cstdio>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1 << 22;

int n, m, a[N + 5], bx[N * 2 + 5], bz[N * 2 + 5], ans, a2[26];

void dfs(int x) {
	if(bz[x]) return;
	bz[x] = 1;
	if(x < N) {
		dfs(x + N);
	} else {
		if(bx[a2[n] - 1 - (x - N)]) dfs(a2[n] - 1 - (x - N));
		fo(i, 0, n - 1) if(!(x & a2[i]))
			dfs(x | a2[i]);
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	a2[0] = 1; fo(i, 1, 25) a2[i] = a2[i - 1] * 2;
	scanf("%d %d", &n, &m);
	fo(i, 1, m) scanf("%d", &a[i]), bx[a[i]] = 1;
	fo(i, 1, m) if(!bz[a[i]]) {
		dfs(a[i]); ans ++;
	}
	printf("%d", ans);
}