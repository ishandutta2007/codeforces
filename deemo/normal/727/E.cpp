#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXLEN = 2e6 + 10;
const ll MAXN = 2e6 + 10;
const ll MOD[2] = {(ll)1e9 + 7, (ll)1e9+9};
const ll BASE[2] = {701, 721};

string s;
ll n, k, ln, m;
pair<ll, ll>	sec[MAXN];
ll hs[2][MAXN], ss[2][MAXN], ans[MAXN];
map<ll, ll>	cnt;

ll getHash(string t){
	ll ret = 0, ret2 = 0;
	for (char c:t){
		ret = (1ll * ret * BASE[0] + c) % MOD[0];
		ret2 = (1ll * ret2 * BASE[1] + c) % MOD[1];
	}
	return (ret<<32)|ret2;
}

ll get(ll bg){
	ll ret, ret2;
	{
		ll gg = min(ln, bg + k) - bg;
		ret = (hs[0][bg + gg] - 1ll * hs[0][bg] * ss[0][gg] % MOD[0] + MOD[0]) % MOD[0];
		gg = k - gg;
		ret = (1ll * ret * ss[0][gg] + hs[0][gg]) % MOD[0];
	}
	{
		ll gg = min(ln, bg + k) - bg;
		ret2 = (hs[1][bg + gg] - 1ll * hs[1][bg] * ss[1][gg] % MOD[1] + MOD[1]) % MOD[1];
		gg = k - gg;
		ret2 = (1ll * ret2 * ss[1][gg] + hs[1][gg]) % MOD[1];
	}	
	return ret<<32|ret2;
}

ll go(ll bg){
	ll ret = 0;
	cnt.clear();
	for (ll i = 0; i < n; i++, bg += k){
		ll tmp = get(bg);
		ll pos = lower_bound(sec, sec + m, make_pair(tmp, -1ll)) - sec;
		if (pos == m || sec[pos].F != tmp)	return ret;
		if (cnt[sec[pos].S])	return 0;
		cnt[sec[pos].S]++;
		ans[ret++] = sec[pos].S;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int w = 0; w < 2; w++){
		ss[w][0] = 1;
		for (ll i = 1; i < MAXN; i++)
			ss[w][i] = 1ll * ss[w][i - 1] * BASE[w] % MOD[w];
	}
	cin >> n >> k;
	cin >> s;	ln = s.size();
	for (int w = 0; w < 2; w++)
		for (ll i = 0; i < ln; i++)
			hs[w][i + 1] = (1ll * hs[w][i] * BASE[w] + s[i]) % MOD[w];
	cin >> m;
	for (ll i = 0; i < m; i++){
		string t;	cin >> t;
		sec[i] = {getHash(t), i+1};
		cnt[sec[i].F]++;
		assert(cnt[sec[i].F] < 2);
	}
	sort(sec, sec + m);
	bool found = 0;
	for (ll i = 0; !found && i < k; i++)
		if (go(i) == n)	found = 1;
	if (!found){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}