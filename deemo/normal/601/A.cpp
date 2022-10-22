#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int max_n = 400 + 20;
const int MAX = 1e3;

int n, m;
bool adj[max_n][max_n];
int q[MAX], d[max_n];
bool mark[max_n];

void bfs(int v, bool type){
	int h = 0, t = 0;
	q[t++] = v;
	mark[v] = 1;
	d[v] = 0;
	while (h < t){
		int u = q[h++];
		for (int i = 0; i < n; i++){
			if (mark[i])	continue;
			if (adj[u][i] != type)	continue;
			q[t++] = i, mark[i] = 1, d[i] = d[u] + 1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a][b] = adj[b][a] = 1;
	}
	
	bool t = 1;
	if (adj[0][n - 1] == 1)	t = 0;
	fill(d, d + n, -1);
	bfs(0, t);
	cout << d[n - 1] << endl;
	return 0;
}