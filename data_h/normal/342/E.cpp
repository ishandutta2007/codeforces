#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111, M = N * 2;
const int inf = 11111111;

vector<pair<int, int> > father[N];
int color[N]; // 0 black  1 white
priority_queue<pair<int, int> > heap[N];
int n, visit[N], fa[N];
vector<int> e[N], vec;
int q[N], size[N], dis[N];

int findRoot(int s) {
	vec.clear();
	int head = 1, tail = 1;
	q[tail] = s;
	fa[s] = 0;
	while(head <= tail) {
		int x = q[head++];
		for(int i = 0; i < e[x].size(); i++) {
			int y = e[x][i];
			if (y == fa[x] || visit[y])
				continue;
			q[++tail] = y;
			fa[y] = x; 
		}
	}
	vec.clear();
	for(int i = 1; i <= tail; i++) {
		int x = q[i];
		size[x] = 0;
		vec.push_back(x);
	}
	int maxSize = inf, choose = 0;
	for(int i = tail; i >= 1; i--) {
		int x = q[i];
		size[x]++;
		size[fa[x]] += size[x];
		int tmp = tail - size[x];
		for(int j = 0; j < e[x].size(); j++) {
			int y = e[x][j];
			if (visit[y] || y == fa[x])
				continue;
			tmp = max(tmp, size[y]);
		}
		if (tmp < maxSize) {
			maxSize = tmp;
			choose = x;
		}
	}
	dis[choose] = 0;
	head = 1, tail = 1;
	fa[choose] = 0;
	q[tail] = choose;
	while(head <= tail) {
		int x = q[head++];
		for(int i = 0; i < e[x].size(); i++) {
			int y = e[x][i];
			if (y == fa[x] || visit[y])
				continue;
			q[++tail] = y;
			fa[y] = x; 
			dis[y] = dis[x] + 1;
		}
	}
	//printf("size = %d\n", tail);
	return choose;
}

void dfs(int x) {
	x = findRoot(x);
	//printf("root %d\n", x);
	for(int i = 0; i < vec.size(); i++) {
		father[vec[i]].push_back(make_pair(dis[vec[i]], x));
		if (color[vec[i]] == 1)
			heap[x].push(make_pair(-dis[vec[i]], vec[i]));
	}
	visit[x] = 1;
	for(int i = 0; i < e[x].size(); i++)
		if (!visit[e[x][i]])
			dfs(e[x][i]);
}

int getV(int x) {
	while(!heap[x].empty() && color[heap[x].top().second] == 0)
		heap[x].pop();
	if (heap[x].size() == 0)
		return inf;
	return -heap[x].top().first;
}

int main() {
	scanf("%d", &n);
	int query;
	scanf("%d", &query);
	for(int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}	
	color[1] = 1;
	dfs(1);
	for(int i = 1; i <= query; i++) {
		int type, v;
		scanf("%d %d", &type, &v);
		if (type == 2) {
			int ans = inf;
			for(int j = 0; j < father[v].size(); j++) {
				int tmp = getV(father[v][j].second);
				ans = min(ans, tmp + father[v][j].first);
			}
			if (ans > inf / 2) {
				printf("-1\n");
			} else {
				printf("%d\n", ans);
			}
		} else {
			if (color[v] == 0) {
				for(int j = 0; j < father[v].size(); j++) {
					int x = father[v][j].second;
					int ds = father[v][j].first;
					heap[x].push(make_pair(-father[v][j].first, v));
				}
			}
			color[v] ^= 1;
		}
	}
	return 0;
}