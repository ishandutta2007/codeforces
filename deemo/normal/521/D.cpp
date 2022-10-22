#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<functional>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Thing{
	ll F, S;
	Thing(ll a, ll b){
		F = a, S = b;
	}
};

const ll MAXN = 1e5 + 10;

ll n, m, k, vec[MAXN], tt[MAXN];
pair<ll, ll>	mx[MAXN];
vector<pair<ll, ll>>	sec[MAXN];
multiset<pair<Thing, ll>>	st;
vector<ll>	ans;

bool cmp(ll u, ll v){return tt[u] < tt[v];}
bool operator <(Thing a, Thing b){return ld(a.F)/ ld(a.S) < ld(b.F)/ ld(b.S);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	for (ll i = 0; i < m; i++){
		ll type, v, x;	cin >> type >> v >> x;	v--;
		if (type == 1)
			mx[v] = max(mx[v], {x, i});
		if (type == 2)
			sec[v].push_back({x, i});
		Thing temp(x, 1);
		if (type == 3)
			st.insert({temp, i});
		tt[i] = type;
	}

	for (ll i = 0; i < n; i++){
		if (mx[i].first > vec[i])	sec[i].push_back({mx[i].first - vec[i], mx[i].second});
		sort(sec[i].begin(), sec[i].end(), greater<pair<ll, ll>>());
		ll cur = vec[i];
		for (ll j = 0; j < sec[i].size(); j++){
			ll g = __gcd(cur, cur + sec[i][j].first);
			Thing temp((cur + sec[i][j].first)/ g, cur/g);
			st.insert({temp, sec[i][j].second});
			cur += sec[i][j].first;
		}
	}

	for (ll i = 0; st.size() && i < k; i++){
		auto it = st.end();	it--;
		ans.push_back(it->second);
		st.erase(it);
	}

	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << "\n";
	for (auto v:ans)
		cout << v + 1 << " ";
	cout << "\n";
	return	0;
}