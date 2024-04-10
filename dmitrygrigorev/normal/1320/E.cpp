#include <bits/stdc++.h>
#define data dlkgfk
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


struct FastLCA{

	static const int N = 524288, LG = 21; //N >= 2*n + 7 and N = 2^k

	vector<vector<int> > data;
	vector<int> euler, where, depth, logs;
	int table[N][LG];

	void dfs(int vertex, int last, int d){
	    where[vertex] = euler.size();
	    euler.push_back(vertex);
	    depth[vertex] = d;
	    for (int i=0; i < (int) data[vertex].size(); i++){
	        int to = data[vertex][i];
	        if (to==last) continue;
	        dfs(to, vertex, d + 1);
	        euler.push_back(vertex);
	    }
	}

	void init(vector<pair<int, int> > edges) { //edges are given in 0-indexation
		int n = edges.size() + 1;
		data.assign(n, {}), where.assign(n, -1), depth.assign(n, -1);
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i].first, v = edges[i].second;
			data[u].push_back(v), data[v].push_back(u);
		}
		dfs(0, -1, 0);


		int sz = euler.size();
	    for (int i=0; i < sz; i++){
	        table[i][0] = euler[i];
	    }
		int counter = 1;
	    int start_log = 1;
	    logs.push_back(0);
	    for (int i=2; i <= N; i*=2){
	        for (int j=0; j + i <= sz; j++){
	            int fv = table[j][counter - 1];
	            int sv = table[j + i/2][counter-1];
	            if (depth[fv] <= depth[sv]) table[j][counter] = fv;
	            else table[j][counter] = sv;
	        }
	        for (int j=start_log; j <= i; j++){
	            logs.push_back(counter - 1);
	        }
	        start_log = i + 1;
	        counter += 1;
	    }
	}

	int get(int q1, int q2) { //queries are given in 0-indexation
		int first = where[q1];
        int second = where[q2];
        if (first > second) swap(first, second);
        int dist = second - first + 1;
        int first_cand = table[first][logs[dist]];
        int second_cand = table[second + 1 - (1 << logs[dist])][logs[dist]];
        int ans;
        if (depth[first_cand] < depth[second_cand]) ans = first_cand;
        else ans = second_cand;
        return ans;
	}

};
FastLCA flca;

struct Edge {
	int to; int len;
};

vector<vector<int> > data;
vector<vector<Edge> > gr;

vector<pair<int, int> > subtree;

vector<int> tour;
vector<int> tin;

vector<int> trans, rev_trans;

int timer = 0;

void dfs(int vertex, int last) {
	tin[vertex] = timer++;
	tour.push_back(vertex);

	for (int i = 0; i < data[vertex].size(); ++i) {
		int to = data[vertex][i];
		if (to == last) continue;
		dfs(to, vertex);
	}

	subtree[vertex] = {tin[vertex], tour.size() - 1};

}

void transform(vector<int> &v) {
	sort(v.begin(), v.end());
	vector<int> t;
	t.push_back(v[0]);
	for (int i = 1; i < v.size(); ++i) {
		if (v[i] != v[i-1]) t.push_back(v[i]);
	}
	v=t;
}

bool cmp(int x, int y) {
	return (flca.depth[x] > flca.depth[y]);
}

vector<int> rmq;

void down(int i, int l, int r) {
	if (r-l==1) {
		rmq[i] = -1;
		return;
	}

	int mid = (l+r)/2;
	if (rmq[i] == rmq[2*i+1]) {
		down(2*i+1, l, mid);
	}
	else down(2*i+2, mid, r);
	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

int ask(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return -1;
	if (l == l1 && r==r1) {
		int res = rmq[i];
		if (res != -1) {
			down(i, l, r);
		}
		return res;
	}

	int mid = (l+r)/2;
	int A = ask(2*i+1, l, mid, l1, min(r1, mid));
	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

	if (A != -1) {
		return A;
	}

	int B = ask(2*i+2, mid, r, max(l1, mid), r1);
	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
	return B;

} 

void add(int i, int l, int r, int index, int val) {
	if (r-l == 1) {
		rmq[i] = val;
		return;
	}
	int mid = (l+r)/2;
	if (index < mid) add(2*i+1, l, mid, index, val);
	else add(2*i+2, mid, r, index, val);
	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);
}

struct Eat {int vertex; int steps; int num; int tot;};

struct lex_compare {
    bool operator() (const Eat& lhs, const Eat& rhs) const {
        pair<int, int> a = {lhs.steps, lhs.num};
        pair<int, int> b = {rhs.steps, rhs.num};
        if (a!=b) return (a<b);
        return (lhs.vertex < rhs.vertex);
    }
};

bool mcmp(Eat &lhs, Eat &rhs) {
	pair<int, int> a = {lhs.steps, lhs.num};
	pair<int, int> b = {rhs.steps, rhs.num};
    if (a!=b) return (a<b);
    return (lhs.vertex < rhs.vertex);
}

const int INF = 1e9;

vector<int> finish(vector<pair<int, int> > &take) {

	int S = gr.size();
	vector<Eat> ans(S);

	set<Eat, lex_compare> ms;

	for (int i = 0; i < S; ++i) {
		ans[i] = {i, INF, INF, INF};
	}

	for (int i = 0; i < take.size(); ++i) {
		ans[take[i].first] = {take[i].first, 0, i, 0};
	}

	for (int i = 0; i < S; ++i) {
		ms.insert(ans[i]);
	}

	vector<bool> dec(S, false);


	while (ms.size()) {
		auto it = ms.begin();
		Eat cur = (*it);
		ms.erase(it);

		dec[cur.vertex] = true;


		for (int i = 0; i < gr[cur.vertex].size(); ++i) {
			int to = gr[cur.vertex][i].to, W = gr[cur.vertex][i].len;

			int dist = W + cur.tot;
			int index = cur.num;
			int req = (dist + take[index].second - 1) / take[index].second;
			//cout << " === " << cur.vertex << " " << to << " " << W << " " << req << " " << index << endl;
			Eat now = {to, req, index, dist};
			if (!dec[to] && mcmp(now, ans[to])) {
				ms.erase(ms.find(ans[to]));
				ans[to] = now;
				ms.insert(ans[to]);
			}

		}

	}

	vector<int> res;
	for (int i = 0; i < S; ++i) {
		res.push_back(ans[i].num);
	}

	return res;



}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > v;
	vector<pair<int, int> > need;
	vector<int> W, q; 

	for (int i = 0; i < n; ++i) {
		int t, s;
		cin >> t >> s;
		t--;
		v.push_back({t, s});
		need.push_back({tin[t], t});
		W.push_back(t);
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		t--;
		q.push_back(t);
		need.push_back({tin[t], t});
		W.push_back(t);
	}

	sort(need.begin(), need.end());

	for (int i = 0; i + 1 < need.size(); ++i) {
		W.push_back(flca.get(need[i].second, need[i+1].second));
	}

	transform(W);
	sort(W.begin(), W.end(), cmp);

	vector<pair<int, int> > edges;
	for (int i = 0; i < W.size(); ++i) {
		int L = subtree[W[i]].first, R = subtree[W[i]].second;

		while (true) {
			int res = ask(0, 0, data.size(), L, R+1);
			if (res == -1) {
				add(0, 0, data.size(), L, W[i]);
				break;
			}
			else {
				edges.push_back({res, W[i]});
			}
		}

	}

	while (true) {
		int res = ask(0, 0, data.size(), 0, data.size());
		if (res == -1) break;
	}

	int S = W.size();
	for (int i = 0; i < W.size(); ++i) {
		//cout << i << " = " << W[i] << endl;
		trans[W[i]] = i;
	}

	gr.assign(S, {});
	for (int i = 0; i < edges.size(); ++i) {
		int lca = flca.get(edges[i].first, edges[i].second);
		int len = abs(flca.depth[edges[i].first] - flca.depth[lca]);
		len += abs(flca.depth[edges[i].second] - flca.depth[lca]);

		int u = trans[edges[i].first], w = trans[edges[i].second];

		gr[u].push_back({w, len});
		gr[w].push_back({u, len});
	}

	for (int i = 0; i < v.size(); ++i) {
		v[i].first = trans[v[i].first];
	}

	vector<int> ans = finish(v);

	for (int i = 0; i < q.size(); ++i) {
		cout << ans[trans[q[i]]]+1 << " ";
	}

	cout << "\n";

	for (int i = 0; i < W.size(); ++i) {
		trans[W[i]] = -1;
	}

	

}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	data.assign(n, {});
	vector<pair<int, int> > ed;

	for (int i = 0; i < n-1; ++i) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
		ed.push_back({u, v});
	}
	flca.init(ed);

	tin.assign(n, -1);
	subtree.assign(n, make_pair(-1, -1));
	trans.assign(n, -1);
	rev_trans.assign(n, -1);

	dfs(0, -1);

	int q;
	cin >> q;

	rmq.assign(4*n, -1);

	for (int i = 0; i < q; ++i) solve();

}