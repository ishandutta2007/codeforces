#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<cassert>

using namespace std;

const int MAXN = 80 + 3;
const int MAX = 5e6;

int n, m, c[MAXN][MAXN], hs[MAXN][MAXN], cst;
int head[MAX], from[MAX], to[MAX], cap[MAX], cost[MAX], prv[MAX], ec;
bool mark[MAX];
int d[MAX], par[MAX], q[MAX];

bool fit(int a, int b){return a >= 0 && a < n && b >= 0 && b < m;}

void add_edge(int u, int v, int uv, int cc){
	from[ec] = u, to[ec] = v, cap[ec] = uv, cost[ec] = cc, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = 0, cost[ec] = 0, prv[ec] = head[v];	head[v] = ec++;
}

void max_flow(int source, int sink){
	int x;
	for (int i = 0; i < n * m/2; i++){
		memset(mark, 0, sizeof(mark));
		memset(par, -1, sizeof(par));
		memset(d, 63, sizeof(d));

		d[source] = 0, mark[source] = 1;
		int h = 0, t = 0;	q[t++] = source;

		while (h < t){
			int v = q[h++];	mark[v] = 0;
			for (int e = head[v]; e != -1; e = prv[e])
				if (cap[e] && cost[e] + d[v] < d[to[e]]){
					d[to[e]] = d[v] + cost[e];	
					par[to[e]] = e;
					if (!mark[to[e]])
						mark[to[e]] = 1, q[t++] = to[e];
				}
		}

		assert(d[sink] < MAX);
		int v = sink;
		while (par[v] != -1){
			int e = par[v];
			cap[e] = 0;
			cap[e^1] = 1;
			cost[e^1] -= cost[e];
			cst += cost[e];
			cost[e] = 0;
			v = from[e];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			hs[i][j] = i * m + j;
		}

	memset(head, -1, sizeof(head));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if ((i + j) % 2 == 0){
				add_edge(n*m, hs[i][j], 1, 0);
				for (int a = -1; a < 2; a++)
					for (int b = -1; b < 2; b++)
						if (fit(i + a, j + b) && abs(a) + abs(b) == 1){
							if (c[i + a][j + b] == c[i][j])
								add_edge(hs[i][j], hs[i + a][j + b], 1, 0);
							else
								add_edge(hs[i][j], hs[i + a][j + b], 1, 1);
						}
			}
			else add_edge(hs[i][j], n*m+1, 1, 0);
	max_flow(n*m, n*m + 1);
	cout << cst << "\n";
	return	0;
}