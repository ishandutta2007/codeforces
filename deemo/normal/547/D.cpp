#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<map>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
vector<int>	adj[3 * MAXN], st;
char ans[3 * MAXN];
map<pair<int, int>, int>	pos;
set<pair<int, int>>	sn;
bool vis[3 * MAXN];

void dfs(int v){
	vis[v] = 1;
	while (adj[v].size()){
		int u = adj[v].back();	adj[v].pop_back();
		if (sn.count({u, v}))	continue;
		sn.insert({u, v}),	sn.insert({v, u});
		dfs(u);
	}
	st.push_back(v);
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b;	a <<= 1, b = b<<1^1;
		adj[a].push_back(b);
		adj[b].push_back(a);
		pos[{a, b}] = i;
	}

	for (int i = 1; i < MAXN; i++)
		if ((int)adj[i<<1].size() % 2 == 1)
			adj[MAXN<<1^1].push_back(i<<1), adj[i<<1].push_back(MAXN<<1^1);
	for (int i = 1; i < MAXN; i++)
		if ((int)adj[i<<1^1].size() % 2 == 1)
			adj[MAXN<<1].push_back(i<<1^1), adj[i<<1^1].push_back(MAXN<<1);

	for (int i = MAXN; i; i--){
		if (adj[i<<1].size() && !vis[i<<1])	dfs(i<<1);
		if (adj[i<<1^1].size() && !vis[i<<1^1]) dfs(i<<1^1);
	}
	bool x = 0;
	for (int i = 0; i < (int)st.size() - 1; i++){
		int u = st[i], v = st[i + 1];
		if (u & 1)	swap(u, v);
		if (pos.count({u, v}))
			ans[pos[{u, v}]] = x == 0?'b':'r', x ^= 1;
	}

	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << "\n";
	return	0;
}