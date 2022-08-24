#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 200007;

vector<int> glob[N];

struct Vertex {
	int f;
	int r;
	int g;
};

vector<Vertex> snm;

int get(int v) {

	if (snm[v].f != v) snm[v].f = get(snm[v].f);
	return snm[v].f;
}

int unite(int u, int v) {
	if (u==v) return -1;

	if (snm[u].r > snm[v].r) swap(u, v);

	snm[u].f = v;
	if (snm[u].r == snm[v].r) snm[v].r++;
	
	int A = snm[u].g;
	int B = snm[v].g;

	if (glob[A].size() > glob[B].size()) {
		swap(A, B);
	}

	int T = glob[A][0];

	for (auto x : glob[A]) glob[B].pb(x);
	snm[v].g = B; 

	return T; 

}

vector<pair<int, int> > rmq;

void upd(int i, int l, int r, int index, int val) {

	if (r-l==1) {
		rmq[i] = mp(val, l);
		return;
	}

	int mid = (l+r)/2;
	if (index < mid) upd(2*i+1, l, mid, index, val);
	else upd(2*i+2, mid, r, index, val);

	rmq[i] = max(rmq[2*i+1], rmq[2*i+2]);

}

pair<int, int> get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return mp(-1, -1);
	if (l==l1 && r==r1) return rmq[i];

	int mid = (l+r)/2;
	return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> perm(n);
	for (auto &t : perm) cin >> t;

	vector<pair<int, int> > queries;
	vector<pair<int, int> > edges;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		edges.pb(mp(u-1, v-1));
	}

	for (int i = 0; i < q; ++i) {
		int t, x;
		cin >> t >> x;
		queries.pb(mp(t, x-1));
	}

	for (int i = 0; i < n; ++i) {
		snm.pb({i, 1, i});
		glob[i].pb(i);
	}

	vector<bool> deleted(m, false);
	for (auto x : queries) {
		if (x.x == 2) {
			deleted[x.y] = true;
		}
	}


	for (int i = 0; i < m; ++i) {
		if (!deleted[i]) {
			unite(get(edges[i].x), get(edges[i].y));
		}
	}

	vector<int> symbol_query;

	reverse(all(queries));
	for (auto x : queries) {
		if (x.x == 2) {
			int ed = x.y;
			int A = get(edges[ed].x), B = get(edges[ed].y);
			symbol_query.pb(unite(A, B));
		}
		else symbol_query.pb(-1);
	}

	reverse(all(queries));
	reverse(all(symbol_query));

	vector<int> total;

	set<int> partitions;
	vector<bool> used(n, false);

	for (int i = 0; i < n; ++i) {
		int Q = get(i);
		if (used[Q]) continue;
		used[Q] = true;

		partitions.insert(total.size());

		for (auto el : glob[snm[Q].g]) {
			total.pb(el);
		}

	}

	partitions.insert(total.size());
	vector<int> pos(n);

	for (int i = 0; i < n; ++i) pos[total[i]] = i;

	rmq.assign(4*n, mp(-1, -1));
	for (int i = 0; i < n; ++i) {
		upd(0, 0, n, i, perm[total[i]]);
	}

	for (int i = 0; i < q; ++i) {
		if (queries[i].x == 2) {
			if (symbol_query[i] == -1) continue;
			partitions.insert(pos[symbol_query[i]]);
		}
		else {
			int p = pos[queries[i].y];

			int l, r;
			auto it = partitions.upper_bound(p);

			r = (*it);

			it--;

			l = (*it);

			auto res = get(0, 0, n, l, r);
			cout << res.x << '\n';
			upd(0, 0, n, res.y, 0);
		}
	}




}