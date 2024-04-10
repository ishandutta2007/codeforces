#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5;

int n, m;
bool mark[MAXN];
vector<int>	adj[MAXN];

void dfs(int v){
	if (mark[v])	return;
	mark[v] = 1;

	for (int u:adj[v])
		dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		cnt += t;
		while (t--){
			int x;	cin >> x;	x--;
			adj[x].push_back(i + m);
			adj[i + m].push_back(x);
		}
	}

	int ans = 0;
	for (int i = m; i < m + n; i++)
		if (!mark[i]){
			dfs(i);
			ans++;
		}
	if (cnt)	ans--;
	cout << ans << endl;
	return 0;
}