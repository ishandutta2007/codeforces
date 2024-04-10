#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll INF = 2e9 + 4;

ll n, q, vec[MAXN];
pair<ll, ll>	sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (ll i = 0; i < n; i++){
		cin >> vec[i];
		sec[i] = {vec[i], i};
	}
	sort(sec, sec + n);

	while (q--){
		ll v, l;	cin >> v >> l;	v--;	

		while (1){
			ll tv = v, x = vec[v];
			ll ind = upper_bound(sec, sec + n, make_pair(x + l, INF)) - sec;	ind--;
			l -= sec[ind].first - x;
			x = sec[ind].first;
			v = sec[ind].second;
	
			ind = lower_bound(sec, sec + n, make_pair(x - l, -1LL)) - sec;	
			l -= x - sec[ind].first;
			x = sec[ind].first;
			v = sec[ind].second;
	
			ind = lower_bound(sec, sec + n, make_pair(x + l, INF)) - sec;	ind--;
			if (sec[ind].second == v)	break;
			ll dis = sec[ind].first - x;
			ll z = l/dis;
			l %= dis;
			
			if (z % 2)
				v = sec[ind].second;
		}
		cout << v + 1 << "\n";
	}
	return	0;
}