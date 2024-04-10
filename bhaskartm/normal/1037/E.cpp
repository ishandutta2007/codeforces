 
#include <bits/stdc++.h>
 
using namespace std;
 
const int maxx = 2e5 + 7;
bool mark[maxx];
int n , m , k , cnt , d[maxx] , u[maxx] , v[maxx] , ans[maxx];
set <int> adj[maxx];
 
void DFS(int v)
{
	if((int)adj[v].size() < k && !mark[v])
	{
		cnt--;
		mark[v] = true;
		for(auto u : adj[v])
			adj[u].erase(v) , DFS(u);
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++)
	{
		cin >> u[i] >> v[i];
		u[i]--;		v[i]--;
		adj[u[i]].insert(v[i]);	adj[v[i]].insert(u[i]);
	}
	cnt = n;
	for(int i = 0 ; i < n ; i++)
		DFS(i);
	ans[m - 1] = cnt;
	
	for(int i = m - 1 ; i >= 1 ; i--)
	{
		adj[u[i]].erase(v[i]);		adj[v[i]].erase(u[i]);
		DFS(u[i]);					DFS(v[i]);	
		ans[i - 1] = cnt;
	}	
	for(int i = 0 ; i < m ; i++)
		cout << ans[i] << "\n";	
}