#include <bits/stdc++.h>
using namespace std;
bool adj[505][505];
char ans[505];
int n;
void dfs (int cur) {
	for (int i = 1; i <= n; i++) if (!adj[cur][i] && !ans[i]) {
		ans[i] = ans[cur] ^ 2;
		dfs(i);
	}
}
int main () {
	int m;
	scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a][b] = adj[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) if (!ans[i]) {
		bool isB = 1;
		for (int j = 1; j <= n; j++) isB &= i == j || adj[i][j];
		if (isB) ans[i] = 'b';
		else {ans[i] = 'a'; dfs(i);}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (i != j && adj[i][j] != (abs(ans[i] - ans[j]) <= 1))
			return !printf ("No\n");
	printf ("Yes\n%s\n",ans+1);
	return 0;
}