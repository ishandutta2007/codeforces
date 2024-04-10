#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 20;

ll a, b, k, gg;
ll d[MAXN];
ll q[MAXN];

ll bfs(ll s, ll des){
	memset(d, -1, sizeof(d));
	d[s] = 0;
	ll h = 0, t = 0;
	q[t++] = s;

	while (h < t){
		ll v = q[h++];
		if (v == 0)	continue;
		for (ll i = 2; i <= k; i++){
			ll z = v % i;
			if (d[v - z] == -1){
				d[v - z] = d[v] + 1;
				q[t++] = v - z;
			}
		}
		if (d[v - 1] == -1){
			d[v - 1] = d[v] + 1;
			q[t++] = v - 1;
		}
	}

	return	d[des];
}

int main(){
	cin >> a >> b >> k;
	if (a == b){
		cout << 0 << endl;
		return 0;
	}
	gg = 1;
	for (ll i = 2; i <= k; i++){
		ll t = gg;
		gg *= i;
		gg /= __gcd(t, (ll)i);
	}
	
	if (a / gg == b / gg){
		ll x = a % gg, y = b % gg;
		cout << bfs(x, y) << endl;
		return 0;
	}		

	ll ta = a, tb = b;
	while (ta % gg)	ta--;
	while (tb % gg)	tb++;
	ll ans = bfs(gg, b % gg) + bfs(a % gg, 0) + (ta - tb)/ gg * bfs(gg, 0);
	cout << ans << endl;
	return 0;
}