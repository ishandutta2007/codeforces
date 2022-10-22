#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 5e3 + 10;
const int INF = 1e7 + 2;

int n, rt, c[2][MAXN][MAXN], d[2][MAXN][MAXN];
vector<int>	adj[MAXN];

int solve(int v, int p = -1){
	if (adj[v].size() == 1){
		d[0][v][0] = d[1][v][1] = 0;
		return 1;
	}

	int z = 0, lu = -1;
	d[0][v][0] = d[1][v][0] = 0;
	for (int u:adj[v])
		if (u != p){
			int t = solve(u, v);
			for (int i = 0; i <= z + t; i++)
				c[0][v][i] = c[1][v][i] = INF;
			for (int i = 0; i <= z; i++)
				for (int j = 0; j <= t; j++){
					c[0][v][i + j] = min(c[0][v][i + j], min(d[0][v][i] + d[0][u][j], d[0][v][i] + d[1][u][j] + 1));
					c[1][v][i + j] = min(c[1][v][i + j], min(d[1][v][i] + d[1][u][j], d[1][v][i] + d[0][u][j] + 1));
				}
			z += t;
			for (int i = 0; i <= z; i++)
				d[0][v][i] = c[0][v][i], d[1][v][i] = c[1][v][i];
		}
	return	z;
}

int main(){
	cin >> n;
	if (n == 2){
		cout << 1 << "\n";
		return	0;
	}
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (adj[a].size() > 1)	rt = a;
		if (adj[b].size() > 1)	rt = b;
	}
	memset(d, 60, sizeof(d));
	int z = solve(rt);
	cout << min(d[0][rt][z/2], d[1][rt][z/ 2]) << "\n";
	return	0;	
}