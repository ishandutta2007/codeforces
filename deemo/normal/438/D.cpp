#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 40;

ll n, q;
ll vec[MAXN];
ll maxi[4 * MAXN], sum[4 * MAXN];

void build(ll v, ll b, ll e){
	if (e - b == 1){
		maxi[v] = sum[v] = vec[b];
		return;
	}	

	ll mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	maxi[v] = max(maxi[v<<1], maxi[v<<1^1]);
	sum[v] = sum[v<<1] + sum[v<<1^1];
}

void update(ll v, ll b, ll e, ll l, ll r, ll x){
	if (r <= b || e <= l)	return;
	if (maxi[v] < x)	return;

	if (e - b == 1){
		sum[v] %= x;
		maxi[v] = sum[v];
		return;
	}

	ll mid = (b + e)/ 2;
	update(v<<1, b, mid, l, r, x);
	update(v<<1^1, mid, e, l, r, x);
	maxi[v] = max(maxi[v<<1], maxi[v<<1^1]);
	sum[v] = sum[v<<1] + sum[v<<1^1];
}

void modify(ll v, ll b, ll e, ll x, ll val){
	if (e - b == 1){
		maxi[v] = sum[v] = val;
		return;
	}
	
	ll mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val);
	else
		modify(v<<1^1, mid, e, x, val);

	maxi[v] = max(maxi[v<<1], maxi[v<<1^1]);
	sum[v] = sum[v<<1] + sum[v<<1^1];
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	sum[v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	return	get(v<<1, b, mid, l, r) + get(v<<1^1, mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)
		cin >> vec[i];
	build(1, 0, n);

	while (q--){
		ll type;	cin >> type;
		if (type == 1){
			ll l, r;	cin >> l >> r;	l--;
			cout << get(1, 0, n, l, r) << "\n";
		}
		else if (type == 2){
			ll l, r, x;	cin >> l >> r >> x;	l--;
			update(1, 0, n, l, r, x);
		}
		else{
			ll x, val;	cin >> x >> val;	x--;
			modify(1, 0, n, x, val);
		}
	}
	return 0;
}