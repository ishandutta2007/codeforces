#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll MOD = 1e9 + 7;

ll n, q, par[MAXN], s_t[MAXN], f_t[MAXN], tm, que[MAXN];
ll sum[4 * MAXN], mul[4 * MAXN], val[MAXN], lz[4 * MAXN];
vector<ll>	adj[MAXN];

void dfs(ll v){
	s_t[v] = tm++;
	for (ll u:adj[v])	dfs(u);
	f_t[v] = tm;
}

ll pw(ll a, ll b){
	ll ret = 1;
	while (b){
		if (b & 1)
			ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return	ret;
}

void plant(ll v, ll b, ll e){
	lz[v] = 1;
	if (e - b == 1){
		if (b == 0)	
			sum[v] = val[0], mul[v] = 1;
		return;
	}		

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	sum[v] = (sum[v<<1] + sum[v<<1^1]) % MOD;
}

void absorb(ll v){
	mul[v<<1] = (mul[v<<1] * lz[v]) % MOD;
	mul[v<<1^1] = (mul[v<<1^1] * lz[v]) % MOD;
	sum[v<<1] = (sum[v<<1] * lz[v]) % MOD;
	sum[v<<1^1] = (sum[v<<1^1] * lz[v]) % MOD;
	lz[v<<1] = (lz[v<<1] * lz[v]) % MOD;
	lz[v<<1^1] = (lz[v<<1^1] * lz[v]) % MOD;
	lz[v] = 1;
}

void asg(ll v, ll b, ll e, ll x, ll sm, ll ml){
	if (e - b == 1){
		sum[v] = (sm * ml) % MOD, mul[v] = ml;
		return;
	}

	ll mid = (b + e)/ 2;
	absorb(v);
	if (x < mid)
		asg(v<<1, b, mid, x, sm, ml);
	else
		asg(v<<1^1, mid, e, x, sm, ml);
	sum[v] = (sum[v<<1] + sum[v<<1^1]) % MOD;
}

void water(ll v, ll b, ll e, ll l, ll r, ll m){
	if (l <= b && e <= r){
		lz[v] = (lz[v] * m) % MOD;
		sum[v] = (sum[v] * m) % MOD;
		mul[v] = (mul[v] * m) % MOD;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	absorb(v);
	water(v<<1, b, mid, l, r, m);
	water(v<<1^1, mid, e, l, r, m);
	sum[v] = (sum[v<<1] + sum[v<<1^1]) % MOD;
}

ll get_mul(ll v, ll b, ll e, ll x){
	if (e - b == 1)	
		return	mul[v];

	ll mid = (b + e)/ 2;
	absorb(v);
	if (x < mid)
		return	get_mul(v<<1, b, mid, x);
	return	get_mul(v<<1^1, mid, e, x);
}

ll get_sum(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	sum[v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	absorb(v);
	return	(get_sum(v<<1, b, mid, l, r) + get_sum(v<<1^1, mid, e, l, r)) % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> val[n++] >> q;
	for (ll i = 0; i < q; i++){
		ll type;	cin >> type;
		if (type == 1){
			cin >> par[n] >> val[n];	par[n]--;
			par[n] = par[n];
			adj[par[n]].push_back(n);	n++;
		}
		else	cin >> que[i];
	}
	dfs(0);
	plant(1, 0, n);
	for (ll i = 0; i < n; i++)	adj[i].clear();
	
	ll c = 1;
	for (ll i = 0; i < q; i++){
		if (que[i] == 0){
			ll tt = adj[par[c]].size();
			ll m = ((tt + 2) * pw(tt + 1, MOD - 2)) % MOD;
			water(1, 0, n, s_t[par[c]], f_t[par[c]], m);
			asg(1, 0, n, s_t[c], val[c], get_mul(1, 0, n, s_t[par[c]]));
			adj[par[c]].push_back(c);	c++;
		}
		else{
			ll v = que[i] - 1;
			if (v == 0)
				cout << get_sum(1, 0, n, s_t[v], f_t[v]) << "\n";
			else
				cout << (get_sum(1, 0, n, s_t[v], f_t[v]) * pw(get_mul(1, 0, n, s_t[par[v]]), MOD - 2)) % MOD << "\n";
		}
	}
	return	0;
}