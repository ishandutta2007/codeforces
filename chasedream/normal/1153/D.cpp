%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define For(i, l, r) rep(i, l, r - 1)

void read(int &x) {
    x = 0; int f = 1;
    char op = getchar();
    while (!isdigit(op)) {
        if (op == '-') f = -1;
        op = getchar();
    }
    while (isdigit(op)) {
        x = 10 * x + op - '0';
        op = getchar();
    }
    x *= f;
}

const int N = 600005;
struct Edge {
	int to, nxt;
}edge[N << 1];
int head[N], tot;
int n;

void add(int u, int v) {
	edge[++tot] = (Edge){v, head[u]};
	head[u] = tot;
}

int w[N], dp[N];
int tott;

void dfs(int u, int F) {
	if (head[u] == 0) 
	{
		tott++, dp[u] = 1;
		return ;
	}
	if (w[u] == 1) dp[u] = 1e9;
	for (int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == F) continue;
		dfs(v, u);
		if (w[u] == 0) dp[u] += dp[v];
		else dp[u] = min(dp[u], dp[v]);
	}
}

int main() {
	read(n);
	rep(i, 1, n) read(w[i]);
	rep(i, 2, n) {
		int fa; read(fa);
		add(fa, i);
	}

	dfs(1, 0);
	printf("%d\n", tott + 1 - dp[1]);
	return 0; 
}