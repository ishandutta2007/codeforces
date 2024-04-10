#include <bits/stdc++.h>
#define data cock
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
const int N = 100007;
vector<int> data[N];
int n;
bool path1[N], path2[N];


bool dfs1(int vertex, int last, int target){
	if (vertex == target){
		path1[vertex] = true;
		return true;
	}
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		bool res = dfs1(to, vertex, target);
		if (res){
			path1[vertex] = true;
			return true;
		}
	}
	return false;
}

bool dfs2(int vertex, int last, int target){
	if (vertex == target){
		path2[vertex] = true;
		return true;
	}
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		bool res = dfs2(to, vertex, target);
		if (res){
			path2[vertex] = true;
			return true;
		}
	}
	return false;
}

vector<int> tpath;

void dfs3(int vertex, int last, vector<int> &path){
	path.push_back(vertex);
	if (path2[vertex]){
		tpath = path;
		path.pop_back();
		return;
	}
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs3(to, vertex, path);
	}
	path.pop_back();
}

vector<int> p1, p2;
int len;

void dfs4(int vertex, int last, int target, vector<int> &path){
	path.push_back(vertex);
	if (vertex == target){
		p1 = path;
		path.pop_back();
		return;
	}
	for (int i=0; i < data[vertex].size() ;++i){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs4(to, vertex, target, path);
	}
	path.pop_back();
}

vector<vector<pair<int, int> > > gr;

bool good;

vector<int> relax, d, father;
const int INF = 1e9;

void dfs5(int vertex, int last, int d, int kek){
	father[vertex] = last;
	if (kek==0){
		int l2 = max(0, len-d);
		if (l2 < p2.size()){
			gr[vertex].push_back({p2[l2], 0});
		}
	}
	else{
		int l2 = max(0, len-d);
		if (l2 < p1.size()){
			gr[vertex].push_back({p1[l2], 0});
		}
	}
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to == last) continue;
		gr[vertex].push_back({to, 1});
		dfs5(to, vertex, d+1, kek);
	}
}

vector<int> ret2;
void dfs6(int vertex, int last, int tar, vector<int> &path){
	path.push_back(vertex);
	if (vertex == tar){
		ret2 = path;
		path.pop_back();
		return;
	}
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs6(to, vertex, tar, path);
	}
	path.pop_back();
}

pair<vector<int>, vector<int> > bfs(int start, int second, int finish, bool reversed){
	relax.assign(n, -1);
	d.assign(n, INF);
	d[start] = 0;
	relax[start] = -1;

	deque<int> deq;

	deq.push_back(start);

	while (deq.size()){
		int W = deq.front();
		deq.pop_front();
		for (int i=0; i < gr[W].size(); ++i){
			int to = gr[W][i].first, dist = d[W] + gr[W][i].second;
			if (dist >= d[to]) continue;
			relax[to] = W;
			d[to] = dist;
			if (gr[W][i].second == 1) deq.push_back(to);
			else deq.push_front(to);
		}
	}

	if (d[finish] == INF){
		good = false;
		return {{}, {}};
	}

	good = true;

	int a = start, b = second;

	vector<int> opath;

	int now = finish;

	while (now != start){
		opath.push_back(now);
		now = relax[now];
	}

	opath.push_back(start);

	reverse(opath.begin(), opath.end());

	vector<int> ret1;

	for (int i=1; i < opath.size(); ++i){
		int N = opath[i];
		if (N==a || N==b) continue;
		else if (father[N] == a){
			if (reversed) ret1.push_back(b);
			else ret1.push_back(N);
			a = N, b = father[b];
		}
		else{
			if (reversed) ret1.push_back(a);
			else ret1.push_back(N);
			b = N, a = father[a];
		}
	}

	if (a!=finish) swap(a, b);
	vector<int> tet;
	dfs6(a, -1, b, tet);
	if (reversed) reverse(ret1.begin(), ret1.end());
	return {ret1, ret2};

}

pair<vector<int>, vector<int> > solve(int root, int x, int y, bool reversed){
	vector<int> cur;
	dfs4(root, -1, y, cur);
	p2 = p1;
	dfs4(root, -1, x, cur);
	if (x==root){
		good = true;
		return {{}, p2};
	}
	if (y==root){
		good = true;
		return {{}, p1};
	}
	len = p1.size() + p2.size() - 2;
	gr.assign(n, {});
	father.assign(n, {});

	dfs5(p1[1], root, 1, 0);
	dfs5(p2[1], root, 1, 1);
	/*

	for (int i=0; i < p1.size(); ++i) cout << p1[i]<< " ";
	cout << endl;

	for (int i=0; i < p2.size(); ++i) cout << p2[i]<< " ";
	cout << endl;

	exit(0);
	 */


	pair<vector<int>, vector<int> > tet = bfs(x, y, root, reversed);
	if (good){
		return tet;
	}


	tet = bfs(y, x, root, reversed);
	if (good){
		return tet;
	}

	return {{}, {}};

}

bool solve(int n, vector<pair<int, int> > edges, int a, int b, int c, int d){
	for (int i=0; i < n; ++i){
		data[i] = {};
		path1[i] = false;
		path2[i] = false;
	}
	for (int i=0; i < n-1; ++i){
		int u = edges[i].first, v = edges[i].second;
		data[u].push_back(v), data[v].push_back(u);
	}

	dfs1(a, -1, b);
	dfs2(c, -1, d);
	vector<int> cur;
	dfs3(a, -1, cur);
	int start = 0;

	for (int i=0; i < tpath.size(); ++i){
		if (!path1[tpath[i+1]]){
			start = i;
			break;
		}
	}

	for (int i=start; i < tpath.size(); ++i){
		cur.push_back(tpath[i]);
	}

	tpath = cur;


	int W = tpath[0];

	for (int i=0; i < data[W].size(); ++i){
		if (data[W][i] == tpath[1]) swap(data[W][i], data[W].back());
	}
	data[W].pop_back();
	pair<vector<int>, vector<int> > resa = solve(W, a, b, false);
	if (!good) return false;
	return true;

}

vector<vector<int> > GR;
vector<int> LEN;
vector<bool> is_good;
vector<bool> is_path;

vector<int> particular;

bool dfs7(int vertex, int last, int target) {

	bool res = false;
	if (vertex == target) res = true;

	LEN[vertex] = 1;
	for (auto to : GR[vertex]) {
		if (to == last) continue;
		bool kek = dfs7(to, vertex, target);
		if (kek) res = true;
		LEN[vertex] = max(LEN[vertex], LEN[to] + 1);
	}

	is_path[vertex] = res;
	if (res) particular.pb(vertex);
	return res;

}

void trelax(int &mx1, int &mx2, int &mx3, int val) {
	if (val > mx1) {
		mx3 = mx2;
		mx2 = mx1;
		mx1 = val;
	}
	else if (val > mx2) {
		mx3 = mx2;
		mx2 = val;
	}
	else if (val > mx3) mx3 = val;
}

void dfs8(int vertex, int last, int third) {

	int mx1 = -1, mx2 = -1, mx3 = -1;
	for (auto to : GR[vertex]) {
		if (to==last) continue;
		int val = LEN[to] + 1;
		trelax(mx1, mx2, mx3, val);
	}

	trelax(mx1, mx2, mx3, third);
	is_good[vertex] = (mx3 >= (int) (particular.size()));

	for (auto to : GR[vertex]) {
		if (to==last) continue;
		if (LEN[to] + 1 != mx1) dfs8(to, vertex, mx1 + 1);
		else dfs8(to, vertex, mx2+1);
	}

}

bool dfs9(int vertex, int last) {
	if (is_good[vertex]) return true;
	for (auto to : GR[vertex]) {
		if (is_path[to]) continue;
		if (to==last) continue;
		if (dfs9(to, vertex)) return true;
	}

	return false;
}

int special;
int kekos;

int dfs10(int vertex, int last, int d) {
	if (d==particular.size()) return vertex;

	for (auto to : GR[vertex]) {
		if (is_path[to]) continue;
		if (to==last) continue;
		int R = dfs10(to,vertex,d+1);
		if (R!=-1) {
			if (vertex == kekos) special = to;
			return R;
		}
	}

	return -1;

}

void solve() {

	int a, b;
	cin >> n >> a >> b;

	a--, b--;
	GR.assign(n, {});

	vector<pair<int, int> > ed;

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ed.pb(mp(u, v));
		GR[u].pb(v);
		GR[v].pb(u);
	}

	particular.clear();
	LEN.assign(n, -1);
	is_good.assign(n, false);
	is_path.assign(n, false);

	dfs7(a, -1, b);

	dfs8(a, -1, 1);

	for (int i = 0; i < n; ++i) if (is_path[i]) {
		if (dfs9(i, -1)) is_good[i] = true;
	}

	for (int i = 0; i < particular.size(); ++i) {
		int W = particular[i];
		if (is_good[W]) {
			kekos = W;
			int T = dfs10(W, -1, 1);
			assert(T >= 0);

			bool ans = solve(n, ed, a, b, special, T);
			if (ans) {
				cout << "YES\n";
				return;
			}
			break;
		}
	}

	reverse(all(particular));
	for (int i = 0; i < particular.size(); ++i) {
		int W = particular[i];
		if (is_good[W]) {
			kekos = W;
			int T = dfs10(W, -1, 1);
			assert(T >= 0);

			bool ans = solve(n, ed, a, b, special, T);
			if (ans) {
				cout << "YES\n";
				return;
			}
			break;
		}
	}

	cout << "NO\n";



}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}