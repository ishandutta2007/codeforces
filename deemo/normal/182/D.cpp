#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll BASE = 71;
const ll MAX = 1e5 + 50;

ll n, ans;
string s, t;
ll a[MAX], b[MAX], aa[MAX], bb[MAX];
ll pw[MAX];
vector<int>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> s;
	n = s.size();	

	for (ll i = 1; i * i <= n ; i++){
		if (n % i != 0)	continue;
		if ((ll)t.size() % i == 0)	
			vec.push_back(i);
		if (i != n / i)
			if ((ll)t.size() % (n/i) == 0)	vec.push_back(n/i);
	}


	pw[0] = 1;
	for (ll i= 1 ; i < MAX; i++)
		pw[i] = (pw[i - 1] * BASE) % MOD;

	a[0] = 0;
	for (ll i = 0 ; i < s.size(); i++)
		a[i + 1] = (a[i] * BASE + s[i]) % MOD;
	aa[n + 1] = 0;
	for (ll i = s.size() - 1; i >= 0; i--)
		aa[i + 1] = (aa[i + 2] + pw[s.size() - i - 1] * s[i])	% MOD;
	
	b[0] = 0;
	for (ll i = 0; i < t.size(); i++)
		b[i + 1] = (b[i] * BASE + t[i]) % MOD;
	bb[t.size() + 1] = 0;
	for (ll i = t.size() - 1; i >= 0; i--)
		bb[i + 1] = (bb[i + 2] + pw[t.size() - i - 1] * t[i]) % MOD;

	for (ll i = 0 ; i < vec.size(); i++){
		ll temp = vec[i];
		if (a[temp] != b[temp])	continue;
		if (a[s.size() - temp] != aa[temp + 1])	continue;
		if (b[t.size() - temp] != bb[temp + 1])	continue;
		ans++;
	}
	cout << ans << endl;
	return 0;
}