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

const int N = (int)2e5 + 7;
const int INF = (int)1e9 + 7;
int n;
int m;
vector<int> g[N];

void addEdge(int a, int b) {
	g[a].push_back(b);
	g[b].push_back(a);
}

struct Edge {
	int a, b, c, solution;
	int init;
};

bool operator < (Edge x, Edge y) {
	return x.c < y.c;
}


int t2[N], dep[N], guy[N];

void clr2() {
	for (int i = 1; i <= n; i++) t2[i] = i, guy[i] = i;
}

int get2(int a) {
	if (t2[a] == a) return a;
	return t2[a] = get2(t2[a]);
}

void unite2(int a, int b) {
	a = get2(a);
	b = get2(b);
	if (a == b) return;
	
	if (dep[guy[a]] < dep[guy[b]]) {
		guy[b] = guy[a];
	}
	t2[a] = b;

}


int t[N];

void clr() {
	for (int i = 1; i <= n; i++) t[i] = i;
}

int get(int a) {
	if (t[a] == a) return a;
	return t[a] = get(t[a]);
}

void unite(int a, int b) {
	t[get(a)] = get(b);
}


struct Question {
	int index, low, high;
};

int par[N];
void build(int a, int p = -1) {
	for (auto& b : g[a]) {
		if (b == p) continue;
		dep[b] = 1 + dep[a];
		par[b] = a;
		build(b, a);
	}
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

	cin >> n >> m;
	vector<Edge> edges(m); 
	{
		int y = 0;
		for (auto& edge : edges) {
			cin >> edge.a >> edge.b >> edge.c;
			edge.solution = -1;
			edge.init = y++;
		}
	}

	sort(edges.begin(), edges.end());
	clr();
	for (auto& edge : edges) {
		if (get(edge.a) == get(edge.b)) continue;
		unite(edge.a, edge.b);
		addEdge(edge.a, edge.b);
	}
	vector<Question> questions(m);
	for (int i = 0; i < m; i++) {
		questions[i] = { i, 0, INF };
	}
	build(1);
	while (!questions.empty()) {
		clr();
		clr2();
		{
			vector<Question> aux;
			for (auto& it : questions) {
				if (it.low > it.high) continue;
				aux.push_back(it);
			}
			questions = aux;
			if (questions.empty()) break;
		}
		{
			for (int i = 1; i < (int)questions.size(); i++) {
				assert(questions[i - 1].low + questions[i - 1].high <= questions[i].low + questions[i].high);
			}
		}
		vector<Question> aux;
		int ptr = 0;
		int l = 0;
		while (l < (int)questions.size()) {
			int mid = (questions[l].low + questions[l].high) / 2;
			int r = l;
			while (r + 1 < (int)questions.size() && (questions[r + 1].low + questions[r + 1].high) / 2 == mid) {
				r++;
			}
			while (ptr < m && edges[ptr].c <= mid) {
				int a = edges[ptr].a, b = edges[ptr].b;
				if (get(a) != get(b)) {
					unite(a, b);
				}
				else {
					while (get2(a) != get2(b)) {
						if (dep[b] > dep[a]) swap(a, b);
						unite2(a, par[a]);
						a = guy[get2(a)];
					}
				}
				ptr++;
			}
			vector<Question> F, S;
			for (int it = l; it <= r; it++) {
				int i = questions[it].index;
				bool con = (edges[i].c > mid) ? (get(edges[i].a) == get(edges[i].b)) : (get2(edges[i].a) == get2(edges[i].b));
				if (!con) {
					edges[i].solution = mid;
					S.push_back(questions[it]);
				}
				else {
					F.push_back(questions[it]);
				}
			}
			for (auto& it : F) {
				it.high = mid - 1;
				aux.push_back(it);
			}
			for (auto& it : S) {
				it.low = mid + 1;
				aux.push_back(it);
			}
			l = r + 1;
		}
		questions = aux;
	}
	vector<int> print(m);
	for (auto& it : edges) {
		print[it.init] = it.solution;
	}
	for (auto& x : print) {
		if (x == INF) x = -1;
		cout << x << " ";
	}
	cout << "\n";
}