#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;
typedef pair<pair<ll, ll>, ll>	Dastan;
#define left first.first
#define right first.second
#define color second

const ll MAXN = 1e5 + 20;
const ll INF = 1e9;

ll n, q;
set<Dastan>	st;
ll sum[4 * MAXN], lazy[4 * MAXN];

void shift(ll v, ll b, ll e, ll mid){
	lazy[v<<1] += lazy[v];
	lazy[v<<1^1] += lazy[v];
	sum[v<<1] += lazy[v] * (mid - b);
	sum[v<<1^1] += lazy[v] * (e - mid);
	lazy[v] = 0;
}

void add(ll v, ll b, ll e, ll l, ll r, ll val){
	if (l <= b && e <= r){
		lazy[v] += val;
		sum[v] += val * (e - b);
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	add(v<<1, b, mid, l, r, val);
	add(v<<1^1, mid, e, l, r, val);
	sum[v] = sum[v<<1] + sum[v<<1^1];
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	sum[v];
	if (r <= b || e <= l)	return	0;

	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	return	get(v<<1, b, mid, l, r) + get(v<<1^1, mid, e, l, r);
}

void update(ll l, ll r, ll col){
	set<Dastan>::iterator it = st.upper_bound({{l, INF}, INF});
	it--;
	vector<Dastan>	sec, gec;

	while (it != st.end()){
		ll tl = it->left, tr = it->right, x = it->color;
		if (tl >= r)	break;

		if (tl < l)
			sec.push_back({{tl, l}, x});
		if (r < tr)
			sec.push_back({{r, tr}, x});

		add(1, 0, n, max(l, tl), min(r, tr), abs(x - col));
		gec.push_back(*it);
		it++;
	}
	for (auto v:gec)	st.erase(v);
	for (auto v:sec)	st.insert(v);
	st.insert({{l, r}, col});
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++)
		st.insert({{i, i + 1}, i + 1});

	while (q--){
		ll type, l, r;	cin >> type >> l >> r;	l--;
		if (type == 2)
			cout << get(1, 0, n, l, r) << "\n";
		else{
			ll x;	cin >> x;
			update(l, r, x);
		}
	}
	return	0;
}