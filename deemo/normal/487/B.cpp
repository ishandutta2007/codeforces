#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll INF = 1e9 + 5;

ll n, s, k;
ll vec[MAXN];
ll d[MAXN];
ll maxi[4 * MAXN], mini[4 * MAXN], dm[4 * MAXN];

void build(ll v, ll b, ll e){
	if (e - b == 1){
		maxi[v] = mini[v] = vec[b];
		dm[v] = d[b];
		return;
	}

	ll mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	mini[v] = min(mini[v<<1], mini[v<<1^1]);
	maxi[v] = max(maxi[v<<1], maxi[v<<1^1]);
	dm[v] = min(dm[v<<1], dm[v<<1^1]);
}

ll get_min(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)
		return	mini[v];
	if (r <= b || e <= l)
		return	INF;

	ll mid = (b + e)/ 2;
	return	min(get_min(v<<1, b, mid, l, r), get_min(v<<1^1, mid, e, l, r));
}

ll get_max(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)
		return	maxi[v];
	if (r <= b || e <= l)
		return	-INF;

	ll mid = (b + e)/ 2;
	return	max(get_max(v<<1, b, mid, l, r), get_max(v<<1^1, mid, e, l, r));
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (l < 0)	return	0;
	if (l <= b && e <= r)
		return	dm[v];
	if (r <= b || e <= l)
		return	INF;

	ll mid = (b + e)/ 2;
	return	min(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void modify(ll v, ll b, ll e, ll x, ll val){
	if (e - b == 1){
		dm[v] = val;
		return;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val);
	else
		modify(v<<1^1, mid, e, x, val);
	dm[v] = min(dm[v<<1], dm[v<<1^1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> k;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	fill(d, d + MAXN, INF);
	build(1, 0, n);

	ll last = 0;
	for (ll i = 0; i < n; i++){
		while (last < i && (get_min(1, 0, n, last, i + 1) < vec[i] - s || get_max(1, 0, n, last, i + 1) > vec[i] + s))	last++;
		if (i + 1 - last >= k){
			ll l = last - 1, r = i - k + 1;
			d[i] = get(1, 0, n, l, r) + 1;
			modify(1, 0, n, i, d[i]);
		}		
	}

	if (d[n - 1] >= INF)
		d[n - 1] = -1;
	cout << d[n - 1] << endl;
	return 0;
}