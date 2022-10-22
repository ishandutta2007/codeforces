#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cassert>
#include<set>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 100;
const ll MOD = 1e9 + 7;
const ll BASE = 721;

ll p[MAXN], p2[MAXN];
ll c1[200], c2[200];
ll h[MAXN], save[MAXN];
set<ll>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin >> n;
	string s, t;	cin >> s >> t;
	for (ll i = 0; i < n; i++)
		c1[s[i]]++, c2[t[i]]++;

	ll cnt = 0;
	char ind = 'z';
	for (ll i = 'a'; i <= 'z'; i++)
		if (c1[i] < c2[i]){
			cnt += c2[i] - c1[i];
			ind = i;
		}
	if (cnt > 1){
		cout << 0 << endl;
		return 0;
	}
	
	ll b = 0;
	for (ll i = 0; i < n; i++){
		if (s[i] == t[b])	b++;
		p[i + 1] = b;
	}
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	b = 0;
	for (ll i = 0; i < n; i++){
		if (s[i] == t[b])	b++;
		p2[n - i - 1] = b;
	}
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	for (ll i = 0; i < n; i++)
		h[i + 1] = (h[i] * BASE + s[i]) % MOD;
	save[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		save[i] = (save[i - 1] * BASE) % MOD;

	for (ind = 'a'; ind <= 'z'; ind++){
		if (t[0] == ind && p2[0] == n - 1){
			ll temp = (ind * save[n] + h[n]) % MOD;
			st.insert(temp);
		}
		for (ll i = 0; i < n; i++){
			ll a = p[i + 1];
			bool fl = 0;
			if (a == i + 1){
				if (ind == t[i + 1] && p2[i + 1] == n - a - 1)	fl = 1;
				//if (i + 2 < n && ind == t[i + 1] && p2[i + 2] == n - a - 1)	fl = 1;
			}
			else if (a == i && p2[i + 1] == n - a - 1){
				if (ind == t[i])	fl = 1;
				//if (i && ind == t[i - 1] && p[i] == a)	fl = 1;
			}
			if (fl){
				ll z = (h[n] + MOD - (h[i + 1] * save[n - i - 1] % MOD)) % MOD;
				ll temp = (h[i + 1] * BASE + ind) % MOD;
				temp = (temp * save[n - i - 1] + z) % MOD;
				st.insert(temp);
			}
		}
	}
	cout << st.size() << endl;
	return 0;
}