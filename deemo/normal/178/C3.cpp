#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;

ll h, m, n, comp[MAXN], id[MAXN], g;
bool vis[MAXN];
vector<ll>	vec[MAXN];
set<ll>	st[MAXN];
map<ll, pair<ll, ll>>	mp;
ll ans = 0;

void dfs(ll v, ll de = 0){
	if (vis[v])	return;
	vis[v] = 1;
	vec[g].push_back(v);
	comp[v] = g, id[v] = de;
	st[g].insert(de);
	dfs((v + m) % h, de + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> m >> n;
	for (ll i = 0; i < n; i++)
		if (!vis[i])	dfs(i), g++;

	while (n--){
		char type;	cin >> type;
		if (type == '-'){
			ll v;	cin >> v;	
			pair<ll, ll>	temp = mp[v];
			st[temp.first].insert(temp.second);
		}
		else{
			ll v, hh;	cin >> v >> hh;	
			ll c = comp[hh], z = id[hh];
			auto it = st[c].lower_bound(z);
			if (it != st[c].end()){
				ans += *it - z;
				mp[v] = {c, *it};
				st[c].erase(it);
			}
			else{
				it = st[c].begin();
				ans += *it + (ll)vec[c].size() - z;
				mp[v] = {c, *it};
				st[c].erase(it);
			}
		}
	}
	cout << ans << endl;
	return	0;
}