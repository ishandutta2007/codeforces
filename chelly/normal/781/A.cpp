#include<bits/stdc++.h>
using namespace std;
const int N(211111);
vector<int> adj[N];
int stmp[N], color[N], tim, ans;
void dfs(int v, int fa) {
	tim++;
	stmp[color[v]] = tim;
	stmp[color[fa]] = tim;
	int cur(0);
	for(int y : adj[v]) {
		if(y != fa) {
			cur++;
			while(cur == color[v] || cur == color[fa]) {
				cur++;
			}
			color[y] = cur;
			ans = max(ans, cur);
			stmp[cur] = tim;
			dfs(y, v);
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i(0); i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	color[1] = 1;
	ans = 1;
	dfs(1, 0);
	cout << ans << endl;
	for(int i(1); i <= n; i++) 
		printf("%d%c", color[i], i == n ? '\n' : ' ');
}