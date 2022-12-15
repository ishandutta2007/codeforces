#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
bool isfib[200005];
int pre1[200005], pre2[200005];
vector<int> G[200005];
vector<bool> used[200005];

int siz[200005], fa[200005];
vector<int> lis;
void get(int x, int f) {
	lis.push_back(x); fa[x] = f;
	siz[x] = 1;
	for (int i = 0; i < G[x].size(); i++) if (G[x][i] != f && !used[x][i])
	 	get(G[x][i], x), siz[x] += siz[G[x][i]];
}
bool solve(int rt) {
	lis.clear();
	get(rt, rt);
	if (siz[rt] == 1 || siz[rt] == 2) return 1;
	int x = -1;
	for (int i : lis) if (siz[i] == pre1[siz[rt]] || siz[i] == pre2[siz[rt]])
		{ x = i; break; }
	lis.clear();
	if (x == -1) return 0;
	for (int i = 0; i < G[fa[x]].size(); i++) if (G[fa[x]][i] == x) used[fa[x]][i] = 1;
	for (int i = 0; i < G[x].size(); i++) if (G[x][i] == fa[x]) used[x][i] = 1;
	return solve(rt) && solve(x);
}

int main() {
	srand(time(NULL));
	scanf("%d", &n);
	int f1 = 0, f2 = 1;
	while (f2 <= 200000) {
		isfib[f2] = 1;
		pre1[f2] = f2 - f1, pre2[f2] = f1;
		f1 += f2; swap(f1, f2);
//		printf("pre %d = %d %d\n");
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v); G[v].push_back(u);
		used[u].push_back(0);
		used[v].push_back(0);
	}
	if (isfib[n] && solve(1)) printf("YES\n"); else printf("NO\n");
}