#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 

bool home = true;
using namespace std;

typedef long long ll;

const int FN = 4 * 3000 + 7;
const int FM = 10 * FN;
const int INF = (int)1e9 + 7;

struct Edge {
	int to;
	int cap;
	int cost;
};

int fn, fm, fs, fd;
Edge edges[2 * FM];
int inds[FN][FN], dim[FN];
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

	for (int i = 0; i < fn; i++) {
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

void rec(int a) {
	if (best[a] != INF) return;
	for (int _ = 0; _ < dim[a]; _++) {
		int i = inds[a][_];
		if (edges[i ^ 1].cap) {
			int b = edges[i].to;
			rec(b);
			best[a] = min(best[a], best[b] + edges[i ^ 1].cost);
		}
	}
}

pair<ll, ll> get() {
	ll flow = 0, cost = 0;
	int st = 0;
	//bell();
	
	for (int i = 1; i <= fn; i++) best[i] = INF;
	best[fs] = 0;
	for (int i = 1; i <= fn; i++) rec(i);

	for (int a = 1; a <= fn; a++) {
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
	while (1) {
		st++;
		if (st > 4) break;
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


int vr[3333];

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

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> vr[i];
	}
	setup(2 + 2 * n, 2 * n + 1, 2 * n + 2);
	for (int i = 1; i <= n; i++) {

		addEdge(2 * i - 1, 2 * i, 1, -1);

		addEdge(2 * n + 1, 2 * i - 1, 1, 0);
		addEdge(2 * i, 2 * n + 2, 1, 0);
	}
	const int ct = 5;
	for (int i = 1; i <= n; i++) {

		for (int j = i + 1, c = 0; j <= n && c <= ct; j++) {
			if (vr[j] == vr[i] - 1) {
				addEdge(2 * i, 2 * j - 1, 1, 0); 
				c++;
			}
		}

		for (int j = i + 1, c = 0; j <= n && c <= ct; j++) {
			if (vr[j] == vr[i] + 1) {
				addEdge(2 * i, 2 * j - 1, 1, 0);
				c++;
			}
		}
		for (int j = i + 1, c = 0; j <= n && c <= ct; j++) {
			if (vr[j] % 7 == vr[i] % 7) {
				addEdge(2 * i, 2 * j - 1, 1, 0);
				c++;
			}
		}


	}
	auto fl = get();
	cout << -fl.second << "\n";
}