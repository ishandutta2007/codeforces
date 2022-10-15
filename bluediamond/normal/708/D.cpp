#include <iostream> 
#include <vector> 
#include <queue> 
#include <cstdio> 

bool home = true;
using namespace std;

typedef long long ll;

const int FN = 100 + 7;
const int FM = FN * FN;
const int INF = (int)1e9 + 7;

struct Edge {
	int to;
	int cap;
	int cost;
};

int fn, fm, fs, fd;
Edge edges[2 * FM];
int inds[FN][FM], dim[FN];
int best[FN], init_best[FN];
int parrent_edge[FN];
bool inq[FN];
queue<int> fq;
priority_queue<pair<int, int>> fpq;

void setup(int n, int s, int d) {
	fn = n;
	fm = 0;
	fs = s;
	fd = d;


	for (int i = 1; i <= fn; i++) {
		dim[i] = 0;
	}
}

void addEdge(int a, int b, int cap, int cost) {
	inds[a][dim[a]++] = fm;
	inds[b][dim[b]++] = fm + 1;
	edges[fm++] = { b, cap, cost };
	edges[fm++] = { a, 0, -cost };
}

void bell() {
	for (int i = 1; i <= fn; i++) best[i] = INF, inq[i] = 0;

	inq[fs] = 1;
	best[fs] = 0;
	fq.push(fs);

	while (!fq.empty()) {
		int a = fq.front();
		fq.pop();
		inq[a] = 0;
		for (int _ = 0; _ < dim[a]; _++) {
			int i = inds[a][_];
			if (edges[i].cap) {
				int b = edges[i].to, cost = edges[i].cost;
				if (best[a] + cost < best[b]) {
					best[b] = best[a] + cost;
					parrent_edge[b] = i;
					if (!inq[b]) inq[b] = 1, fq.push(b);
				}
			}
		}
	}
}

void dij() {

	for (int i = 1; i <= fn; i++) init_best[i] = best[i], best[i] = INF;

	best[fs] = 0;
	fpq.push({ 0, fs });

	while (!fpq.empty()) {
		pair<int, int> tp = fpq.top();
		fpq.pop();
		int a = tp.second;
		int _a_ = -tp.first;
		if (_a_ != best[a]) continue;
		for (int _ = 0; _ < dim[a]; _++) {
			int i = inds[a][_];
			if (edges[i].cap) {
				int b = edges[i].to, cost = edges[i].cost;
				if (best[a] + init_best[a] + cost - init_best[b] < best[b]) {
					best[b] = best[a] + init_best[a] + cost - init_best[b];
					parrent_edge[b] = i;
					fpq.push({ -best[b], b });
				}
			}
		}
	}
	for (int a = 1; a <= fn; a++) {
		best[a] = best[a] - init_best[fs] + init_best[a];
	}
}

pair<ll, ll> get() {
	ll flow = 0, cost = 0;
	bell();
	while (1) {
		dij();
		int coef = best[fd];
		if (coef >= INF) break;
		int mn = INF;

		int vertex = fd;
		while (vertex != fs) {
			int i = parrent_edge[vertex];

			mn = min(mn, edges[i].cap);

			vertex = edges[i ^ 1].to;
		}

		vertex = fd;

		while (vertex != fs) {
			int i = parrent_edge[vertex];

			edges[i].cap -= mn;
			edges[i ^ 1].cap += mn;

			vertex = edges[i ^ 1].to;
		}

		flow += mn;
		cost += mn * (ll)coef;
	}
	return { flow, cost };
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	ll cost = 0;

	{
		int n, m, s, d;
		cin >> n >> m;

		s = n + 1;
		d = n + 2;

		setup(n + 2, s, d);

		vector<int> bal(n + 1, 0);
		for (int i = 1; i <= m; i++) {
			int a, b, f, c;
			cin >> a >> b >> c >> f;
			bal[b] += f;
			bal[a] -= f;



			if (f <= c) {
				addEdge(a, b, c - f, 1);
				addEdge(b, a, f, 1);
				addEdge(a, b, INF, 2);
			}
			else {
				cost += f - c;
				addEdge(b, a, f - c, 0);
				addEdge(b, a, c, 1);
				addEdge(a, b, INF, 2);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (bal[i] > 0) {
				addEdge(s, i, bal[i], 0);
			}
			else {
				addEdge(i, d, -bal[i], 0);
			}
		}
		addEdge(n, 1, INF, 0); // throw away
		cost += get().second;
		cout << cost << "\n";
	}
}