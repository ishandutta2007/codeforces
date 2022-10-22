//Spread your wings across the universe..

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXM = 20 + 2;
const ll MAXN = 100 + 2;
const ll INF = 2e18;
const ll MAX = (1 << 20) + 100;

ll n, m, s;
pair<pair<ll, ll>, ll>	vec[MAXN];
ll c[MAX], d[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s;
	for (ll i = 0; i < n; i++){
		ll a, b, t;	cin >> a >> b >> t;
		ll mask = 0;
		while (t--){
			ll temp;	cin >> temp;	temp--;
			mask |= 1 << temp;
		}
		vec[i] = {{b, a}, mask};
	}
	sort(vec, vec + n);
	fill(c, c + MAX, INF);
	fill(d, d + MAX, INF);
	c[0] = d[0] = 0;
	ll z = (1 << m) - 1;
	for (ll i = 0; i < n; i++){
		for (ll j = z; j; j--)
			d[j] = min(d[j], c[(j ^ vec[i].second) & j] + vec[i].first.second + vec[i].first.first * s);
		for (ll j = z; j; j--)
			c[j] = min(c[j], c[(j ^ vec[i].second) & j] + vec[i].first.second);
	}
	if (d[z] == INF)
		d[z] = -1;
	cout << d[z] << "\n";
	return 0;
}