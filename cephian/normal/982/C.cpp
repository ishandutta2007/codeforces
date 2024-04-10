#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;	
vector<int> G[N];
vector<int> children[N];
// above total vert 
vector<int> solve[2][2][N];

int dfs(int v, int p) {
	for(int u : G[v]) {
		if(u == p)
			continue;
		children[v].push_back(u);
		//cout << v << " >> " << u << endl;
		dfs(u,v);
	}
	const int BAD = -1000000;
	int n = children[v].size();
	for(int a = 0; a < 2; ++a)
		for(int t = 0; t < 2; ++t) {
			solve[a][t][v] = vector<int>(n+1);
			if(a == t)
				solve[a][t][v][0] = BAD;
			else
				solve[a][t][v][0] = 0;
			//printf("%d %d %d %d --> %d\n",a,t,v,0,solve[a][t][v][0]);
		}
	for(int i = 1; i <= n; ++i) {
		int u = children[v][i-1];
		int m = children[u].size();
		for(int a = 0; a < 2; ++a) {
			for(int t = 0; t < 2; ++t) {
				// case: without
				solve[a][t][v][i] = BAD;
				solve[a][t][v][i] = max(solve[a][t][v][i], 1 + solve[a][t][v][i-1] + solve[0][0][u][m]);
				//case: with prev evn
				solve[a][t][v][i] = max(solve[a][t][v][i], solve[a][0][v][i-1] + solve[0][t][u][m]);
				//case: with prev odd
				solve[a][t][v][i] = max(solve[a][t][v][i], solve[a][1][v][i-1] + solve[1][t][u][m]);
				//printf("%d %d %d %d --> %d\n",a,t,v,i,solve[a][t][v][i]);
			}
		}
	}
	return solve[0][0][v][children[v].size()];
}

int main() {
	int n;
	cin >> n;
	if(n&1) {
		cout << "-1\n";
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		int a,b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << dfs(1,-1) << "\n";

}