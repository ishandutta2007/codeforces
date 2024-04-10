#include <bits/stdc++.h>
using namespace std;
 
#define N 70070
 
int n, a[N], id[N], did[N], prv[N], gas[N], s;
 
bool cmp(int i, int j) {
	return a[i] < a[j];
}
 
int vis[N], ans[N], e;
 
bool dfs(int x, int k) {
    if (!x) return 1;
	if (vis[x] >= k) return 0;
	vis[x] = max(vis[x], k);
    for (int i = k; i >= 1; i --) if (x >= a[i]) {
        if (dfs(x - a[i], i - 1)) {
			ans[++e] = i;
			return 1;
        }
    }
    return 0;
}
 
int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		id[i] = i;
	}
	sort (id + 1, id + n + 1, cmp);
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) did[id[i]] = i;
	if (s >= a[n] && dfs(s - a[n], n - 1)) {
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= e; i ++) vis[ans[i]] = 1;
		vis[0] = 1;
		for (int i = 1; i <= n; i ++) {
            if (vis[i-1]) prv[i] = 0, gas[i] = 0;
            else prv[i] = i - 1, gas[i] = 1;
		}
		for (int i = 1; i <= n; i ++) {
			int now = did[i];
			printf("%d %d", a[now] - a[prv[now]], gas[now]);
			now = prv[now];
			if (now) printf(" %d", id[now]);
			puts("");
		}
	}
	else puts("-1");
	return 0;
}