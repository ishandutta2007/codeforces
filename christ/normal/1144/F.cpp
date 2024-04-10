#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+7, LOG = 15;
#define all(x) (x).begin(),(x).end()
vector<int> adj[MN];
vector<pii> edges;
int color[MN];
void dfs (int cur) {
	for (int i : adj[cur]) {
		if (color[i] == color[cur]) {printf ("nO\n"); exit(0);}
		else if (!color[i]) color[i] = 3 - color[cur], dfs(i);
	}
}
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	while (m--) {
		int a,b;
		scanf ("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		edges.emplace_back(a,b);
	}
	color[1] = 1;
	dfs(1);
	printf ("YES\n");
	for (pii &p : edges) putchar('0'+color[p.first]-1);
	putchar(10);
    return 0;
}