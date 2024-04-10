#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;

ll n, cc[MAXN], arr[MAXN], fst[MAXN], seed[MAXN];
vector<ll>	dvs[MAXN];
ll ans, weed[4 * MAXN], nut[4 * MAXN];

void plant(ll v = 1, ll b = 0, ll e = n){
	if (e - b == 1){
		weed[v] = seed[b];
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = weed[v<<1] + weed[v<<1^1];
}

void absorb(ll v, ll b, ll e, ll mid){
	if (nut[v]){
		nut[v<<1] = nut[v<<1^1] = nut[v];
		weed[v<<1] = (mid - b) * nut[v];
		weed[v<<1^1] = (e - mid) * nut[v];
		nut[v] = 0;
	}
}

ll smoke(ll v, ll b, ll e, ll l, ll r){
	if (r - l < 1)	return 0;
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return 0;

	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	return smoke(v<<1, b, mid, l, r) + smoke(v<<1^1, mid, e, l, r);
}

void water(ll v, ll b, ll e, ll l, ll r, ll x){
	if (r - l < 1)	return;
	if (l <= b && e <= r){
		weed[v] = (e - b) * x;
		nut[v] = x;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	water(v<<1, b, mid, l, r, x);
	water(v<<1^1, mid, e, l, r, x);
	weed[v] = weed[v<<1] + weed[v<<1^1];
}

ll gmax(ll v, ll b, ll e, ll pos){
	if (e - b == 1)	return weed[v];
	
	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	if (pos < mid)
		return gmax(v<<1, b, mid, pos);
	return gmax(v<<1^1, mid, e, pos);
}

int main(){
	for (ll i = 1; i < MAXN; i++)
		for (ll j = i; j < MAXN; j += i)
			cc[j]++;
	for (ll j = 1; j < MAXN; j++)	dvs[j].resize(cc[j]), cc[j] = 0;
	for (ll i = 1; i < MAXN; i++)
		for (ll j = i; j < MAXN; j += i)
			dvs[j][cc[j]++] = i;

	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &arr[i]);
	//

	memset(cc, 0, sizeof(cc));
	memset(fst, -1, sizeof(fst));
	ll mx = 0;
	for (ll i = 0; i < n; i++){
		ll x = arr[i];
		for (ll u:dvs[x]){
			cc[u]++;
			if (cc[u] == 1)
				fst[u] = i;
			if (cc[u] == 2)
				mx = max(mx, u);
		}
		seed[i] = mx;
	}
	plant();

	memset(cc, 0, sizeof(cc));
	mx = 0;
	for (ll i = n - 1; i >= 0; i--){
		ans += smoke(1, 0, n, 0, i) + mx;
		
		ll x = arr[i];
		for (ll u:dvs[x]){
			cc[u]++;
			if (cc[u] == 2)	mx = max(mx, u);
			if (~fst[u]){
				ll b = fst[u], e = i - 1, ret = -1;
				while (b <= e){
					ll mid = (b + e)/ 2;
					if (gmax(1, 0, n, mid) < u)
						ret = mid, b = mid + 1;
					else
						e = mid - 1;
				}
				if (~ret)
					water(1, 0, n, fst[u], ret + 1, u);
				fst[u] = -1;
			}
		}
		
		ll b = 0, e = i, ret = -1;
		while (b <= e){
			ll mid = (b + e)/ 2;
			if (gmax(1, 0, n, mid) <= mx)
				ret = mid, b = mid + 1;
			else
				e = mid - 1;
		}
		if (~ret)	
			water(1, 0, n, 0, ret+1, mx);
	}
	
	printf("%I64d\n", ans);
	return 0;
}