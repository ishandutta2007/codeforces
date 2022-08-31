#include <bits/stdc++.h>
#define merge merg
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;

struct Edge{int index; int to; ll w;};
struct Appearance{int centroid; int son; int l; int r;};
vector<vector<Edge> > data;
vector<vector<Appearance> > app;
vector<bool> used;
vector<int> sz;

void dfs(int vertex, int last){
	sz[vertex] = 1;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to;
		if (to==last || used[to]) continue;
		dfs(to, vertex);
		sz[vertex] += sz[to];
	}
}

int cnt;

struct Rmq{
	int N;
	vector<ll> arr, p;
	vector<pair<int, int> > sons_segments;
	multiset<ll> dist;

	Rmq(int n){
		arr.assign(4*n, 0);
		p.assign(4*n, 0);
		N=n;
	}

	void push(int i, int l, int r){
		if (r-l <= 1) return;
		ll P = p[i];
		if (P==0) return;
		p[i] = 0;
		arr[2*i+1] += P, p[2*i+1] += P, arr[2*i+2] += P, p[2*i+2]+=P;
		return;
	}

	void change(int i, int l, int r, int l1, int r1, ll w){
		push(i, l, r);
		if (l1 >= r1) return;
		if (l==l1 && r==r1){
			arr[i] += w;
			p[i] += w;
			return;
		}
		int mid = (l+r)/2;
		change(2*i+1, l, mid, l1, min(r1, mid), w);
		change(2*i+2, mid, r, max(l1, mid), r1, w);
		arr[i] = max(arr[2*i+1], arr[2*i+2]);
	}

	ll get(int i, int l, int r, int l1, int r1){
		push(i, l, r);
		if (l1 >= r1) return -5e18;
		if (l==l1 && r==r1) return arr[i];
		int mid = (l+r)/2;
		return max(get(2*i+1, l, mid, l1, min(r1, mid)), get(2*i+2, mid, r, max(l1, mid), r1));
	}

};

vector<Rmq> centroids;

int current;

void dfs2(int vertex, int last, ll w, Rmq &x, int edge, int son){
	int L = cnt++;
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to;
		if (to==last || used[to]) continue;
		dfs2(to, vertex, data[vertex][i].w, x, data[vertex][i].index, son);
	}
	int R = cnt-1;
	if (last == current){
		x.sons_segments.push_back({L, R});
	}
	app[edge].push_back({centroids.size(), son, L, R});
	x.change(0, 0, x.N, L, R+1, w);
}

multiset<ll> answers;

void add(multiset<ll> &x){
	if (x.size()==1){
		answers.insert((*x.begin()));
		return;
	}
	auto it = x.end();
	ll Q = 0;
	for (int i=0;i<2;++i){
		it--;
		Q += (*it);
	}
	answers.insert(Q);
}

void remv(multiset<ll> &x){
	if (x.size()==1){
		answers.erase(answers.find(((*x.begin()))));
		return;
	}
	auto it = x.end();
	ll Q = 0;
	for (int i=0;i<2;++i){
		it--;
		Q += (*it);
	}
	answers.erase(answers.find((Q)));
}

void build_centroid(int vertex){
	dfs(vertex, -1);
	if (sz[vertex] == 1) return;

	int centr = vertex, last = -1;
	while (true){
		int bad = -1;
		for (int i=0; i < data[centr].size(); ++i){
			int to = data[centr][i].to;
			if (to==last || used[to]) continue;
			if (2 * sz[to] > sz[vertex]) bad = to;
		}
		if (bad == -1) break;
		last = centr;
		centr = bad;
	}
	cnt = 0;
	current = centr;
	Rmq r(sz[vertex]);
	int ptr=0;
	for (int i=0;i<data[centr].size(); ++i){
		int to = data[centr][i].to;
		if (used[to]) continue;
		dfs2(to, centr, data[centr][i].w, r, data[centr][i].index, ptr++);
	}
	for (int i=0; i < r.sons_segments.size(); ++i){
		r.dist.insert(r.get(0, 0, r.N, r.sons_segments[i].first, r.sons_segments[i].second+1));
	}
	add(r.dist);

	centroids.push_back(r);
	used[centr] = true;
	for (int i=0; i < data[centr].size(); ++i){
		int to = data[centr][i].to;
		if (used[to]) continue;
		build_centroid(to);
	}
}

ll print_ans(){
	auto it = answers.end();
	it--;
	return (*it);
}

vector<ll> cur_w;

void change(int edge, ll x){
	ll D = x - cur_w[edge];
	cur_w[edge] = x;
	for (int i=0; i < app[edge].size(); ++i){
		int C = app[edge][i].centroid, S = app[edge][i].son, L = app[edge][i].l, R = app[edge][i].r;
		remv(centroids[C].dist);
		centroids[C].dist.erase(centroids[C].dist.find(centroids[C].get(0, 0, centroids[C].N, centroids[C].sons_segments[S].first,centroids[C].sons_segments[S].second+1)));
		centroids[C].change(0, 0, centroids[C].N, L, R+1, D);
		ll Q = centroids[C].get(0, 0, centroids[C].N, centroids[C].sons_segments[S].first,centroids[C].sons_segments[S].second+1);
		centroids[C].dist.insert(Q);
		add(centroids[C].dist);
	}
}

main(){
	#ifdef LOCAL
    freopen("H_input.txt", "r", stdin);
    //freopen("B_output.txt", "w", stdout);
#endif
	int n, q;
	ll w;
	cin >> n >> q >> w;
	data.assign(n, {});
	cur_w.assign(n-1, {});
	for (int i=0; i < n-1; ++i){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		data[a].push_back({i, b, c});
		data[b].push_back({i, a, c});
		cur_w[i] = c;
	}
	app.assign(n-1, {});
	used.assign(n, false);
	sz.assign(n, 0);
	build_centroid(0);
	ll last = 0;
	for (int i=0; i < q; ++i){
		int d;
		ll e;
		cin >> d >> e;
		d = (d+last)%(n-1);
		e = (e+last)%w;
		change(d, e);
		ll res = print_ans();
		last = res;
		cout << res << "\n";
	}
}