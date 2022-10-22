#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 3e5 + 30;

ll n, q;
vector<ll>	adj[MAXN];
ll mini[4 * MAXN];
ll depth[MAXN], s_t[MAXN], f_t[MAXN], sz;
ll d[4 * MAXN], c[4 * MAXN];

void build(ll v, ll de = 0){
	depth[sz] = de;
	s_t[v] = sz++;
	for (ll u:adj[v])
		build(u, de + 1);
	f_t[v] = sz;
}

void seg_build(ll v, ll b, ll e){
	if (e - b == 1){
		mini[v] = depth[b];
		return;
	}

	ll mid = (b + e)/ 2;
	seg_build(v<<1, b, mid);
	seg_build(v<<1^1, mid, e);
	mini[v] = min(mini[v<<1], mini[v<<1^1]);
}

void shift(ll v){
	ll f = ((mini[v<<1] - mini[v]) * c[v]) % MOD;
	ll g = ((mini[v<<1^1] - mini[v]) * c[v]) % MOD;

	d[v<<1] = (d[v<<1] + d[v] + MOD - f) % MOD;
	d[v<<1^1] = (d[v<<1^1] + d[v] + MOD - g) % MOD;

	c[v<<1] = (c[v<<1] + c[v]) % MOD;
	c[v<<1^1] = (c[v<<1^1] + c[v]) % MOD;

	d[v] = c[v] = 0;
}

void add(ll v, ll b, ll e, ll l, ll r, ll x, ll k, ll ss){
	if (l <= b && e <= r){
		x = (x + MOD - ((mini[v] - ss) * k % MOD)) % MOD;
		d[v] = (d[v] + x) % MOD, c[v] = (c[v] + k) % MOD;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	shift(v);
	
	add(v<<1, b, mid, l, r, x, k, ss);
	add(v<<1^1, mid, e, l, r, x, k, ss);
}

ll get(ll v, ll b, ll e, ll x){
	if (e - b == 1)		return	d[v];

	ll mid = (b + e)/ 2;
	shift(v);
	if (x < mid)	
		return	get(v<<1, b, mid, x);
	return	get(v<<1^1, mid, e, x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 1; i < n; i++){
		ll p;	cin >> p;	p--;
		adj[p].push_back(i);
	}
	build(0);
	seg_build(1, 0, n);

	cin >> q;
	while (q--){
		ll type;	cin >> type;
		if (type == 2){
			ll v;	cin >> v;	v--;
			cout << get(1, 0, n, s_t[v]) << "\n";
		}
		else{
			ll v, x, k;	cin >> v >> x >> k;		v--;
			add(1, 0, n, s_t[v], f_t[v], x, k, depth[s_t[v]]);
		}
	}
	return 0;
}