#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define tm lajksdf
#define F first
#define S second

const int MAXN = 1e5 + 10;
const int INF = 1e8;

int n, sub[MAXN], st[MAXN], ft[MAXN], tm, mp[MAXN], ans[MAXN];
vector<int> adj[MAXN];
set<pii> weed[MAXN<<2];

void dfs(int v){
	mp[tm] = v;
	st[v] = tm++;
	sub[v] = 1;
	for (int u:adj[v])
		dfs(u), sub[v] += sub[u];
	ft[v] = tm;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		weed[v].insert({sub[mp[b]]<<1, mp[b]});
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);

	auto hint = weed[v].begin();
	for (auto x:weed[v<<1]) hint = weed[v].insert(hint, x);
	for (auto x:weed[v<<1^1]) hint = weed[v].insert(hint, x);
}

int smoke(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		auto it = weed[v].lower_bound(make_pair(x, -1));
		int y = -INF, z = -INF;
		if (it != weed[v].end()) y = it->F;
		if (it != weed[v].begin()){
			it--;
			z = it->F;
		}

		if (abs(y-x) < abs(z-x)) return y;
		return z;
	}
	if (r <= b || e <= l) return -INF;

	int mid = b + e >> 1;
	int y = smoke(v<<1, b, mid, l, r, x);
	int z = smoke(v<<1^1, mid, e, l, r, x);
	if (abs(y-x) < abs(z-x)) return y;
	return z;
}

void ers(int v, int b, int e, int pos, int x, int y){
	weed[v].erase({x, y});
	if (e - b == 1) return;

	int mid = b + e >> 1;
	if (pos < mid)
		ers(v<<1, b, mid, pos, x, y);
	else
		ers(v<<1^1, mid, e, pos, x, y);
}

void ins(int v, int b, int e, int pos, int x, int y){
	weed[v].insert({x, y});
	if (e - b == 1) return;

	int mid = b + e >> 1;
	if (pos < mid)
		ins(v<<1, b, mid, pos, x, y);
	else
		ins(v<<1^1, mid, e, pos, x, y);
}

pii sec[MAXN];
set<pii> ss;
void go(int v, int p = -1){
	int sz = 0;
	for (int u:adj[v]) sec[sz++] = {sub[u], u};
	if (~p) sec[sz++] = {n-sub[v], p};

	if (sz < 2) ans[v] = n-1;
	else{
		sort(sec, sec + sz);
		reverse(sec, sec + sz);
		if (sec[0].S^p){
			int dif = sec[0].F-sec[sz-1].F;
			int y = smoke(1, 0, n, st[sec[0].S], ft[sec[0].S], dif)>>1;
			ans[v] = max(sec[0].F-y, sec[sz-1].F+y);
			if (sz > 2)
				ans[v] = max(ans[v], sec[1].F);
			ans[v] = min(ans[v], sec[0].F);
		}
		else{
			int dif = sec[0].F-sec[sz-1].F;
			int y = smoke(1, 0, n, 0, st[v], dif);
			int z = smoke(1, 0, n, ft[v], n, dif);
			if (abs(y-dif) > abs(z-dif)) swap(y, z);
			int temp;
			{
				auto it = ss.lower_bound({dif+(sub[v]<<1), -1});
				int y = -INF, z = -INF;
				if (it != ss.end()) y = it->F;
				if (it != ss.begin()){
					it--;
					z = it->F;
				}
				if (abs(y-(dif+(sub[v]<<1))) > abs(z-(dif+(sub[v]<<1)))) swap(y, z);
				y -= sub[v]<<1;
				temp = y;
			}
			z = temp;
			if (abs(y-dif) > abs(z-dif)) swap(y, z);

			y >>= 1;

			ans[v] = max(sec[0].F-y, sec[sz-1].F+y);
			if (sz > 2)
				ans[v] = max(ans[v], sec[1].F);

			ans[v] = min(ans[v], sec[0].F);
		}
	}

	if (adj[v].size()){
		ers(1, 0, n, st[v], sub[v]<<1, v);
		ins(1, 0, n, st[v], -INF, v);
		for (int u:adj[v]){
			ss.insert({sub[v]<<1, v});
			go(u, v);
			ss.erase({sub[v]<<1, v});
		}
		ers(1, 0, n, st[v], -INF, v);
		ins(1, 0, n, st[v], sub[v]<<1, v);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int root = -1;
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b, a--, b--;
		if (~a)
			adj[a].push_back(b);
		else
			root = b;
	}
	dfs(root);
	plant(1, 0, n);
	go(root);
	for (int v = 0; v < n; v++)
		cout << ans[v] << "\n";
	return 0;
}