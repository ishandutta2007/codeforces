#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<numeric>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 40;

ll n, m, p, q, cnt;
vector<pair<ll, ll>>	ans;
ll sum[MAXN], comp[MAXN];
bool del[MAXN];
set<pair<ll, ll>>	st;

ll get_comp(ll v){
	if (comp[v] == v)
		return	v;
	return	
		comp[v] = get_comp(comp[v]);
}

void put(ll u, ll v, ll w = -1){
	bool fl = 0;
	if (w == -1){
		w = min((ll)1e9, sum[get_comp(u)] + sum[get_comp(v)] + 1);	
		fl = 1;
	}

	if (get_comp(u) == get_comp(v)){
		sum[get_comp(u)] += w;
		return;
	}

	ll ret = sum[get_comp(u)] + sum[get_comp(v)] + w;
	del[get_comp(u)] = 1;
	comp[get_comp(u)] = get_comp(v);
	sum[get_comp(v)] = ret;
	if (!fl)	cnt--;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p >> q;
	cnt = n;
	iota(comp, comp + n, 0);
	pair<ll, ll>	e(-1, -1);
	for (ll i = 0; i < m; i++){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		e = {a, b};
		put(a, b, c);
	}
	if (cnt < q || cnt - q > p){
		cout << "NO\n";
		return 0;
	}
	cnt = cnt - q;
	for (ll i = 0; i < n; i++)
		if (!del[i])
			st.insert({sum[i], i});
	
	while (cnt--){
		set<pair<ll, ll>>::iterator it = st.begin(), it2;
		it2 = it;
		it2++;
	
		ll u = it->second, v = it2->second;
		e = {u, v};
		st.erase(st.begin());	st.erase(st.begin());
		ans.push_back({u, v});
		put(u, v);
		st.insert({sum[get_comp(u)], get_comp(u)});
	}
	p -= (ll)ans.size();
	
	while (p--){
		if (e.first == -1){
			cout << "NO\n";
			return 0;
		}
		ans.push_back(e);
	}
	cout << "YES\n";
	for (pair<ll, ll>	v:ans)
		cout << v.first + 1 << " " << v.second + 1 << "\n";
	return 0;	
}