#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 2e5 + 10;
const ll INF = 1e8;
const ll C = 1e9;

ll n, k, d, arr[MAXN];
ll prv[MAXN];
ll weed[4 * MAXN], nut[4 * MAXN];
map<ll, ll>	mp;
pair<ll, ll>	f[MAXN], g[MAXN];

void plant(ll v, ll b, ll e){
	weed[v] = INF;
	if (e - b == 1)	return;

	ll mid = b+e>>1;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
}

void absorb(ll v){
	if (!nut[v])	return;
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	weed[v<<1] += nut[v];
	weed[v<<1^1] += nut[v];
	nut[v] = 0;
}

void modify(ll v, ll b, ll e, ll pos, ll val){
	if (e - b == 1){
		weed[v] = val;
		return;
	}

	ll mid = b+e>>1;
	absorb(v);
	if (pos < mid)
		modify(v<<1, b, mid, pos, val);
	else
		modify(v<<1^1, mid, e, pos, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void water(ll v, ll b, ll e, ll l, ll r, ll val){
	if (l <= b && e <= r){
		weed[v] += val;
		nut[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = b+e>>1;
	absorb(v);
	water(v<<1, b, mid, l, r, val);
	water(v<<1^1, mid, e, l, r, val);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

ll smoke(ll v, ll b, ll e){
	if (e - b == 1)	
		return b;

	ll mid = b+e>>1;
	absorb(v);
	if (weed[v<<1] <= k)
		return smoke(v<<1, b, mid);
	return smoke(v<<1^1, mid, e);
}

int main(){
	scanf("%I64d %I64d %I64d", &n, &k, &d);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &arr[i]), arr[i] += C;
	
	if (!d){
		ll l = 0, r = 0;
		ll tl = 0, tr = 0;
		for (ll i = 0; i < n; i++){
			if (i && arr[i] ^ arr[i - 1])	tl = tr = i;
			
			tr++;
			if (r - l < tr - tl)
				l = tl, r = tr;
		}
		printf("%I64d %I64d\n", l + 1, r);
	}

	else{
		for (ll i = 0; i < n; i++){
			if (mp.count(arr[i]))
				prv[i] = mp[arr[i]] + 1;
			else
				prv[i] = 0;
	
			mp[arr[i]] = i;
		}
		mp.clear();

		ll l = 0, r = 0;
		ll tl = 0, hmin = 0, tmin = 0, hmax = 0, tmax = 0;
		plant(1, 0, n);
		for (ll i = 0; i < n; i++){
			if (tl < prv[i]){
				for (; tl < prv[i]; tl++)
					modify(1, 0, n, tl, INF);
				
				while (hmin < tmin && f[hmin].S <= tl)	hmin++;
				while (hmax < tmax && g[hmax].S <= tl)	hmax++;
			}

			if (i && arr[i - 1] % d ^ arr[i] % d){
				water(1, 0, n, tl, i, INF);
				tl = i, hmin = tmin, hmax = tmax;
			}

			//Next Chapter->
			ll v = arr[i]/d;
			while (hmin < tmin && f[tmin - 1].F > v)
				tmin--, water(1, 0, n, hmin==tmin?tl:f[tmin-1].S, f[tmin].S, f[tmin].F - v);
			while (hmax < tmax && g[tmax - 1].F < v)
				tmax--, water(1, 0, n, hmax==tmax?tl:g[tmax-1].S, g[tmax].S, v - g[tmax].F);
	
			f[tmin++] = {v, i + 1};
			g[tmax++] = {v, i + 1};
			
			modify(1, 0, n, i, 1);
			water(1, 0, n, tl, i + 1, -1);
			ll x = smoke(1, 0, n);
			if (i + 1 - x > r - l)
				l = x, r = i + 1;
		}
		printf("%I64d %I64d\n", l + 1, r);
	}
	return 0;
}