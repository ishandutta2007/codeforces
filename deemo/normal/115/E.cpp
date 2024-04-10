//Accepted!

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

#define Race pair<pair<ll, ll>, ll>
#define left first.first
#define right first.second
#define val second

const ll MAXN = 2e5 + 10;
const ll INF = 2e18 + 2;

ll n, m, c[MAXN];
Race vec[MAXN];
ll d[MAXN];
ll weed[4 * MAXN], nut[4 * MAXN];

bool cmp(Race a, Race b){
	if (a.right != b.right)
		return	a.right < b.right;
	return	a.left < b.left;
}

void absorb(ll v, ll b, ll e, ll mid){
	weed[v<<1] += nut[v];
	weed[v<<1^1] += nut[v];
	nut[v<<1] += nut[v];
	nut[v<<1^1] += nut[v];
	nut[v] = 0;
}

void add(ll v, ll b, ll e, ll x, ll g){
	if (e - b == 1){
		weed[v] = g;
		return;
	}

	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	if (x < mid)
		add(v<<1, b, mid, x, g);
	else
		add(v<<1^1, mid, e, x, g);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void water(ll v, ll b, ll e, ll l, ll r, ll x){
	if (l <= b && e <= r){
		nut[v] += x;
		weed[v] += x;
		return;	
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	water(v<<1, b, mid, l, r, x);
	water(v<<1^1, mid, e, l, r, x);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	-INF;

	ll mid = (b + e)/ 2;
	absorb(v, b, e, mid);
	return	max(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++)	cin >> c[i];
	for (ll i = 0; i < m; i++)
		cin >> vec[i].left >> vec[i].right >> vec[i].val;
	sort(vec, vec + m, cmp);
	
	ll b = 0;
	for (ll i = 0; i < n; i++){
		water(1, 0, n + 1, 0, i + 1, -c[i]);
		while (b < m && vec[b].right == i + 1)
			water(1, 0, n + 1, 0, vec[b].left, vec[b].val), b++;
	
		d[i + 1] = max(d[i], get(1, 0, n + 1, 0, i + 1));
		add(1, 0, n + 1, i + 1, d[i + 1]);
	}
	cout << d[n] << endl;
	return	0;
}