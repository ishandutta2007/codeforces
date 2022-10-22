#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll B1 = 701;
const ll B2 = 721;
const ll INF = 1e9 + 2;

ll n, m, sz;
map<ll, ll>	mp;
vector<ll>	st;
ll mini[MAXN], sum[MAXN], comp[MAXN], cn[MAXN], cc[MAXN], g, size[MAXN], tt[MAXN];
bool vis[MAXN];
vector<ll>	adj[MAXN], sadj[MAXN], cadj[MAXN];
pair<ll, ll>	save[MAXN];

ll hs(string s){
	for (ll i = 0; i < s.size(); i++)
		if (s[i] > 'Z')	s[i] -= ('a' - 'A');
	ll h1 = 0, h2 = 0;
	for (char c:s){
		h1 = (h1 * B1 + c) % MOD;
		h2 = (h2 * B2 + c) % MOD;
	}
	return	(h1 << ll(32)) ^ h2;
}

void dfs(ll v){
	if (vis[v])	return;
	vis[v] = 1;
	for (ll u:adj[v])
		dfs(u);
	st.push_back(v);
}

void kosaraju(ll v, ll col){
	if (comp[v])	return;
	if (cn[v] < mini[col]){
		mini[col] = cn[v];
		sum[col] = size[v];
	}
	else if (cn[v] == mini[col])
		sum[col] = min(sum[col], size[v]);

	tt[col] += cc[v];

	comp[v] = col;
	for (ll u:sadj[v])
		kosaraju(u, col);
}

pair<ll, ll>	get(ll v){
	if (vis[v])	return	save[v];
	vis[v] = 1;
	pair<ll, ll>	ret = {mini[v], sum[v]};
	for (ll u:cadj[v]){
		pair<ll, ll>	c = get(u);
		if (c.first < ret.first)
			ret = c;
		else if (c.first == ret.first)
			ret.second = min(ret.second, c.second);
	}
	return	save[v] = ret;
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m;
	while (m--){
		string t;	cin >> t;
		ll h = hs(t);
		if (mp.count(h) == 0){
			for (char c:t)
				if (c == 'R' || c == 'r')	cn[sz]++;
			size[sz] = t.size();
			mp[h] = sz++;
		}
		cc[mp[h]]++;
	}
	
	cin >> n;
	while (n--){
		string a, b;	cin >> a >> b;
		ll aa = hs(a), bb = hs(b);
		if (mp.count(aa) == 0){
			for (char c:a)
				if (c == 'R' || c == 'r')	cn[sz]++;
			size[sz] = a.size();
			mp[aa] = sz++;
		}
		if (mp.count(bb) == 0){
			for (char c:b)
				if (c == 'R' || c == 'r')	cn[sz]++;
			size[sz] = b.size();
			mp[bb] = sz++;
		}

		aa = mp[aa], bb = mp[bb];
		adj[aa].push_back(bb);
		sadj[bb].push_back(aa);
	}
	
	for (ll i = 0; i < sz; i++)
		if (!vis[i])	dfs(i);
	reverse(st.begin(), st.end());
	fill(mini, mini + MAXN, INF);
	for (ll u:st)
		if (comp[u] == 0)	kosaraju(u, ++g);

	for (ll i = 0; i < sz; i++)
		for (ll u:adj[i])
			if (comp[u] != comp[i])	
				cadj[comp[i]].push_back(comp[u]);


	ll ans1 = 0, ans2 = 0;
	fill(vis, vis + MAXN, 0);
	for (ll i = 1; i <= g; i++){
		pair<ll, ll>	temp = get(i);

		ans1 += tt[i] * temp.first;
		ans2 += tt[i] * temp.second;
	}
	cout << ans1 << " " << ans2 << "\n";
	return	0;
}