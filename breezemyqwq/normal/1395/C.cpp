#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int C = 550;
const int inf = 0x3f3f3f3f;

int n, m, a[N], b[N], vis[C][N], ans = inf;

void dfs(int sum, int depi) {
	if(vis[sum][depi]) return ;
	vis[sum][depi] = true;
	if(depi > n) {
		ans = min(ans, sum);
		return ;
	}
	for(int i = 1; i <= m; i++) {
		dfs((sum | (a[depi] & b[i])), depi + 1);
	} 
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    for(int i = 1; i <= m; i++) scanf("%d", b + i);
    dfs(0, 1);
    printf("%d\n", ans);
    return 0;
}