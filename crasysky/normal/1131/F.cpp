#include <iostream>
#include <cstdio>
#include <vector>
#define mp make_pair
#define fi first
#define se second
#define maxn 1000006
using namespace std;
int fa[maxn], sze[maxn];
vector <int> G[maxn];
void dfs(int u){
	printf("%d ", u);
	for (int i = 0; i < G[u].size(); ++ i)
		dfs(G[u][i]);
}
int getfa(int u){
	if (fa[u] == u)
		return u;
	return getfa(fa[u]);
}
int read(){
	int cnt = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch)
		ch = getchar();
	while ('0' <= ch && ch <= '9'){
		cnt = cnt * 10 + ch - '0';
		ch = getchar();
	}
	return cnt;
}
int main(){
	int n = read();
	for (int i = 1; i <= n; ++ i)
		fa[i] = i, sze[i] = 1;
	for (int i = 1; i < n; ++ i){
		int x = getfa(read()), y = getfa(read());
		if (sze[x] > sze[y])
			swap(x, y);
		fa[x] = y;
		sze[y] += sze[x];
		G[y].push_back(x);
	}
	dfs(getfa(1));
}