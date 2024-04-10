#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 30;
const ll INF = 1e18 + 4;

ll n, vec[MAXN];
ll sec[4];
ll seg[4 * MAXN], lz[4 * MAXN];

void build(ll v, ll b, ll e){
	if (e - b == 1){
		seg[v] = vec[b];
		return;
	}

	ll mid = (b + e)/ 2;
	build(v<<1, b, mid);
	build(v<<1^1, mid, e);
	seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

void shift(ll v){
	lz[v<<1] += lz[v];
	lz[v<<1^1] += lz[v];
	seg[v<<1] += lz[v];
	seg[v<<1^1] += lz[v];
	lz[v] = 0;
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (l <= b && e <= r)	return	seg[v];
	if (r <= b || e <= l)	return	INF;

	ll mid = (b + e)/ 2;
	shift(v);
	return	min(get(v<<1, b, mid, l, r), get(v<<1^1, mid, e, l, r));
}

void add(ll v, ll b, ll e, ll l, ll r, ll val){
	if (l <= b && e <= r){
		seg[v] += val;
		lz[v] += val;
		return;
	}
	if (r <= b || e <= l)	return;

	ll mid = (b + e)/ 2;
	shift(v);
	add(v<<1, b, mid, l, r, val);
	add(v<<1^1, mid, e, l, r, val);
	seg[v] = min(seg[v<<1], seg[v<<1^1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	build(1, 0, n);

	ll q;	cin >> q;
	string s;	getline(cin, s);
	while (q--){
		getline(cin, s);
		memset(sec, 0, sizeof(sec));
		ll cur = 0;
		bool fl = 0;
		for (ll i = 0; i < s.size(); i++)
			if (s[i] == ' ')	cur++;
			else{
				if (s[i] == '-')	
					fl = 1;
				else
					sec[cur] = sec[cur] * 10 + (s[i] - '0');
			}
		if (fl)
			sec[cur] *= -1;
	
		if (cur == 1){
			ll l = sec[0], r = sec[1];
			if (l <= r)
				cout << get(1, 0, n, l, r + 1) << "\n";
			else
				cout << min(get(1, 0, n, l, n), get(1, 0, n, 0, r + 1)) << "\n";
		}
		else{
			ll l = sec[0], r = sec[1], val = sec[2];
			if (l <= r)
				add(1, 0, n, l, r + 1, val);
			else{
				add(1, 0, n, l, n, val);
				add(1, 0, n, 0, r + 1, val);
			}
		}
	}
	return 0;
}