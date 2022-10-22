#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100 + 20;

int n, m;
vector<int>	adj[MAXN], sadj[MAXN], jadj[MAXN];
int level[MAXN], q[MAXN];
ld d[MAXN], c[MAXN];
bool vis[MAXN];

void bfs(int r){
	fill(level, level + n, -1);
	level[r] = 0;
	int h = 0, t = 0;
	q[t++] = r;
	while (h < t){
		int v = q[h++];
		for (int u:adj[v]){
			if (level[u] == -1){
				level[u] = level[v] + 1;
				q[t++] = u;
			}
			if (level[u] == level[v] + 1){
				sadj[u].push_back(v);
				sadj[v].push_back(u);
			}
		}
	}
}

void bfs2(int r){
	vis[r] = 1;
	d[r] = 1;
	int h = 0, t = 0;
	q[t++] = r;
	while (h < t){
		int v = q[h++];
		for (int u:sadj[v])
			if (level[u] == level[v] - 1){
				if (!vis[u])	q[t++] = u;
				vis[u] = 1;
				d[u] += d[v];
				jadj[u].push_back(v);
				jadj[v].push_back(u);
			}
	}

	fill(vis, vis + n, 0);
	c[0] = 1;
	vis[0] = 1;
	h = t = 0;
	q[t++] = 0;
	while (h < t){
		int v = q[h++];
		for (int u:jadj[v])
			if (level[u] == level[v] + 1){
				if (!vis[u])	q[t++] = u;
				vis[u] = 1;
				c[u] += c[v];
			}
	}
}

ld get(int v){
	ll sum = 0;
	for (int u:jadj[v])
		if (level[u] != level[v] + 1)
			sum += c[u] * d[v];
		else
			sum += d[u] * c[v];
	return	sum/ d[0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(13);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(0);
	bfs2(n - 1);

	ld ret = 0;
	for (int i = 0; i < n; i++)
		ret = max(ret, get(i));
	cout << ret << endl;
	return 0;
}