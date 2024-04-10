#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstring>
#include<utility>
#include<map>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 20;
const ll INF = 1e18;

ll n, m, s, t, depth[MAXN];
vector<pair<ll, ll>>	adj[2][MAXN];
ll aa[MAXN], bb[MAXN], cc[MAXN], d[2][MAXN];
bool mark[MAXN];
set<pair<ll, ll>>	st;
map<pair<pair<ll, ll>, ll>, ll>	mp;

void update(ll v, ll type){
	mark[v] = 1;
	for (auto e:adj[type][v])
		if (!mark[e.first] && e.second + d[type][v] < d[type][e.first]){
			ll u = e.first, w = e.second;
			st.erase({d[type][u], u});
			d[type][u] = d[type][v] + w;
			st.insert({d[type][u], u});
		}
}

ll get_min(){
	auto temp = *st.begin();
	st.erase(st.begin());
	return	temp.second;
}

void dijk(ll v, ll type){
	memset(mark, 0, sizeof(mark));
	d[type][v] = 0;
	update(v, type);

	while (st.size())
		update(get_min(), type);
}

ll dfs(ll v, ll p = -1, ll de = 0){
	mark[v] = 1;
	depth[v] = de;
	ll tp = de;
	for (auto e:adj[1][v])
		if (d[0][e.first] + e.second + d[1][v] == d[0][t]){
			if (mark[e.first]){
				if (p != e.first)	tp = min(tp, depth[e.first]);
			}
			else{
				ll z = dfs(e.first, v, de + 1);
				if (z > de)	mp[{{e.first, v}, e.second}] = 1;
				tp = min(tp, z);
			}
			if (p == e.first)	p = -1;
		}

	for (auto e:adj[0][v])
		if (d[0][v] + e.second + d[1][e.first] == d[0][t]){
			if (mark[e.first]){
				if (p != e.first)	tp = min(tp, depth[e.first]);
			}
			else{
				ll z = dfs(e.first, v, de + 1);
				if (z > de)	mp[{{v, e.first}, e.second}] = 1;
				tp = min(tp, z);
			}
			if (p == e.first)	p = -1;
		}
	return	tp;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;	s--, t--;
	for (ll i = 0; i < m; i++){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		adj[0][a].push_back({b, c});
		adj[1][b].push_back({a, c});
		aa[i] = a, bb[i] = b, cc[i] = c;
	}
	for (ll i = 0; i < 2; i++)
		fill(d[i], d[i] + MAXN, INF);
	dijk(s, 0);
	dijk(t, 1);
	memset(mark, 0, sizeof(mark));
	dfs(t);
	for (ll i = 0; i < m; i++){
		if (mp[{{aa[i], bb[i]}, cc[i]}])
			cout << "YES\n";
		else if (d[0][aa[i]] + d[1][bb[i]] + 1 < d[0][t])
			cout << "CAN " << cc[i] - (d[0][t] - d[0][aa[i]] - d[1][bb[i]] - 1) << "\n";
		else cout << "NO\n";
	}
	return	0;
}