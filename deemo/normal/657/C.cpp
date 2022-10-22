#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll INF = 1e9 + 10;

ll n, k, x, y, vec[MAXN];
ll ans = 2e18;
multiset<ll>	st[6];
ll we[6];

void add(ll v, ll z){
	ll ret = 0;
	while (v % 5 != z)
		v++, ret += y;
	ll tt = ((INF + z) - v)/ 5LL * x + ret;
	we[z] += tt;
	st[z].insert(tt);
	if (st[z].size() > k){
		auto it = st[z].end();	it--;
		we[z] -= *it;
		st[z].erase(it);
	}
}

ll get(ll v, ll z){
	while (v % 5 != z)	v++;
	return	we[z] - k * ((INF + z - v)/5LL * x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> x >> y;
	for (ll i = 0; i < n; i++)	cin >> vec[i], vec[i] += INF;
	sort(vec, vec + n);
	if (5 * y <= x){
		ll sm = 0;
		for (ll i = 0; i < n; i++){
			sm += INF - vec[i];
			if (i >= k)
				sm -= INF - vec[i - k];
			if (i + 1 >= k)
				ans = min(ans, (sm - k * (INF - vec[i])) * ll(y));
		}
		cout << ans << "\n";
		return	0;
	}

	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < 5; j++){
			add(vec[i], j);
			if (i + 1 >= k)	
				ans = min(ans, get(vec[i], j));
		}
	}
	cout << ans << "\n";
	return	0;
}