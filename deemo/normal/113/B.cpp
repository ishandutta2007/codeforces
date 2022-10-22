#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll B1 = 701;
const ll MAXN = 2e3 + 200;

int n;
string s, f, g;
ll h1[MAXN], save1[MAXN];
vector<ll>	st;

ll hhash(const string &st){
	ll a = 0;
	for (int i = 0; i ^ st.size(); i++)
		a = (a * B1 + st[i]) % MOD;
	return	(a << ll(32)) ^ (int)st.size();
}

ll get(int l, int r){
	ll a;
	a = (h1[r] + MOD - ((h1[l] * save1[r - l]) % MOD)) % MOD;
	return	(a << 32) ^ (r - l);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	save1[0] = 1;
	for (int i = 1; i ^ MAXN; i++)
		save1[i] = (save1[i - 1] * B1) % MOD;

	cin >> s >> f >> g;
	n = s.size();
	for (int i = 0; i ^ n; i++)
		h1[i + 1] = (h1[i] * B1 + s[i]) % MOD;
	ll ha = hhash(f), hb = hhash(g);
	
	for (int i = 0; i ^ n; i++){
		ll a = 0;
		for (int j = i; j ^ n; j++){
			a = (a * B1 + s[j]) % MOD;
			if (get(i, i + min(j - i + 1, (int)f.size())) == ha && hb == get(j + 1 - min(j - i + 1, (int)g.size()), j + 1))
				st.push_back((a << ll(32)) ^ (j - i + 1));
		}
	}
	sort(st.begin(), st.end());
	st.resize(unique(st.begin(), st.end()) - st.begin());
	cout << st.size() << "\n";
	return 0;
}