#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>
#include<deque>
#include<cstring>

using namespace std;

const int max_n = 1e5 + 30;

int n, m;
bool mat[10][10], mark[max_n];
vector<int>	adj[max_n];
int cnt[10];
vector<pair<int, int>>	sec;

void gen(){
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (!mat[i][j])	sec.push_back({i, j});
}

int q[max_n];
deque<int>	saf;

void bfs(int v){
	int h = 0, t = 0;
	mark[v] = 1;
	q[t++] = v;
	while (h < t){
		int u = q[h++];
		for (int z:adj[u])
			if (!mark[z])
				q[t++] = z, mark[z] = 1;
		saf.push_back(u);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		if (n < 9)	mat[a][b] = mat[b][a] = 1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	if (n < 9){
		gen();
		int ans = -1;
		for (int i = 0; i < (1 << (int)sec.size()); i++){
			if (__builtin_popcount(i) != m)	continue;
			memset(cnt, 0, sizeof(cnt));
			bool fl = 0;
			for (int j = 0; j < sec.size(); j++)
				if ((i >> j) & 1){
					cnt[sec[j].first]++;
					cnt[sec[j].second]++;
					if (cnt[sec[j].first] > 2 || cnt[sec[j].second] > 2){
						fl = 1;
						break;
					}
				}
			if (!fl){
				ans = i;
				break;
			}
		}
		if (ans == -1)
			printf("-1\n");
		else{
			for (int i = 0; i < sec.size(); i++)
				if ((ans >> i) & 1)	
					printf("%d %d\n", sec[i].first + 1, sec[i].second + 1);
		}
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			bfs(i);

	for (int i = 0; i < n && m; i++){
		m--;
		if (i + 3 < n)
			printf("%d %d\n", saf[i] + 1, saf[i + 3] + 1);
		else
			printf("%d %d\n", saf[i] + 1, saf[i % 3] + 1);
	}
	return 0;
}