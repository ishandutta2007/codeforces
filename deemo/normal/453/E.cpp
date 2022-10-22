//No longer debatin'..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<set>

using namespace std;

typedef long long ll;
typedef long double ld;

#define A first.first
#define B first.second
#define C second

const ll MAXN = 1e5 + 10;
const ll LOG = 20;

ll n, s[MAXN], mx[MAXN], gen[MAXN], root[MAXN], temp[MAXN], weed[2][LOG * MAXN], le[LOG * MAXN], ri[LOG * MAXN], sz;
pair<pair<ll, ll>, ll>	sec[MAXN], hec[MAXN], gec[MAXN];
set<ll>	st2;
set<pair<pair<ll, ll>, ll>>	st;

pair<ll, ll>	fix(ll a, ll b){
	if (b == 0)	return {(ll)2e9, 1};
	if (a == 0)	return {0, 1};
	ll g = __gcd(a, b);
	return {a/g, b/g};
}

bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b){return a.A * b.B < b.A * a.B;}

ll plant(ll b, ll e){
	ll id = sz++;
	if (e - b == 1){
		weed[0][id] = gen[b];
		return id;
	}

	ll mid = (b + e)/ 2;
	le[id] = plant(b, mid);
	ri[id] = plant(mid, e);
	for (ll w = 0; w < 2; w++)
		weed[w][id] = weed[w][le[id]] + weed[w][ri[id]];
	return id;	
}

ll water(ll pid, ll b, ll e, ll x){
	ll nid = sz++;
	le[nid] = le[pid], ri[nid] = ri[pid];
	if (e - b == 1){
		weed[0][nid] = 0;
		weed[1][nid] = mx[x];
		return nid;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		le[nid] = water(le[nid], b, mid, x);
	else
		ri[nid] = water(ri[nid], mid, e, x);
	for (ll w = 0; w < 2; w++)
		weed[w][nid] = weed[w][le[nid]] + weed[w][ri[nid]];
	return nid;
}

pair<ll, ll> smoke(ll id, ll b, ll e, ll l, ll r){
	if (l <=b && e <= r)	return {weed[0][id], weed[1][id]};
	if (r <= b || e <= l)	return {0, 0};

	ll mid = (b + e)/ 2;
	auto aa = smoke(le[id], b, mid, l, r);
	auto bb = smoke(ri[id], mid, e, l, r);
	aa.first += bb.first;
	aa.second += bb.second;
	return aa;
}	

ll sum(ll l, ll r, ll tm){
	ll pos = upper_bound(sec, sec + n, make_pair(make_pair(tm, 1), -1), cmp) - sec;
	auto x = smoke(root[pos], 0, n, l, r);
	return x.first * tm + x.second;
}

ll get(ll cur, ll l, ll r){
	ll ret = 0;
	{
		auto it = st2.lower_bound(l);
		ll tt = 0;
		while (it != st2.end() && *it < r){
			ll v = *it;
			ret += min(mx[v], s[v] + cur * gen[v]);
			temp[tt++] = *it;
			it++;
		}
		while (tt)	st2.erase(temp[--tt]);
	}

	auto it = st.lower_bound({{l, -1}, -1});	
	ll tt = 0, zz = 0;
	if (it != st.begin())	it--;
	while (it != st.end()){
		ll tl = (*it).A, tr = (*it).B, tm = (*it).C;
		if (tl >= r)	break;
		if (tr <= l){
			it++;
			continue;
		}
		
		hec[zz++] = *it;
		if (tl < l)	gec[tt++] = {{tl, l}, tm};
		if (tr > r)	gec[tt++] = {{r, tr}, tm};
		tl = max(tl, l);
		tr = min(tr, r);
		ret += sum(tl, tr, cur - tm);
		it++;
	}

	while (zz)
		st.erase(hec[--zz]);
	st.insert({{l, r}, cur});
	while (tt)
		st.insert(gec[--tt]);
	return ret;
}	

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)
		scanf("%I64d %I64d %I64d", &s[i], &mx[i], &gen[i]), sec[i] = {fix(mx[i], gen[i]), i};
	sort(sec, sec + n, cmp);
	root[0] = plant(0, n);
	for (ll i = 0; i < n; i++)
		root[i + 1] = water(root[i], 0, n, sec[i].C);
	for (ll i = 0; i < n; i++)
		st2.insert(i);
	
	ll q;	scanf("%I64d", &q);
	while (q--){
		ll t, l, r;	scanf("%I64d %I64d %I64d", &t, &l, &r), l--;	
		printf("%I64d\n", get(t, l, r));
	}
	return 0;
}