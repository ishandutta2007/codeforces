#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int h = 19;
int N, M;
ll baseCost;

struct edge {
	int cost;
	int first, second;
	int ind;
	bool operator<(const edge& o) const {
		return cost < o.cost;
	}
};

vector<vector<pii>> adj_list;
vector<edge> edges;
vector<vector<pii>> par;
vector<int> level;

vector<int> ufp;
void SETUP(int s) {
	ufp = vector<int>(s, -1);
}
int FIND(int s) {
	if(ufp[s] == -1) return s;
	return ufp[s] = FIND(ufp[s]);
}
void UNION(int a, int b) {
	if(FIND(a) == FIND(b)) return;
	ufp[FIND(a)] = FIND(b);
}

void readIt() {
	scanf("%d %d", &N, &M);
	int u, v, w;
	for(int i=0;i<M;++i) {
		scanf("%d %d %d", &u, &v, &w);
		--u;--v;
		edges.push_back({w, u, v, i});
	}
	sort(edges.begin(), edges.end());
	adj_list.resize(N);
	level = vector<int>(N, -1);
	par = vector<vector<pii>>(N, vector<pii>(h));
}
void constructMst() {
	SETUP(N);
	int merges = 0;
	baseCost = 0;
	for(int i=0;i<M && merges < N-1;++i) {
		if(FIND(edges[i].first) != FIND(edges[i].second)) {
			UNION(edges[i].first, edges[i].second);
			baseCost += edges[i].cost;
			adj_list[edges[i].first].push_back({edges[i].second, edges[i].cost});
			adj_list[edges[i].second].push_back({edges[i].first, edges[i].cost});
			++merges;
		}
	}
	queue<int> q;
	par[0][0] = pii(-1, -1);
	// node, parent, cost of edge we took.
	q.push(0);
	level[0] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		int v, cst;
		for(pii pr : adj_list[u]) {
			v = pr.first;
			cst = pr.second;
			if(level[v] != -1) continue;
			par[v][0] = pii(u, cst);
			level[v] = level[u]+1;
			q.push(v);
		}
	}
}

void buildJump() {
	for(int hh = 1; hh < h; ++hh) {
		for(int i=0;i<N;++i) {
			if(par[i][hh-1].first == -1) {
				par[i][hh] = pii(-1, -1); continue;
			} if(par[par[i][hh-1].first][hh-1].first == -1) {
				par[i][hh] = pii(-1, -1); continue;
			}
			par[i][hh].first = par[par[i][hh-1].first][hh-1].first;
			par[i][hh].second = max(par[par[i][hh-1].first][hh-1].second, par[i][hh-1].second);
		}
	}
}

int getNthParent(int v, int n) {
	for(int i=h-1; i>=0;--i) {
		if(n & (1 << i)) {
			n-= (n << i);
			v = par[v][i].first;
		}
	}
	return v;
}

bool verbose = false;

int pathMax(int a, int b) {
	ll best = 0;
	if(level[a] > level[b]) swap(a, b);

	int diff = level[b]-level[a];
	for(int i=h-1; i>=0;--i) {
		if(diff & (1 << i)) {
			diff-= (diff << i);
			best = max(best, par[b][i].second);
			b = par[b][i].first;
		}
	}

	for(int i=h-1;i>=0;--i) {
		if(par[a][i].first == par[b][i].first) continue;
		best = max(max(par[a][i].second, par[b][i].second), best);
		a = par[a][i].first;
		b = par[b][i].first;
	}
	if(a != b) {
		best = max(best, max(par[a][0].second, par[b][0].second));
		a = par[a][0].first;
		b = par[b][0].first;
	}
	return best;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	readIt();
	constructMst();
	buildJump();
	/*
	for(int i=0;i<N;++i) {
		cerr << i << ":\t";
		for(int hh=0;hh<4;++hh) {
			cerr << "(" << par[i][hh].first << "," << par[i][hh].second << ")\t";
		}
		cerr << endl;
	}
	int testu, testv;
	cerr << " u:"; cin >> testu; -- testu;
	cerr << " v:"; cin >> testv; -- testv;
	cerr << " Path max: " << pathMax(testu, testv) << endl;
	*/
	vector<ll> ans(M);
	for(int i=0;i<M;++i) {
		edge e = edges[i];
		ll tcost = baseCost + e.cost - pathMax(e.first, e.second);
		ans[e.ind] = tcost;
	}
	for(int i=0;i<M;++i)
		cout << ans[i] << "\n";


	return 0;
}