#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define tm kljasfd

const int MAXN = 1e5 + 10;
const ll INF = 1e18;

int n, par[MAXN], sub[MAXN];
vector<int> adj[MAXN];
int st[MAXN], ft[MAXN], tm, depth[MAXN];

bool cmp(int u, int v){return sub[u] > sub[v];}

void buildH(int v){
	sub[v] = 1;
	for (int u:adj[v])
		buildH(u), sub[v] += sub[u];
	sort(adj[v].begin(), adj[v].end(), cmp);
}

int start = -1, anc[MAXN];
void buildTree(int v, int de = 0){
	st[v] = tm++;
	depth[v] = de;

	if (start == -1) start = v;
	anc[v] = start;

	for (int u:adj[v]){
		buildTree(u, de+1);
		start = -1;
	}

	ft[v] = tm;
}

ll sm[MAXN<<2], mx[MAXN<<2];
int lz[MAXN<<2];

void plant(int v, int b, int e){
	if (e - b == 1){
		sm[v] = mx[v] = -1;
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	sm[v] = sm[v<<1] + sm[v<<1^1];
	mx[v] = max(mx[v<<1^1], sm[v<<1^1] + mx[v<<1]);
}

void absorb(int v, int b, int e, int mid){
	if (lz[v]){
		sm[v<<1] = -(mid-b);
		sm[v<<1^1] = -(e - mid);
		mx[v<<1] = mx[v<<1^1] = -1;
		lz[v<<1] = lz[v<<1^1] = 1;
		lz[v] = 0;
	}
}

void updRange(int v, int b, int e, int l, int r){
	if (l <= b && e <= r){
		sm[v] = -(e-b);
		mx[v] = -1;
		lz[v] = 1;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	updRange(v<<1, b, mid, l, r);
	updRange(v<<1^1, mid, e, l, r);
	sm[v] = sm[v<<1] + sm[v<<1^1];
	mx[v] = max(mx[v<<1^1], sm[v<<1^1] + mx[v<<1]);
}

pair<ll, ll> getRange(int v, int b, int e, int l, int r){
	if (l <= b && e <= r) return {mx[v], sm[v]};
	if (r <= b || e <= l) return {-INF, 0};

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	auto resL = getRange(v<<1, b, mid, l, r), resR = getRange(v<<1^1, mid, e, l, r);
	return {max(resR.F, resR.S + resL.F), resL.S + resR.S};
}

void inc(int v, int b, int e, int pos, ll val){
	if (e - b == 1){
		sm[v] += val;
		mx[v] += val;
		return;
	}

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	if (pos < mid)
		inc(v<<1, b, mid, pos, val);
	else
		inc(v<<1^1, mid, e, pos, val);

	sm[v] = sm[v<<1] + sm[v<<1^1];
	mx[v] = max(mx[v<<1^1], sm[v<<1^1] + mx[v<<1]);
}

ll getMax(int v){
	ll ret = -INF, sm = 0;
	while (~v){
		auto x = getRange(1, 0, n, st[v] - (depth[v] - depth[anc[v]]), st[v] + 1);
		ret = max(ret, x.F + sm);
		sm += x.S;
		v = par[anc[v]];
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> n >> q;
	par[0] = -1;
	for (int i = 1; i < n; i++){
		int p; cin >> p, p--;
		adj[p].push_back(i);
		par[i] = p;
	}
	buildH(0);
	buildTree(0);
	plant(1, 0, n);

	while (q--){
		int t, v; cin >> t >> v, v--;
		if (t == 1)
			inc(1, 0, n, st[v], 1);
		else if (t == 2){
			updRange(1, 0, n, st[v], ft[v]);
			if (~par[v]){
				auto x = getMax(par[v]);
				if (x > 0)
					inc(1, 0, n, st[v], -x);
			}
		}
		else{
			auto x = getMax(v);
			if (x >= 0)
				cout << "black\n";
			else
				cout << "white\n";
		}
	}
	return 0;
}