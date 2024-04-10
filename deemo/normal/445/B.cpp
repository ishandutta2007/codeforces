#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 50 + 5;

int n, m, cn;
vector<int>	adj[MAXN];
bool mark[MAXN];
ll ans = 1;

void dfs(int v){
	if (mark[v])	return;
	mark[v] = 1;
	cn++;
	if (cn > 1)	ans *= 2;
	for (int u:adj[v])
		dfs(u);
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i]){
			cn=0;
			dfs(i);
		}
	cout << ans << endl;
	return	0;
}