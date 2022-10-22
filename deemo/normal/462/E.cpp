#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, q, le, ri, weed[4 * MAXN];
bool dir;

void plant(ll v, ll b, ll e){
	if (e - b == 1){
		weed[v] = 1;
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1] + weed[v<<1^1];
}

void water(ll v, ll b, ll e, ll x, ll val){
	if (e - b == 1){
		weed[v] += val;
		return;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		water(v<<1, b, mid, x, val);
	else
		water(v<<1^1, mid, e, x, val);
	weed[v] = weed[v<<1] + weed[v<<1^1];
}

ll smoke(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	return	smoke(v<<1, b, mid, l, r) + smoke(v<<1^1, mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	le = 0, ri = n;
	plant(1, 0, n);

	while (q--){
		ll type;	cin >> type;
		if (type == 1){
			ll x;	cin >> x;

			if (dir)
				x = (ri - le) - x;
			if (!dir && 2 * x > ri - le)
				dir = !dir;
			else if (dir && 2 * x < ri - le)
				dir = !dir;
		
			x += le;
			if (!dir){
				for (ll i = x; i < x + (x - le); i++)
					water(1, 0, n, i, smoke(1, 0, n, x - (i - x + 1), x - (i - x)));
				le = x;
			}
			else{
				for (ll i = x - 1; i >= x - (ri - x); i--)
					water(1, 0, n, i, smoke(1, 0, n, x + (x - 1 - i), x + (x - i)));
				ri = x;
			}
		}
		else{
			ll l, r;	cin >> l >> r;	
			l += le;	r += le;
			if (!dir)
				cout << smoke(1, 0, n, l, r) << "\n";
			else
				cout << smoke(1, 0, n, le + (ri - r), le + (ri - l)) << "\n";
		}
	}
	return	0;
}