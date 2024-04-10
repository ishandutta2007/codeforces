/*
a,b,c:
s[i]s[j]acij

n<=500
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 509;
int w[maxn][maxn], ans[maxn];
int n, m, u, v;

void dfs(int u){
	for (int i=1; i<=n; i++)
		if (w[u][i] && ans[i] == -1){
			ans[i] = !ans[u];
			dfs(i);
		}
		else if (w[u][i] && u != i && ans[i] == ans[u]){
			puts("No");
			exit(0);
		}
}

bool judge(int u){
	for (int i=1; i<=n; i++) if (w[u][i]) return true;
	return false;
}

bool check(){
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (ans[i] + ans[j] == 1 && !w[i][j])
				return false;
	return true;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++){
		ans[i] = -1;
		for (int j=1; j<=n; j++)
			w[i][j] = 1;
		w[i][i] = 0;
	}
	for (int i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		w[u][v] = w[v][u] = 0;
	}
	for (int i=1; i<=n; i++)
		if (judge(i) && ans[i] == -1) { ans[i] = 1; dfs(i); }
	if (!check()) { puts("No"); return 0; }
	puts("Yes");
	for (int i=1; i<=n; i++)
		if (ans[i] == -1) putchar('b');
		else if (ans[i]) putchar('a');
		else putchar('c');
	return 0;
}