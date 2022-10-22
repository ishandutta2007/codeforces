#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<numeric>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll MAXH = 1e4 + 10;

ll n, k, h, w[MAXN], vv[MAXN], vec[MAXN], ans[MAXN];

bool cmp(ll u, ll v){
	if (w[u] != w[v])
		return w[u] < w[v];
	return	vv[u] < vv[v];
}

bool ok(ld mid){
	ll x = h, cur = 0;
	for (ll i = 0; i < n; i++){
		ld t = ld(x)/ ld(vv[vec[i]]);
		if (t <= mid)
			x += h, ans[cur++] = vec[i];
		if (cur >= k)	break;
	}
	return	cur >= k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> h;
	for (ll i = 0; i < n; i++)	cin >> w[i];
	for (ll i = 0; i < n; i++)	cin >> vv[i];
	iota(vec, vec + n, 0);
	sort(vec, vec + n, cmp);
	
	ld b = 0, e = 1e18;
	for (int i = 0; i < 400; i++){
		ld mid = (b + e)/ ld(2);
		if (ok(mid))
			e = mid;
		else
			b = mid;
	}
	ok(e);
	for (ll i = 0; i < k; i++)
		cout << ans[i] + 1 << " ";
	cout << "\n";
	return	0;
}