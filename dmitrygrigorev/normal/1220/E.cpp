#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int ans = 0;

vector<vector<int> > data;
vector<int> w;
vector<int> tin, fup;
int cnt=0;
vector<vector<int> > gr;
vector<bool> used;
set<pair<int, int> > bridges;
void dfs(int vertex, int last){
	tin[vertex] = cnt++;
	fup[vertex] = tin[vertex];
	used[vertex] = true;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (used[to]){
			if (to==last) continue;
			fup[vertex] = min(fup[vertex], tin[to]);
			continue;
		}
		dfs(to, vertex);
		fup[vertex] = min(fup[vertex], fup[to]);
		if (fup[to] > tin[vertex]){
			bridges.insert({vertex, i});
		}
	}
}

int ptr=0;
vector<int> r, where;
void dfs2(int vertex, int cur){
	//cout << vertex << " " << cur << " " << gr.size() << endl;
	if (cur == gr.size()){
		gr.push_back({});
		r.push_back(0);
	}
	r[cur] += w[vertex];
	where[vertex] = cur;
	used[vertex] = true;
	for (int i=0;i<data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (used[to]) continue;
		if (bridges.count({vertex, i})){
			ptr++;
			int tut = ptr;
			dfs2(to, ptr);
			gr[cur].push_back(tut);
			gr[tut].push_back(cur);
		}
		else dfs2(to, cur);
	}
}

vector<int> sz;
vector<bool> is_good;
pair<int, int> dfs3(int vertex, int last){
	if (sz[vertex]!=1) is_good[vertex] = true;
	int res = r[vertex];
	int best = 0;
	bool was = false;
	for (int i=0; i < gr[vertex].size(); ++i){
		int to = gr[vertex][i];
		if (to==last) continue;
		pair<int, int> t = dfs3(to, vertex);
		is_good[vertex] = (is_good[vertex] | is_good[to]);
		//cout << t.first << " " << t.second << endl;
		res += t.first;
		if (t.second-t.first > best) best = t.second-t.first;
	}
	//cout << vertex << " " << res << " " << best << " " << sz[vertex] << endl;
	if (!is_good[vertex]){
		return {0, res+best};
	}
	return {res, res+best};
}

main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	data.assign(n, {});
	w.assign(n, -1);
	for (int i=0;i<n;++i) cin >> w[i];
	for (int i=0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}
	tin.assign(n, -1);
	fup.assign(n, -1);
	used.assign(n, false);
	dfs(0, -1);
	used.assign(n, false);
	where.assign(n, -1);
	dfs2(0, 0);
	int s;
	cin >> s;
	sz.assign(gr.size(), 0);
	for (int i=0;i<n;++i) sz[where[i]]++;
		is_good.assign(n, false);
	ans = dfs3(where[s-1], -1).second;
	cout << ans;
}