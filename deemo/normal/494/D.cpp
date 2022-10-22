#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second
#define tm lkashdf

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, q;
ll depth[MAXN], weed[4 * MAXN], nut[4 * MAXN], sm[4 * MAXN], ans[MAXN];
int s_t[MAXN], f_t[MAXN], tm, mp[MAXN];
vector<pair<int, int>>	adj[MAXN], vec[MAXN];

void dfs(int v = 0, int p = -1){
	mp[tm] = v;
	s_t[v] = tm++;
	for (auto e:adj[v])
		if (e.F^p)
			depth[e.F] = depth[v] + e.S, dfs(e.F, v);
	f_t[v] = tm;
}

void plant(int v = 1, int b = 0, int e = n){
	if (e - b == 1){
		sm[v] = depth[mp[b]] % MOD;
		weed[v] = sm[v] * sm[v] % MOD;
		return;
	}

	int mid = b + e >> 1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	sm[v] = (sm[v<<1] + sm[v<<1^1]) % MOD;
	weed[v] = (weed[v<<1] + weed[v<<1^1]) % MOD;
}

void absorb(int v, int b, int e, int mid){
	if (!nut[v])	return;

	nut[v<<1] = (nut[v<<1] + nut[v]) % MOD;
	nut[v<<1^1] = (nut[v<<1^1] + nut[v]) % MOD;
	
	weed[v<<1] = (weed[v<<1] + ll(mid - b) * nut[v] % MOD * nut[v] % MOD + MOD) % MOD;
	weed[v<<1] = (weed[v<<1] + sm[v<<1] * 2ll % MOD * nut[v] % MOD + MOD) % MOD;

	weed[v<<1^1] = (weed[v<<1^1] + ll(e - mid) * nut[v] % MOD * nut[v] % MOD + MOD) % MOD;
	weed[v<<1^1] = (weed[v<<1^1] + sm[v<<1^1] * 2ll % MOD * nut[v] % MOD + MOD) % MOD;
	
	sm[v<<1] = (sm[v<<1] + ll(mid - b) * nut[v] % MOD + MOD) % MOD;
	sm[v<<1^1] = (sm[v<<1^1] + ll(e - mid) * nut[v] % MOD + MOD) % MOD;
	nut[v] = 0;
}

void water(int v, int b, int e, int l, int r, ll val){
	if (l <= b && e <= r){
		weed[v] = (weed[v] + ll(e - b) * val % MOD * val % MOD + MOD) % MOD;
		weed[v] = (weed[v] + sm[v] * 2ll % MOD * val % MOD + MOD) % MOD;
		sm[v] = (sm[v] + ll(e - b) * val % MOD + MOD) % MOD;
		nut[v] = (nut[v] + val) % MOD;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	sm[v] = (sm[v<<1] + sm[v<<1^1]) % MOD;
	weed[v] = (weed[v<<1] + weed[v<<1^1]) % MOD;
}

ll smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return 0;

	int mid = b + e >> 1;
	absorb(v, b, e, mid);
	return (smoke(v<<1, b, mid, l, r) + smoke(v<<1^1, mid, e, l, r)) % MOD;
}

void go(int v, int p = -1){
	for (auto g:vec[v]){
		ll temp = smoke(1, 0, n, s_t[g.F], f_t[g.F]);
		ans[g.S] = (temp - (weed[1] - temp + MOD) % MOD + MOD) % MOD;
	}

	for (auto e:adj[v])
		if (e.F^p){
			int u = e.F;
			water(1, 0, n, s_t[u], f_t[u], -e.S);
			water(1, 0, n, 0, s_t[u], e.S);
			water(1, 0, n, f_t[u], n, e.S);

			go(u, v);

			water(1, 0, n, s_t[u], f_t[u], e.S);
			water(1, 0, n, 0, s_t[u], -e.S);
			water(1, 0, n, f_t[u], n, -e.S);
		}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	scanf("%d %d %d", &a, &b, &c), a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs();
	plant();

	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		int a, b;	scanf("%d %d", &a, &b), a--, b--;
		vec[a].push_back({b, i});
	}
	go(0);

	for (int i = 0; i < q; i++)
		printf("%lld\n", ans[i]);
	return 0;
}