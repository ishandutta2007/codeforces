//Dear god..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

#define Query pair<pair<ll, ll>, ll>
#define left first.first
#define right first.second
#define id second

const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 10;
const ll MAXVAL = 1e6 + 10;

ll n, vec[MAXN], q, pos[MAXVAL];
Query sec[MAXN];
vector<ll>	pr[MAXVAL];
ll ans[MAXN], aa[4 * MAXN], bb[4 * MAXN], p[MAXN];

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

void init(){
	for (ll i = 2; i < MAXVAL; i++)
		if (pr[i].empty())
			for (ll j = i; j < MAXVAL; j += i)
				pr[j].push_back(i);
	p[0] = 1;
	for (ll i = 0; i < n; i++)
		p[i + 1] = (p[i] * vec[i]) % MOD;
}

bool cmp(Query a, Query b){
	if (a.right != b.right)
		return	a.right < b.right;
	return	a.left < b.left;
}

void div(ll v, ll b, ll e, ll x, ll val){
	if (e - b == 1){
		aa[v]/=val - 1;
		bb[v]/=val;
		return;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		div(v<<1, b, mid, x, val);
	else
		div(v<<1^1, mid, e, x, val);
	aa[v] = (aa[v<<1] * aa[v<<1^1]) % MOD;
	bb[v] = (bb[v<<1] * bb[v<<1^1]) % MOD;
}

void mul(ll v, ll b, ll e, ll x, ll val){
	if (e - b == 1){
		aa[v]*=val-1;
		bb[v]*=val;
		return;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		mul(v<<1, b, mid, x, val);
	else
		mul(v<<1^1, mid, e, x, val);
	aa[v] = (aa[v<<1] * aa[v<<1^1]) % MOD;
	bb[v] = (bb[v<<1] * bb[v<<1^1]) % MOD;
}

pair<ll, ll>	get(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	{aa[v], bb[v]};
	if (r <= b || e <= l)	return	{1, 1};

	ll mid = (b + e)/ 2;
	pair<ll, ll>	f = get(v<<1, b, mid, l, r);
	pair<ll, ll>	g = get(v<<1^1, mid, e, l, r);
	return	{(f.first * g.first) % MOD, (f.second * g.second) % MOD};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> vec[i];
	init();
	cin >> q;	for (ll i = 0; i < q; i++)	cin >> sec[i].left >> sec[i].right, sec[i].id = i, sec[i].left--;
	sort(sec, sec + q, cmp);
	
	memset(pos, -1, sizeof(pos));
	fill(aa, aa + 4 * MAXN, 1);
	fill(bb, bb + 4 * MAXN, 1);
	ll b = 0;
	for (ll i = 0; i < n; i++){
		ll x = vec[i];
		for (ll u:pr[x]){
			if (pos[u] != -1)
				div(1, 0, n, pos[u], u);
			pos[u] = i;
			mul(1, 0, n, i, u);
		}
	
		while (b < q && sec[b].right == i + 1){
			pair<ll, ll>	y = get(1, 0, n, sec[b].left, sec[b].right);
			ans[sec[b].id] = (p[sec[b].right] * pw(p[sec[b].left], MOD - 2)) % MOD;
			ans[sec[b].id] = (ans[sec[b].id] * y.first) % MOD;
			ans[sec[b].id] = (ans[sec[b].id] * pw(y.second, MOD - 2)) % MOD;
			b++;
		}
	}

	for (ll i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return	0;
}