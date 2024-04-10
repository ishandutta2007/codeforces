//It's Deemo now :)

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll LOG = 20;

ll n, q;
ll d[MAXN], h[MAXN];
ll seg[4 * MAXN], ss[LOG][4 * MAXN], maxi[LOG][4 * MAXN];
ll le[MAXN], ri[MAXN];

void build(ll v, ll b, ll e, ll de = 0){
	if (e - b == 1){
		seg[v] = h[b];
		return;
	}		

	ll mid = (b + e)/ 2;
	build(v<<1, b, mid, de + 1);
	build(v<<1^1, mid, e, de + 1);
	
	maxi[de][mid - 1] = h[mid - 1];
	ll sum = d[mid - 2];
	for (ll i = mid - 2; i >= b; i--){
		maxi[de][i] = max(h[i] + sum, maxi[de][i + 1]);
		sum += (i == b?0:d[i - 1]);
	}

	maxi[de][mid] = h[mid];
	sum = d[mid];
	for (ll i = mid + 1; i < e; i++){
		maxi[de][i] = max(sum + h[i], maxi[de][i - 1]);
		sum += d[i];
	}

	seg[v] = max(seg[v<<1], seg[v<<1^1]);
	seg[v] = max(seg[v], maxi[de][b] + d[mid - 1] + maxi[de][e - 1]);
}

ll get(ll v, ll b, ll e, ll l, ll r, ll de = 0){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	ll f = get(v<<1, b, mid, l, r, de + 1), g = get(v<<1^1, mid, e, l, r, de + 1);

	if (g == 0)	return	f;
	if (f == 0)	return	g;
	ll ret = max(f, g);
	
	l = max(l, b);
	r = min(r - 1, e - 1);
	return	max(ret, maxi[de][l] + maxi[de][r] + d[mid - 1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)	cin >> d[i];
	for (ll i = 0; i < n; i++)	cin >> h[i], h[i] *= 2;
	
	le[0] = h[0];
	ll sum = d[0];
	for (ll i = 1; i < n; i++){
		le[i] = max(le[i - 1], h[i] + sum);
		sum += d[i];
	}

	ri[n - 1] = h[n - 1];
	sum = d[n - 2];
	for (ll i = n - 2; i >= 0; i--)
		ri[i] = max(ri[i + 1], h[i] + sum), sum += (i == 0?0:d[i - 1]);
	build(1, 0, n);

	while (q--){
		ll l, r;	cin >> l >> r;	l--;
		if (l >= r)
			cout << get(1, 0, n, r, l) << "\n";
		else{
			ll f = 0, g = 0;
			if (l != 0)	f = get(1, 0, n, 0, l);
			if (r != n)	g = get(1, 0, n, r, n);
			if (f == 0)
				cout << g << "\n";
			else if (g == 0)
				cout << f << "\n";
			else
				cout << max(max(f, g), le[l - 1] + ri[r] + d[n - 1]) << "\n";
		}
	}
	return 0;
}