#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

#define Thing pair<pair<ll, ll>, ll>
#define X first.first
#define Y first.second
#define id second

const ll MAXN = 1e5 + 10;
const ll INF = 1e9 + 3;
const ll LOG = 20;

ll n, par[MAXN], xx[MAXN], yy[MAXN], h, t, q[MAXN];
Thing vec[MAXN];
pair<ll, ll>	weed[LOG][4 * MAXN];
ll tl[4 * MAXN], d[MAXN];

void show(ll v){
	if (v == n - 1)	return;
	show(par[v]);
	cout << v + 1 << " ";
}

bool cmp(Thing a, Thing b){
	if (a.X != b.X)	return	a.X < b.X;
	if (a.Y != b.Y)	return	a.Y < b.Y;
	return	a.id < b.id;
}

void plant(ll v, ll b, ll e, ll de = 0){
	tl[v] = b;
	if (e - b == 1){
		weed[de][b] = {vec[b].Y, vec[b].id};
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid, de + 1);
	plant(v<<1^1, mid, e, de + 1);
	merge(weed[de + 1] + b, weed[de + 1] + mid, weed[de + 1] + mid, weed[de + 1] + e, weed[de] + b);
}

void water(ll v, ll b, ll e, ll l, ll r, ll h, ll ind, ll de = 0){
	if (l <= b && e <= r){
		while (tl[v] < e){
			if (weed[de][tl[v]].first > h)	break;
			if (par[weed[de][tl[v]].second] != -2){	tl[v]++;	continue;}
			par[weed[de][tl[v]].second] = ind;
			d[weed[de][tl[v]].second] = d[ind] + 1;
			q[t++] = weed[de][tl[v]].second;
			tl[v]++;
		}
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	water(v<<1, b, mid, l, r, h, ind, de + 1);
	water(v<<1^1, mid, e, l, r, h, ind, de + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(par, par + MAXN, -2);

	cin >> n;
	par[n] = -1;
	for (ll i = 0; i < n; i++){
		cin >> vec[i].X >> vec[i].Y >> xx[i] >> yy[i];
		vec[i].id = i;
	}
	xx[n] = 0, yy[n] = 0, vec[n] = {{0, 0}, n};	n++;
	sort(vec, vec + n, cmp);
	plant(1, 0, n);

	q[t++] = n - 1;
	while (h < t){
		ll v = q[h++];	
		ll pos = upper_bound(vec, vec + n, make_pair(make_pair(xx[v], INF), INF)) - vec;
		water(1, 0, n, 0, pos, yy[v], v);
	}

	if (par[n - 2] == -2)
		cout << "-1\n";
	else{
		cout << d[n - 2] << "\n";
		show(n - 2);
		cout << "\n";
	}
	return	0;
}