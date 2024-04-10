#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
vector<vector<int> > data;
 
const int TRY = 228;
 
bool suit;
vector<bool> father;
vector<bool> used;
vector<int> d;
 
void check_dfs(int vertex) {
 
	father[vertex] = true;
	used[vertex] = true;
 
	for (auto to : data[vertex]) {
 
		if (father[to]) continue;
		if (!used[to]) {
			check_dfs(to);
			continue;
		}
 
		suit = false;
	}
 
	father[vertex] = false;
 
 
 
}
 
set<pair<int, int> > ded;
 
void dfs2(int vertex, int cd) {
 
	father[vertex] = true;
	used[vertex] = true;
	d[vertex] = cd;
 
	for (auto to : data[vertex]) {
 
		if (father[to]) continue;
		if (!used[to]) {
			ded.insert(mp(vertex, to));
			dfs2(to, cd+1);
			continue;
		}
	}
 
	father[vertex] = false;
 
 
 
}
 
std::mt19937 gen; 
 
vector<int> high2, high;
 
bool cmp(int a, int b) {
	return (d[a] < d[b]);
}
 
vector<bool> isin;
 
void do_best(int vertex, int y) {
	if (cmp(y, high[vertex])) {
		high2[vertex] = high[vertex];
		high[vertex] = y;
	}
	else if (cmp(y, high2[vertex])) high2[vertex] = y;
}
 
void dfs3(int vertex) {
 
	high2[vertex] = vertex;
	high[vertex] = vertex;
 
	for (auto to: data[vertex]) {
		if (ded.count(mp(vertex, to))) {
			dfs3(to);
 
			do_best(vertex, high[to]);
			do_best(vertex, high2[to]);
		}
		else {
			do_best(vertex, to);
		}
	}
 
}
 
void dfs4(int vertex) {
 
	if (d[high2[vertex]] < d[vertex]) isin[vertex] = false;
	else if (high[vertex] == vertex) isin[vertex] = true;
 
	else {
 
		int T = high[vertex];
		isin[vertex] = isin[T];
 
	}
 
	for (auto to : data[vertex]) {
		if (ded.count(mp(vertex, to))) dfs4(to);
	}
 
}
 
void solve() {
 
	int n, m;
	cin >> n >> m;
 
	data.assign(n, {});
	father.assign(n, false);
 
	high2.assign(n, 0);
	high.assign(n, -1);
	d.assign(n, 0);
 
	vector<pair<int, int> > edges;
 
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		edges.push_back(mp(u, v));
 
		data[u].push_back(v);
	}
 
	int ft = -1;
	for (int i = 0; i < TRY; ++i) {
 
		suit = true;
		used.assign(n, false);
 
		int x = gen() % n;
 
		check_dfs(x);
		if (suit) {
			ft = x;
			break;
		}
 
	}
 
	if (ft == -1) {
		cout << "-1\n";
		return;
	}
 
	ded.clear();
	used.assign(n, false);
	dfs2(ft, 0);
 
	dfs3(ft);
 
	isin.assign(n, false);
	isin[ft] = true;
 
	dfs4(ft);
 
	int g = 0;
	for (int i = 0; i < n; ++i) if (isin[i]) g++;
	if (5*g < n) cout << "-1\n";
 
	else {
		vector<int> tg;
		for (int i = 0; i < n; ++i) if (isin[i]) tg.push_back(i);
 
		sort(all(tg));
 
		for (int i = 0; i < tg.size(); ++i) cout << tg[i]+1 << " ";
		cout << "\n";
	}
 
 
 
 
 
 
 
}
 
int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
    gen.seed(228);
 
	int t;
	cin >> t;
 
	for (int i = 0; i < t; ++i) solve();
 
}