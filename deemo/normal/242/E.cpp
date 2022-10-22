#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll C = 22;

ll n, q, vec[MAXN];
bool lz[C][4 * MAXN];
ll seg[C][4 * MAXN];

void build(ll v, ll b, ll e, ll c){
	if (e - b == 1){
		seg[c][v] = (vec[b] >> c) & 1;
		return;
	}
	
	ll mid = (b + e)/ 2;
	build(v<<1, b, mid, c);
	build(v<<1^1, mid, e, c);
	seg[c][v] = seg[c][v<<1] + seg[c][v<<1^1];
}

void shift(ll v, ll b, ll e, ll mid, ll c){
	if (!lz[c][v])	return;
	lz[c][v<<1] = !lz[c][v<<1];
	lz[c][v<<1^1] = !lz[c][v<<1^1];
	seg[c][v<<1] = (mid - b) - seg[c][v<<1];
	seg[c][v<<1^1] = (e - mid) - seg[c][v<<1^1];
	lz[c][v] = 0;
}

void modify(ll v, ll b, ll e, ll l, ll r, ll c){
	if (l <= b && e <= r){
		lz[c][v] = !lz[c][v];
		seg[c][v] = e - b - seg[c][v];
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	shift(v, b, e, mid, c);
	modify(v<<1, b, mid, l, r, c);
	modify(v<<1^1, mid, e, l, r, c);
	seg[c][v] = seg[c][v<<1] + seg[c][v<<1^1];
}

ll get(ll v, ll b, ll e, ll l, ll r, ll c){
	if (l <= b && e <= r)	return	seg[c][v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	shift(v, b, e, mid, c);
	return	get(v<<1, b, mid, l, r, c) + get(v<<1^1, mid, e, l, r, c);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	for (ll i = 0; i < C; i++)
		build(1, 0, n, i);

	cin >> q;
	while (q--){
		ll type, l, r;	cin >> type >> l >> r;	l--;
		if (type == 1){
			ll ret = 0;
			for (ll i = 0; i < C; i++)
				ret += get(1, 0, n, l, r, i) * (ll(1) << ll(i));
			cout << ret << "\n";
		}
		else{
			ll x;	cin >> x;
			for (ll i = 0; i < C; i++)
				if ((x >> i) & 1)
					modify(1, 0, n, l, r, i);
		}		
	}		
	return 0;
}