//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 100100;

struct edge {
	int a, b, w;
	bool operator< (edge o) const {
		return tie(w, a, b) < tie(o.w, o.a, o.b);
	}
	bool operator== (edge o) const {
		return a == o.a && b == o.b && w == o.w;
	}
};

int n, m, q;
multiset<ll> three;
set<edge> s[N][2], good_edges;
map<pair<int, int>, int> wei;

ll sum(int x) {
	if (int(s[x][0].size()) < 3)
		return 0;
	ll sum = 0;
	for (auto e : s[x][0])
		sum += e.w;
	return sum;
}

bool good_edge(edge e) {
	auto top3 = [&](int x) {
		auto it = s[x][0].lower_bound(e);
		if (it != s[x][0].end() && *it == e)
			return true;
		return false;
	};
	return top3(e.a) && top3(e.b);
}

void upd(int x) {
	if (sum(x) > 0)
		three.insert(sum(x));
	for (auto e : s[x][0])
		if (good_edge(e))
			good_edges.insert(e);
}

void clear(int x) {
	for (auto e : s[x][0])
		good_edges.erase(e);
	if (sum(x) != 0)
		three.erase(three.find(sum(x)));
}

void add_node(int x, edge e) {
	s[x][0].insert(e);
	if (int(s[x][0].size()) > 3) {
		auto it = prev(s[x][0].end());
		s[x][1].insert(*it);
		s[x][0].erase(it);
	}
}

void add() {
	int a, b, w;
	cin >> a >> b >> w;
	if (a > b)
		swap(a, b);
	wei[make_pair(a, b)] = w;
	clear(a);
	clear(b);
	add_node(a, edge{a, b, w});
	add_node(b, edge{a, b, w});
	upd(a);
	upd(b);
}

void rem_node(int x, edge e) {
	s[x][0].erase(e);
	s[x][1].erase(e);
	if (int(s[x][0].size()) < 3 && !s[x][1].empty()) {
		auto it = s[x][1].begin();
		s[x][0].insert(*it);
		s[x][1].erase(it);
	}
}

void rem() {
	int a, b;
	cin >> a >> b;
	if (a > b) 
		swap(a, b);
	int w = wei[make_pair(a, b)];
	clear(a);
	clear(b);
	rem_node(a, edge{a, b, w});
	rem_node(b, edge{a, b, w});
	upd(a);
	upd(b);
}

ll query() {
	ll res = 5e9;
	if (!three.empty())
		res = *three.begin();

	auto relax = [&](edge x, edge y) {
		set<int> q;
		q.insert(x.a);
		q.insert(x.b);
		q.insert(y.a);
		q.insert(y.b);
		if (int(q.size()) == 4) {
			res = min<ll>(res, x.w + y.w);
			return true;
		}
		return false;
	};

	assert(good_edges.size() > 0);
	auto mini = *good_edges.begin();
	for (auto x : s[mini.a][0])
		for (auto y : s[mini.b][0])
			relax(x, y);

	for (auto e : good_edges) {
		if (relax(mini, e)) {
			break;
		}
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	while (m--)
		add();
	cout << query() << '\n';

	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 0)
			rem();
		if (t == 1)
			add();
		cout << query() << '\n';
	}

	return 0;
}