#include <bits/stdc++.h>

const int MAXN = 500010;

int A[MAXN], n, B[MAXN], cur;
int head[MAXN], nxt[MAXN], to[MAXN], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
}
void dfs(int u) {
	B[u] = cur--;
	for (int i = head[u]; i; i = nxt[i])
		dfs(to[i]);
}
int st[MAXN], top;
int main() {
	int T; scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n); cur = n + 1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", A + i);
			if (A[i] == -1) A[i] = i + 1;
		}
		for (int i = n; i; --i) addedge(A[i], i);
		dfs(n + 1);
		tot = 0; B[n + 1] = 0;
		memset(head, 0, n + 2 << 2);
		// puts("SPLIT"); for (int i = 1; i <= n; ++i) printf("%d ", B[i]); putchar(10);
		top = 0;
		for (int i = n; i; --i) {
			while (top && B[i] > st[top]) --top;
			if (st[top] != B[A[i]]) {
				puts("-1");
				goto https;
			}
			st[++top] = B[i];
		}
		for (int i = 1; i <= n; ++i) printf("%d ", B[i]); putchar(10);
		https://codeforces.com
	;}
	return 0;
}