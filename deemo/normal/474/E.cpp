#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;

ll n, d;
ll h[MAXN], gec[MAXN];
map<ll, ll>	mp;
ll p[4 * MAXN], seg[4 * MAXN], par[MAXN], dp[MAXN];

void build(ll v, ll b, ll e){
	if (e - b == 1){
		p[v] = -1;
		return;
	}

	ll mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	p[v] = -1;
}

void modify(ll v, ll b, ll e, ll x, ll val, ll ind){
	if (e - b == 1){
		if (seg[v] < val){
			seg[v] = val;
			p[v] = ind;
		}
		return;
	}

	ll mid = (b + e)/ 2;
	if (x < mid)
		modify(v<<1, b, mid, x, val, ind);
	else
		modify(v<<1^1, mid, e, x, val, ind);
	if (seg[v<<1] >= seg[v<<1^1])
		seg[v] = seg[v<<1], p[v] = p[v<<1];
	else
		seg[v] = seg[v<<1^1], p[v] = p[v<<1^1];
}

pair<ll, ll>	get(ll v, ll b, ll e, ll l, ll r){
	if (r <= l)		return {0, -1};
	if (l <= b && e <= r)	return	{seg[v], p[v]};
	if (r <= b || e <= l)	return	{-1, -1};

	ll mid = (b + e)/ 2;
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void show(ll v){
	if (v == -1)	return;
	show(par[v]);
	cout << v + 1 << " ";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (ll i = 0; i < n; i++)	
		cin >> h[i];
	copy(h, h + n, gec);
	sort(gec, gec + n);
	for (ll i = 0; i < n; i++)
		if (i == 0 || gec[i - 1] != gec[i])
			mp[gec[i]] = i;
	build(1, 0, n);
	ll maxi = 0, ind = -1;
	for (ll i = 0; i < n; i++){
		ll l, r, pos = lower_bound(gec, gec + n, h[i] + d) - gec;
		if (pos < n)
			l = mp[gec[pos]];
		else
			l = n;
		pair<ll, ll>	temp = get(1, 0, n, l, n);
		
		pos = upper_bound(gec, gec + n, h[i] - d) - gec;
		if (pos == n)
			r = n;
		else
			r = mp[gec[pos]];
		pair<ll, ll>	temp2 = get(1, 0, n, 0, r);

		if (temp.first < temp2.first)
			swap(temp, temp2);
		dp[i] = temp.first + 1;
		par[i] = temp.second;
		modify(1, 0, n, mp[h[i]], dp[i], i);

		if (maxi < dp[i])
			maxi = dp[i], ind = i;
	}
	cout << maxi << "\n";
	show(ind);
	cout << "\n";
	return 0;
}