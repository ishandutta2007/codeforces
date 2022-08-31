#include <bits/stdc++.h>
#define remainder suka
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Edge{int to; int index;};
int n, m;
vector<vector<Edge> > data;
vector<int> remainder;
vector<int> remainder_2;
vector<bool> in_dfs, used;
vector<int> ans, deg;
vector<pair<int, int> > edges;

void dfs1(int vertex, int d){
	used[vertex] = true;
	remainder_2[vertex] = d;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to, I = data[vertex][i].index;
		if (used[to]) continue;
		in_dfs[I] = true;
		dfs1(to, d^1);
	}
}

void add_edge(int index, int num){
	deg[edges[index].first] += num;
	deg[edges[index].second] += num;
	ans[index] += num;
}

void dfs2(int vertex, int go){
	used[vertex] = true;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to, I = data[vertex][i].index;
		if (used[to]) continue;
		dfs2(to, I);
	}
	if (go!=-1){
		int add = (remainder[vertex] - deg[vertex])%3;
		if (add <= 0) add += 3;
		add_edge(go, add);
	}
}

bool check(){
	for (int i=0; i < edges.size(); ++i){
		int u = edges[i].first, v = edges[i].second;
		if (deg[u] == deg[v]) return false;
	}
	return true;
}

void print(){
	for (int i=0;i<m;++i){
		cout << edges[i].first << " " << edges[i].second << " " << ans[i] << "\n";
	}
	exit(0);
}

void solve3(int special){
	for (int it=0;it<3;++it){
		deg.assign(n, 0);
		ans.assign(m, 0);
		add_edge(special, it+1);
		for (int i=0;i<m;++i){
			if (in_dfs[i] || i==special) continue;
			add_edge(i, 1);
		}
		used.assign(n, false);
		dfs2(0, -1);
		if (check()){
			print();
		}
	}
	assert(0);
}

vector<int> dfs_deg;

void dfs3(int vertex){
	used[vertex] = true;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to, I = data[vertex][i].index;
		if (used[to]) continue;
		in_dfs[I] = true;
		dfs3(to);
	}
}

void dfs4(int vertex, int go){
	used[vertex] = true;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to, I = data[vertex][i].index;
		if (used[to]) continue;
		dfs4(to, I);
	}
	if (go!=-1){
		int add = (remainder_2[vertex] - deg[vertex])%2;
		if (add <= 0) add += 2;
		add_edge(go, add);
	}
}

void solve2(){
	dfs_deg.assign(n, 0);
	for (int i=0;i<m;++i){
		if (in_dfs[i]){
			dfs_deg[edges[i].first]++;
			dfs_deg[edges[i].second]++;
		}
	}
	int special = -1;
	for (int i=0;i<n;++i) if (dfs_deg[i] == 1) special = i;
	deg.assign(n, 0);
	ans.assign(m, 0);
	in_dfs.assign(m, false);
	used.assign(n, false);
	dfs3(special);
	for (int i=0;i<m;++i) if (!in_dfs[i]){
		add_edge(i, 1);
	}
	used.assign(n, false);
	if (remainder_2[special] == (data[special].size() % 2)){
		for (int i=0;i<n;++i) remainder_2[i] ^= 1;
	}
	dfs4(special, -1);
	if (check()){
		print();
	}
	vector<int> nei, degs;
	for (int i=0; i < data[special].size(); ++i){
		int to = data[special][i].to, I = data[special][i].index;
		nei.push_back(I);
		degs.push_back(deg[to]-deg[special]);
	}
	int S = degs.size();
	vector<int> app(S, 0);
	for (int i=0; i < S; ++i){
		if (degs[i] >= 0 && degs[i] < 2*S && degs[i] % 2 == 0){
			app[degs[i]/2]++;
		}
	}
	int to_add;
	for (int i=0; i < S; ++i){
		if (app[i] > i) continue;
		if (i > 0 && S-app[i-1] < i) continue;
		to_add = i;
		break;
	}
	int W = to_add;
	for (int i=0; i < S; ++i){
		if (degs[i] == 2*W){
			add_edge(nei[i], 2);
			to_add--;
		}	
	}
	for (int i=0;i<S;++i){
		if (degs[i] == 2*W) continue;
		if (degs[i] == 2*(W-1)) continue;
		if (to_add == 0) continue;
		add_edge(nei[i], 2);
		to_add--;
	}
	print();

}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	data.assign(n, {});
	for (int i=0; i < n; ++i){
		char ch;
		cin >> ch;
		remainder.push_back(ch - 'X');
	}
	for (int i=0;i<m;++i){
		int u, v;
		cin >> u >> v;
		data[u].push_back({v, i});
		data[v].push_back({u, i});
		edges.push_back({u, v});
	}
	in_dfs.assign(m, false);
	ans.assign(m, -1);
	used.assign(n, false);
	remainder_2.assign(n, -1);
	dfs1(0, 0);
	int special = -1;
	for (int i=0;i<m;++i){
		int u = edges[i].first, v = edges[i].second;
		if (remainder_2[u] == remainder_2[v]) special = i;
	}
	if (special != -1) solve3(special);
	solve2();
}