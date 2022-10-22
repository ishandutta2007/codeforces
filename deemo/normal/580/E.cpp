#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef unsigned long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_ll(x) ({ ll _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const ll MOD = 1e8 + 7;
const ll base = 71;
const ll max_n = 2e5 + 400;

ll n, m, k, q;
string s;
ll pw[2 * max_n + 200];
ll save[20][2 * max_n + 200];
ll seg[10 * max_n], lazy[10 * max_n];

void init(ll v, ll b, ll e){
	lazy[v] = -1;
	if (b == e){
		seg[v] = s[b];
		return;
	}
	ll mid = (b + e) / 2;
	init(v<<1, b, mid);
	init(v<<1^1, mid + 1, e);
	seg[v] = (seg[v<<1] * pw[e - mid] + seg[v<<1^1]) % MOD;
}

void shift(ll v, ll b, ll e, ll mid){
	if (lazy[v] == -1)	return;
	lazy[v<<1] = lazy[v<<1^1] = lazy[v];
	seg[v<<1] = save[lazy[v]][mid - b];
	seg[v<<1^1] = save[lazy[v]][e - mid - 1];
	lazy[v] = -1;
}

void update(ll v, ll b, ll e, ll l, ll r, ll val){
	if (b > r || l > e)	return;
	if (l <= b && e <= r){
		seg[v] = save[val][e - b];
		lazy[v] = val;
		return;
	}
	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	update(v<<1, b, mid, l, r, val);
	update(v<<1^1, mid + 1, e, l, r, val);
	seg[v] = (seg[v<<1] * pw[e - mid] + seg[v<<1^1]) % MOD;
}

ll get(ll v, ll b, ll e, ll l, ll r){
	if (b > r || l > e)	return 0;
	if (l <= b && e <= r)	return seg[v];
	ll mid = (b + e)/ 2;
	shift(v, b, e, mid);
	ll first = get(v<<1, b, mid, l, r);
	ll second = get(v<<1^1, mid + 1, e, l, r);
	first = (first * pw[max(0, int(min(r,e) - mid))] + second) % MOD;
	return	first;
}

int main(){
	read_fast;
	cin >> n >> m >> k;
	q = m + k;
	cin >> s;	
	//ok
	
	pw[0] = 1;
	for (ll i = 1; i < max_n; i++)
		pw[i] = (pw[i - 1] * base) % MOD;
		
	for (ll i = 0; i < 10; i++){
		save[i][0] = i + 48;
		for (ll j = 1; j < max_n;  j++)
			save[i][j] = (save[i][j - 1] * base + (i + 48)) % MOD;
	}
	//ok

	init(1, 0, n - 1);

	while(q--){
		ll type, l, r;	cin >> type >> l >> r;
		l--, r--;
		if (type == 1){
			ll c;	cin >> c;
			update(1, 0, n - 1, l, r, c);
			continue;
		}
		bool fl = 0;
		ll d;	cin >> d;
		if (d == r - l + 1)	fl = 1;
		if (!fl)
			fl = get(1, 0, n - 1, l, r - d) == get(1, 0, n - 1, l + d, r);
		if (fl)	cout << "YES\n";
		else	cout << "NO\n";
	}

    return 0;
}