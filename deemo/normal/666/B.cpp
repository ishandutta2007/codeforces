#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 3e3 + 10;
const int INF = 1e8;

int n, m, d[MAXN][MAXN], q[MAXN];
vector<pair<int, int>>	vec[MAXN], sec[MAXN];
vector<int>	ans;
vector<int>	adj[MAXN];

void bfs(int rt){
	int h = 0, t = 0;
	d[rt][rt] = 0;
	q[t++] = rt;
	while (h < t){
		int v = q[h++];
		for (int u:adj[v])
			if (d[rt][u] > d[rt][v] + 1){
				d[rt][u] = d[rt][v] + 1;
				q[t++] = u;
			}
	}
	for (int j = 0; j < n; j++)
		if (d[rt][j] == INF)	d[rt][j] = -INF;
}

int main(){
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			d[i][j] = INF;
	scanf("%d %d", &n, &m);
	while (m--){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		adj[a].push_back(b);
	}
	for (int i = 0; i < n; i++){
		bfs(i);
		vec[i].resize(n - 1);
		int cc = 0;
		for (int j = 0; j < n; j++)
			if (i^j)	vec[i][cc++] = {d[i][j], j};
		sort(vec[i].begin(), vec[i].end());
		reverse(vec[i].begin(), vec[i].end());
	}
	for (int i = 0; i < n; i++){
		sec[i].resize(n - 1);
		int cc = 0;
		for (int j = 0; j < n; j++)
			if (i^j)	sec[i][cc++] = {d[j][i], j};
		sort(sec[i].begin(), sec[i].end());
		reverse(sec[i].begin(), sec[i].end());
	}

	ans.resize(4);
	int maxi = -1e8;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i^j){
				int ret = d[i][j], z = -1, y = -1;
				for (int w = 0; w < n-1; w++)
					if (sec[i][w].second ^ j){
						ret += sec[i][w].first;
						z = sec[i][w].second;
						break;
					}

				for (int w = 0; w < n-1; w++)
					if (vec[j][w].second != i && vec[j][w].second != z){
						ret += vec[j][w].first;
						y = vec[j][w].second;
						break;
					}
				if (maxi < ret){
					ans[0] = z;
					ans[1] = i;
					ans[2] = j;
					ans[3] = y;
					maxi = ret;
				}

				ret = d[i][j], z = -1, y = -1;
				
				for (int w = 0; w < n-1; w++)
					if (vec[j][w].second != i){
						ret += vec[j][w].first;
						y = vec[j][w].second;
						break;
					}

				for (int w = 0; w < n-1; w++)
					if (sec[i][w].second ^ j && sec[i][w].second != y){
						ret += sec[i][w].first;
						z = sec[i][w].second;
						break;
					}

				if (maxi < ret){
					ans[0] = z;
					ans[1] = i;
					ans[2] = j;
					ans[3] = y;
					maxi = ret;
				}
			}
	
	for (int u:ans)
		printf("%d ", u + 1);
	printf("\n");
	return 0;
}