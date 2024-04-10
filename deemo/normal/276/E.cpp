#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll MAX = 1e5 + 20;

ll n, q;
vector<ll>	adj[MAXN];
ll depth[MAXN], s_t[MAXN], f_t[MAXN], sz;
ll fen[MAX + 20];
ll sum[4 * MAX], lazy[4 * MAX];

void build(ll v, ll p = -1, ll de = 0){
	depth[v] = de;
	s_t[v] = sz++;

	for (ll u:adj[v])
		if (u != p)
			build(u, v, de + 1);
	f_t[v] = sz;
}

void add(ll v, ll val){
	for (v++; v < MAX; v += v & (-v))
		fen[v] += val;
}

ll get(ll v){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void shift(ll v, ll b, ll e, ll mid){
	if (lazy[v] == 0)	return;

	sum[v<<1] += (mid - b) * lazy[v];
	sum[v<<1^1] += (e - mid) * lazy[v];

	lazy[v<<1] += lazy[v];
	lazy[v<<1^1] += lazy[v];
	lazy[v] = 0;
}

void pl(ll v, ll b, ll e, ll l, ll r, ll val){
	if (l <= b && e <= r){
		sum[v] += (e - b) * val;
		lazy[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	pl(v<<1, b, mid, l, r, val);
	pl(v<<1^1, mid, e, l, r, val);
}

ll sm(ll v, ll b, ll e, ll u){
	if (e - b == 1)
		return	sum[v];
	
	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	if (u < mid)
		return	sm(v<<1, b, mid, u);
	return	sm(v<<1^1, mid, e, u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n - 1; i++){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	build(0);

	while (q--){
		ll type;	cin >> type;
		if (type == 0){
			ll v, x, d;	cin >> v >> x >> d;	v--;
			if (v == 0){
				add(d, x);
				continue;
			}		
				
			ll b = s_t[v], e = s_t[v];
			b -= min(depth[v] - 1, d);
			e = min(e + d + 1, f_t[v]);
			pl(1, 0, n, b, e, x);

			if (depth[v] <= d){
				ll z = d - depth[v];
				add(z, x);
				if (z)	
					pl(1, 0, n, b, min(e, b + z), -x);
			}
		}
		else{
			ll v;	cin >> v;	v--;
			ll ans = sm(1, 0, n, s_t[v]);
			ans += get(MAX - 1) - get(depth[v]);
			cout << ans << "\n";
		}
	}
	return 0;
}