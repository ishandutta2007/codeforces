#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;

int n, m, col[MAXN], mark[MAXN], z, g, vis[MAXN], seen[MAXN];
vector<int>	adj[MAXN], sec[MAXN];

void get(int v, int c){
	if (vis[v] == g)
		return;
	vis[v] = g;
	if (col[v] != c){
		if (seen[col[v]] != g)	z++;
		seen[col[v]] = g;
		return;
	}

	for (int u:adj[v])
		get(u, c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> col[i];
		sec[col[i]].push_back(i);
	}
	while(m--){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	g++;

	int maxi = -1, ind = -1;
	for (int i = 0; i < n; i++)
		if (!mark[col[i]]){
			mark[col[i]] = 1;
			g++, z = 0;
			for (int u:sec[col[i]])
				get(u, col[i]);
			if (z > maxi || (z == maxi && ind > col[i])){
				maxi = z;
				ind = col[i];
			}
		}
	cout << ind << endl;
	return 0;
}