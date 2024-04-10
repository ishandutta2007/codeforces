#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;
const ll INF = 1e16;

int n;
pair<ll, ll> seg[4 * MAXN];
ll lz[4 * MAXN];
vector<pair<int, int>> adj[MAXN];
vector<pair<pair<int, int>, int>> vec[MAXN];
pair<int, int> sec[MAXN]; int sz; bool del[MAXN]; vector<int> gec[4 * MAXN];

pair<ll, ll> gg(pair<ll, ll> a, pair<ll, ll> b){
	if (a.S == INF) return b;
	if (b.S == INF) return a;
	return min(a, b);
}

void insert(int v, int b, int e, int l, int r, int id){
	if (l <= b && e <= r){
		gec[v].push_back(id);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	insert(v<<1, b, mid, l, r, id);
	insert(v<<1^1, mid, e, l, r, id);
}

void absorb(int v){
	if (lz[v] >= INF) return;
	lz[v<<1] = min(lz[v<<1], lz[v]);
	lz[v<<1^1] = min(lz[v<<1^1], lz[v]);
	seg[v<<1].F = min(seg[v<<1].F, lz[v]);
	seg[v<<1^1].F = min(seg[v<<1^1].F, lz[v]);
	lz[v] = INF;
}

void plant(int v, int b, int e){
	if (e - b == 1){
		seg[v] = {INF, b};
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	seg[v] = gg(seg[v<<1], seg[v<<1^1]);
}

void modify(int v, int b, int e, int pos, ll val){
	if (e - b == 1){
		seg[v].F = min(seg[v].F, val);
		if (val == INF)
			seg[v] = {INF, INF};
		return;
	}

	int mid = b + e >> 1;
	absorb(v);
	if (pos < mid)
		modify(v<<1, b, mid, pos, val);
	else
		modify(v<<1^1, mid, e, pos, val);
	seg[v] = gg(seg[v<<1], seg[v<<1^1]);
}

void segUpd(int v, int b, int e, int l, int r, ll x){
	if (l <= b && e <= r){
		lz[v] = min(lz[v], x);
		seg[v].F = min(seg[v].F, x);
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b+e>>1;
	absorb(v);
	segUpd(v<<1, b, mid, l, r, x);
	segUpd(v<<1^1, mid, e, l, r, x);
	seg[v] = gg(seg[v<<1], seg[v<<1^1]);
}

void go(int v, int b, int e, int pos, ll x){
	for (auto e:gec[v])
		if (!del[e])
			modify(1, 0, n, sec[e].F, x+sec[e].S), del[e] = 1;

	if (e - b == 1) return;

	int mid = b + e >> 1;
	if (pos < mid)
		go(v<<1, b, mid, pos, x);
	else
		go(v<<1^1, mid, e, pos, x);
}

void update(int v, ll x){
	for (auto e:adj[v])
		modify(1, 0, n, e.F, x + e.S);
	for (auto e:vec[v])
		segUpd(1, 0, n, e.F.F, e.F.S, x+e.S);
	go(1, 0, n, v, x);
}

ll ans[MAXN];

void dijk(int v){
	memset(lz, 63, sizeof(lz));
	plant(1, 0, n);
	modify(1, 0, n, v, 0);
	ans[v] = 0ll;
	update(v, 0ll);
	while (1){
		pair<ll, ll> x = seg[1];
		if (x.S >= INF || x.F >= INF) return;
		ans[x.S] = x.F;
		modify(1, 0, n, x.S, INF);
		update(x.S, x.F);
	}
}

int main(){
	int m, s;	scanf("%d %d %d", &n, &m, &s), s--;
	while (m--){
		int tp; scanf("%d", &tp);
		if (tp == 1){
			int u, v, w; scanf("%d %d %d", &u, &v, &w), u--, v--;
			adj[u].push_back({v, w});
		}
		else{
			int u, l, r, w; scanf("%d %d %d %d", &u, &l, &r, &w), l--, u--;
			if (tp == 2)
				vec[u].push_back({{l, r}, w});
			else{
				sec[sz++] = {u, w};
				insert(1, 0, n, l, r, sz-1);
			}
		}
	}
	memset(ans, 63, sizeof(ans));
	dijk(s);
	for (int i = 0; i < n; i++){
		if (ans[i] >= INF) ans[i] = -1;
		printf("%lld ", ans[i]);
	}
	printf("\n");
	return 0;
}