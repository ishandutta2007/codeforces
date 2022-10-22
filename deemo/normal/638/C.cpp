#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 2e5 + 10;

int n, from[2 * MAXN], to[2 * MAXN], prv[2 * MAXN], head[MAXN], ec, col[2 * MAXN], cn[MAXN];
vector<int>	ans[MAXN];

void add_edge(int u, int v){
	cn[u]++, cn[v]++;
	from[ec] = u, to[ec] = v, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, prv[ec] = head[v], head[v] = ec++;
}

void solve(int v, int p = -1, int z = -1){
	int cur = !z;
	for (int e = head[v]; ~e; e = prv[e]){
		if (to[e] == p)	continue;
		col[e] = col[e^1] = cur;
		solve(to[e], v, cur);
		cur++;
		if (cur == z)	cur++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(col, -1, sizeof(col));
	memset(head, -1, sizeof(head));
	int sz = 0;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		add_edge(a, b);
		sz = max({sz, cn[a], cn[b]});
	}	
	solve(0);
	cout << sz << "\n";
	for (int e = 0; e < ec; e += 2)
		ans[col[e]].push_back(e/2 + 1);
	for (int i = 0; i < sz; i++){
		cout << ans[i].size() << " ";
		for (auto u:ans[i])
			cout << u << " ";
		cout << "\n";
	}
	return	0;
}