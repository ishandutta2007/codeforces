#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MX = 1e3 + 10;

int n, ans, cnt;
bool vis[4 * MX];
vector<int>	adj[3 * MX];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	cnt++;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	cin >> n;
	while (n--){
		int a, b;	cin >> a >> b, a--, b--;	b += MX;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < MX; i++){
		cnt = 0;
		dfs(i);
		if (cnt > 1)
			ans++;
	}
	cout << ans - 1 << endl;
	return 0;
}