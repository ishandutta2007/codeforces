//I don't care, Go on and tear me apart..

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 10;
const ll LOG = 21;
const ll MOD = 1e9 + 7;

string s[3];
ll	pl[MAXN], sz[3], lc[MAXN];
pair<pair<ll, ll>, ll>	vec[MAXN];
ll tt[LOG][MAXN], pos[3][MAXN], cn[MAXN];
ll mark[MAXN];
ll ans[MAXN], comp[MAXN], aa[3][MAXN];
set<pair<ll, ll>>	st;

ll ce(ll ind){
	if (ind >= sz[1])	return	sz[2];
	if (ind >= sz[0])	return	sz[1];
	return	sz[0];
}

ll lcp(ll a, ll b){
	ll sa = ce(a), sb = ce(b), ta = a;
	for (ll i = LOG - 1; i >= 0 && a < sa && b < sb; i--)
		if (a + (1 << i) <= sa && b + (1 << i) <= sb && tt[i][a] == tt[i][b])	a += 1 << i, b += 1 << i;
	return	a - ta;
}

ll get_comp(ll v){
	if (v == comp[v])	return	v;
	return	comp[v] = get_comp(comp[v]);
}

void join(ll u, ll v){
	for (ll i = 0; i < 3; i++)
		aa[i][get_comp(v)] += aa[i][get_comp(u)];
	comp[get_comp(u)] = get_comp(v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	{
		ll sum = 0;
		for (ll i = 0; i < 3; i++){
			cin >> s[i];
			for (ll j = 0; j < (ll)s[i].size(); j++)	
				tt[0][sum + j] = s[i][j];
			sum += (ll)s[i].size();
			sz[i] = sum;
		}
	}

	for (ll w = 1; w < LOG; w++){
		ll sum = 0;
		for (ll i = 0; i < 3; sum += (ll)s[i].size(), i++)
			for (ll j = 0; j < (ll)s[i].size(); j++)
				if (j + (1 << (w - 1)) >= s[i].size())
					vec[sum + j] = {{tt[w - 1][sum + j], -1}, sum + j};
				else
					vec[sum + j] = {{tt[w - 1][sum + j], tt[w - 1][sum + j + (1 << (w - 1))]}, sum + j};
		
		sort(vec, vec + sum);
		for (ll i = 1; i < sum; i++)
			if (vec[i].first == vec[i - 1].first)	
				tt[w][vec[i].second] = tt[w][vec[i - 1].second];
			else
				tt[w][vec[i].second] = i;
	}

	{
		ll sum = 0;
		for (ll i = 0; i < 3; sum += (ll)s[i].size(), i++)
			for (ll j = 0; j < (ll)s[i].size(); j++){
				pos[i][j] = tt[LOG - 1][sum + j] + cn[tt[LOG - 1][sum + j]]++;
				pl[pos[i][j]] = sum + j;
			}	
	}
	
	{//lcp
		for (ll i = 0; i < sz[2] - 1; i++){
			lc[i] = lcp(pl[i], pl[i + 1]);
			st.insert({lc[i], i});
		}
		iota(comp, comp + sz[2], 0);
		for (ll i = 0; i < sz[2]; i++)
			if (pl[i] >= sz[1])
				aa[2][pl[i]] = 1;
			else if (pl[i] >= sz[0])
				aa[1][pl[i]] = 1;
			else 
				aa[0][pl[i]] = 1;
	}	
	
	ll cnt = 0;
	while ((ll)st.size()){
		cnt++;
		auto it = st.end();	it--;
		ll x = it->first, ind = it->second;
		st.erase(it);

		ll c1 = get_comp(pl[ind]), c2 = get_comp(pl[ind + 1]);
		for (ll i = 0; i < 3; i++){
			ll ret = 1;
			for (ll j = 0; j < 3; j++)
				if (j != i)	ret = (ret * aa[j][c2]) % MOD;
			mark[x] = (mark[x] + aa[i][c1] * ret) % MOD;
		}

		for (ll i = 0; i < 3; i++){
			ll ret = 1;
			for (ll j = 0; j < 3; j++)
				if (j != i)	ret = (ret * aa[j][c1]) % MOD;
			mark[x] = (mark[x] + aa[i][c2] * ret) % MOD;
		}
		join(pl[ind], pl[ind + 1]);
	}

	ll ss = 0;
	ll mini = min((ll)s[0].size(), min((ll)s[1].size(), (ll)s[2].size()));
	for (ll i = mini; i >= 0; i--){
		ss = (ss + mark[i]) % MOD;
		ans[i] = ss;
	}

	for (ll i = 1; i <= mini; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return	0;
}