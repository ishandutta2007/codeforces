#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 3e5 + 10;
const ll INF = 8e18;

ll n, x[MAXN], y[MAXN], m[MAXN], p[MAXN], r[MAXN], d[MAXN], q[MAXN], sec[MAXN], mp[MAXN];
pair<ll, ll>	weed[4 * MAXN];

ll dis(ll ind){
	ll temp = (x[ind] - x[0]) * (x[ind] - x[0]) + (y[ind] - y[0]) * (y[ind] - y[0]);
	ll b = 0, e = 3e9, ret = 3e9;
	while (b <= e){
		ll mid = (b + e)/ 2;
		if (mid * mid >= temp)
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	return ret;
}

bool cmp(ll u, ll v){return d[u] < d[v];}
bool cmp2(ll v, ll val){return d[v] < val;}

void plant(ll v, ll b, ll e){
	if (e - b == 1){
		if (b)
			weed[v] = {m[sec[b]], b};
		else
			weed[v] = {INF, b};
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

void burn(ll v, ll b, ll e, ll pos){
	if (e - b == 1){
		weed[v] = {INF, b};
		return;
	}

	ll mid = (b + e)/ 2;
	if (pos < mid)
		burn(v<<1, b, mid, pos);
	else
		burn(v<<1^1, mid, e, pos);
	weed[v] = min(weed[v<<1], weed[v<<1^1]);
}

pair<ll, ll>	smoke(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return weed[v];
	if (r <= b || e <= l)	return {INF, -1};

	ll mid = (b + e)/ 2;
	return min(smoke(v<<1, b, mid, l, r), smoke(v<<1^1, mid, e, l, r));
}

int get(ll z){
	int b = 1, e = n, ret = 0;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (d[sec[mid - 1]] <= z)
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	return ret;
}

int main(){
	{
		ll xx, yy, pp, rr;	
		scanf("%I64d %I64d %I64d %I64d %I64d", &xx, &yy, &pp, &rr, &n), n++;
		x[0] = xx, y[0] = yy, p[0] = pp, r[0] = rr;
		for (ll i = 1; i < n; i++)
			scanf("%I64d %I64d %I64d %I64d %I64d", &x[i], &y[i], &m[i], &p[i], &r[i]), d[i] = dis(i);
		iota(sec, sec + n, 0);
		sort(sec, sec + n, cmp);
		for (ll i = 0; i < n; i++)
			mp[sec[i]] = i;
	}
	
	{
		plant(1, 0, n);
		ll h = 0, t = 0;
		q[t++] = 0;
		while (h < t){
			ll v = q[h++];
			//ll ri = lower_bound(sec, sec + n, r[v] + 1, cmp2) - sec; 
			ll ri = get(r[v]);
			
			auto mn = smoke(1, 0, n, 0, ri);
			while (mn.F <= p[v]){
				q[t++] = sec[mn.S];
				burn(1, 0, n, mn.S);
				mn = smoke(1, 0, n, 0, ri);
			}
		}
		
		printf("%I64d\n", t-1);
	}
	return 0;
}