#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int c[1000006], a[1000006], flag[1000006];
vector <int> G[1000006];
void dfs(int u){
	if (flag[u])
		return;
	flag[u] = true;
	for (int i = 0; i < G[u].size(); ++ i)
		dfs(G[u][i]);
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
		c[i] = read();
	int ans = 0;
	for (int i = 1; i <= n; ++ i){
		a[i] = read();
		G[i].push_back(a[i]);
		G[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++ i){
		if (flag[i])
			continue;
		dfs(i);
		int p1 = i, p2 = a[i];
		while (p1 != p2){
			p1 = a[p1];
			p2 = a[a[p2]];
		}
		int cnt = 1000000000;
		do{
			cnt = min(cnt, c[p2]);
			flag[p2] = true;
			p2 = a[p2];
		}while (p2 != p1);
		ans += cnt;
	}
	cout << ans << endl;
}