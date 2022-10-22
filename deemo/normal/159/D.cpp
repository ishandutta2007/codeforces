#include<iostream>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 9;
const ll max_n = 2e3 + 10;
const ll BASE = 71;

ll n;
string s;
ll d[max_n], r[max_n], l[max_n], save[max_n];
vector<pair<ll, ll>>	vec;

void init(){
	save[0] = 1;
	for (ll i = 1; i < max_n; i++)
		save[i] = (save[i - 1] * BASE) % MOD;
	
	l[0] = s[0];
	for (ll i = 1; i < n; i++)
		l[i] = (l[i - 1] * BASE + s[i]) % MOD;
	
	r[n - 1] = s[n - 1];
	for (ll i = n - 2; i >= 0; i--)
		r[i] = (r[i + 1] * BASE + s[i]) % MOD;

	for (ll i = 0; i < n; i++)
		for (ll j = i; j < n; j++){
			ll a, b;
			if (i == 0)	a = l[j];
			else{
				ll t = l[i - 1];
				t = (t * save[j - i + 1]) % MOD;
				a = (l[j] + MOD - t) % MOD;
			}
			if (j == n - 1)	b = r[i];
			else{
				ll t = r[j + 1];
				t = (t * save[j - i + 1]) % MOD;
				b = (r[i] + MOD - t) % MOD;
			}
			if (a == b)
				vec.push_back({i, j});
		}
}

bool cmp(pair<ll, ll>	a, pair<ll, ll>	b){
	return	a.second < b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	 n = s.size();
	init();
	sort(vec.begin(), vec.end(), cmp);
	ll j = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++){
		for (ll k = j; vec[k].second == i; k++){
			if (vec[k].first == 0)	continue;
			ans += d[vec[k].first - 1];
		}

		if (i != 0)	d[i] = d[i - 1];
		while (j < vec.size() && vec[j].second == i)
			d[i]++, j++;
	}
	cout << ans << endl;
	return 0;
}