#include <bits/stdc++.h>
using namespace std;
struct node {
	vector <int> son;
	int father;
}s[200005];
// pos[i]1i
// fro[i]1i 
int pos[200005], fro[200005];
int dp[200005], n, q, cnt;
inline void insert(int k, int x) {
	s[k].father = x;
	s[x].son.push_back(k);
	return ;
}
inline void dfs(int k) {
//	printf("%d ", k);
	dp[k] = 1;
	pos[++cnt] = k;
	fro[k] = cnt;
	int len = s[k].son.size();
	for (int i = 0; i < len; i++) {
		dfs(s[k].son[i]);
		dp[k] += dp[s[k].son[i]];
	}
	return ;
}
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		insert(i, x);
	}
	dfs(1);
	while (q--) {
		int u, k;
		scanf("%d %d", &u, &k);
		if (dp[u] < k)
			puts("-1");
		else
			printf("%d\n", pos[fro[u] + k - 1]);
	}
	return 0;
}