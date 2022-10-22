//Darker than the Blood, Higher than the Sun..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e5 + 10;

ll n, nxt[MAXN], d[MAXN];
pair<ll, ll>	weed[4*MAXN];
pair<ll, ll>	q[MAXN];

void plant(ll v=1, ll b=0, ll e=n){
	if (e - b == 1){
		weed[v] = {nxt[b], b};
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

pair<ll, ll>	venom(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {0, 0};
	
	ll mid = (b + e)/ 2;
	return max(venom(v<<1, b, mid, l, r), venom(v<<1^1, mid, e, l, r));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n-1; i++)
		cin >> nxt[i];
	nxt[n - 1] = n;
	
	plant();
	ll ans = 0;
	for (ll i = n - 2; i >= 0; i--){
		d[i] = n-i-1;
		auto pos = venom(1, 0, n, i+1, nxt[i]);
		if (pos.first > nxt[i]){
			d[i] -= nxt[i] - pos.second - 1;
			d[i] += d[pos.second];
		}
		ans += d[i];
	}
	cout << ans << "\n";
	return 0;
}