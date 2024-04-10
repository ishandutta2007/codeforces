#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2222;

int dist[N][N], n;
int father[N];
vector<pair<int, pair<int, int> > > edges;
vector<pair<int, int> > e[N];
bool flag = true;

void dfs(int x, int fa, int from, int ds) {
	if (!flag || ds != dist[from][x]) {
		flag = false;
		return;
	}
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		if (y != fa) {
			dfs(y, x, from, ds + e[x][i].second);
		}
	}
}

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			scanf("%d", &dist[i][j]);
			if (i != j) {
				edges.push_back(make_pair(dist[i][j], make_pair(i, j)));
			}
			if (i != j && dist[i][j] == 0) {
				puts("NO");
				return 0;
			}
		}	
	for(int i = 1; i <= n; i++) {
		father[i] = i;
	}
	sort(edges.begin(), edges.end());
	int cnt = 0;
	for(int i = 0; i < (int)edges.size(); i++) {
		int x = edges[i].second.first;
		int y = edges[i].second.second;
		if (find(x) != find(y)) {
			e[x].push_back(make_pair(y, edges[i].first));
			e[y].push_back(make_pair(x, edges[i].first));
			father[find(x)] = find(y);
			cnt++;
		}
	}
	for(int i = 1; i <= n; i++) {
		dfs(i, -1, i, 0);
	}
	if (flag) {
		puts("YES");
	} else {
		puts("NO");
	}
	return 0;
}