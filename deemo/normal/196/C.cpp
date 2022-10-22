#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

#define F first.first
#define S first.second
#define ID second
#define Point pair<pair<int, int>, int>

const int MAXN = 1500 + 10;

int n, sz[MAXN], ans[MAXN];
vector<int>	adj[MAXN];
Point g;

bool cmp(Point a, Point b){return a.F < b.F;}
bool cmp2(Point a, Point b){return ll(a.F - g.F) * (b.S - g.S) - ll(a.S - g.S) * (b.F - g.F) < 0;}

void dfs(int v, int p = -1){
	sz[v] = 1;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v), sz[v] += sz[u];
}

vector<Point>	gec;
void solve(int v, vector<Point> vec, int p = -1){
	ans[vec[0].ID] = v;
	g = vec[0];
	sort(vec.begin() + 1, vec.end(), cmp2);

	int l = 1;
	for (int u:adj[v])
		if (u^p){
			gec.assign(vec.begin() + l, vec.begin() + l + sz[u]);
			solve(u, gec, v);
			l += sz[u];
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int u, v;	cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);

	vector<Point>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i].F >> vec[i].S, vec[i].ID = i;
	sort(vec.begin(), vec.end(), cmp);
	solve(0, vec);
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}