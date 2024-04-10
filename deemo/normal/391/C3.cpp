#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 2e5 + 10;
const ll INF = 1e18;

ll n, k, p[MAXN], f[MAXN], sec[MAXN], mp[MAXN], rem, gec[MAXN], sz, pt[MAXN], nd;
ll mn[4 * MAXN], cnt[4 * MAXN], sm[4 * MAXN];
vector<ll>	vec[MAXN];

bool cmp(ll u, ll v){return f[u] < f[v];}

void plant(ll v, ll b, ll e){
	if (e - b == 1){
		cnt[v] = 1;
		sm[v] = f[sec[b]];
		mn[v] = f[sec[b]];
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);

	mn[v] = min(mn[v<<1], mn[v<<1^1]);
	cnt[v] = cnt[v<<1] + cnt[v<<1^1];
	sm[v] = sm[v<<1] + sm[v<<1^1];
}

void water(ll v, ll b, ll e, ll pos, bool type){
	if (e - b == 1){
		if (type){
			cnt[v] = 1;
			sm[v] = f[sec[b]];
			mn[v] = f[sec[b]];
		}
		else{
			cnt[v] = 0;
			sm[v] = 0;
			mn[v] = INF;
		}
		return;
	}

	ll mid = (b + e)/ 2;
	if (pos < mid)
		water(v<<1, b, mid, pos, type);
	else
		water(v<<1^1, mid, e, pos, type);

	mn[v] = min(mn[v<<1], mn[v<<1^1]);
	cnt[v] = cnt[v<<1] + cnt[v<<1^1];
	sm[v] = sm[v<<1] + sm[v<<1^1];
}

pair<ll, ll> smoke(ll v, ll b, ll e, ll x = 0, ll y = 0){
	if (e - b == 1){
		if (cnt[v] && (rem + (nd - y - 1) >= sz || mn[v] < gec[rem + (nd - y - 1)]))
			y++, x += sm[v];
		return {x, y};
	}

	ll mid = (b + e)/ 2;
	if (nd <= (sz - rem) + (cnt[v<<1] + y) && (cnt[v<<1] + y >= nd || mn[v<<1^1] >= gec[rem + nd - (cnt[v<<1] + y) - 1]))
		return	smoke(v<<1, b, mid, x, y);
	return smoke(v<<1^1, mid, e, x + sm[v<<1], y + cnt[v<<1]);
}

int main(){
	{
		scanf("%I64d %I64d", &n, &k);
		for (ll i = 0; i < n; i++){
			scanf("%I64d %I64d", &p[i], &f[i]);
			vec[p[i]].push_back(i);
		}
		iota(sec, sec + n, 0);
		sort(sec, sec + n, cmp);
		for (ll i = 0; i < n; i++)
			mp[sec[i]] = i;
	}

	ll ans = INF;
	{
		plant(1, 0, n);
		ll cc = 0;
		for (ll i = 0; i <= n; i++){
			cc += vec[i].size();
			if (n - cc > k - 1)	continue;
			sz = vec[i].size();
			if (i)
				sz += vec[i - 1].size();
			rem = max(sz - (k - 1 - (n - cc)), 0LL);
			nd = i - rem;
			if (nd < 0)	continue;

			sz = 0;
			for (auto v:vec[i])
				water(1, 0, n, mp[v], 0), gec[sz++] = f[v];
			if (i)
				for (auto v:vec[i - 1])
					water(1, 0, n, mp[v], 0), gec[sz++] = f[v];
			
			sort(gec, gec + sz);
			for (ll j = 0; j < sz; j++)
				pt[j + 1] = pt[j] + gec[j];
			pair<ll, ll> x = (nd?smoke(1, 0, n):make_pair(0LL, 0LL));
			ans = min(ans, pt[rem + (nd - x.S)] + x.F);

			for (auto v:vec[i])
				water(1, 0, n, mp[v], 1);
			if (i)
				for (auto v:vec[i - 1])
					water(1, 0, n, mp[v], 1);
		}
	}
	if (ans == INF)	ans = -1;
	printf("%I64d\n", ans);
	return 0;
}