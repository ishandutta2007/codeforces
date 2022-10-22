#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 10;
const ll MOD = 1e9 + 7;

ll n, m, c[MAXN], mn[MAXN], tt[MAXN], g;
bool vis[MAXN];
vector<ll>	adj[MAXN], rev_adj[MAXN], st;

void top_sort(ll v){
	if (vis[v])	return;
	vis[v] = 1;
	for (ll u:adj[v])
		top_sort(u);
	st.push_back(v);
}

void kosaraju(ll v){
	if (vis[v])	return;
	vis[v] = 1;
	if (mn[g] > c[v]){
		mn[g] = c[v];
		tt[g] = 1;
	}
	else if (mn[g] == c[v])	tt[g]++;
	for (ll u:rev_adj[v])
		kosaraju(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> c[i];
	cin >> m;
	while (m--){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		rev_adj[b].push_back(a);
	}
	for (ll i = 0; i < n; i++)
		top_sort(i);
	reverse(st.begin(), st.end());
	memset(vis, 0, sizeof(vis));
	memset(mn, 63, sizeof(mn));
	ll sum = 0, ans = 1;
	for (ll u:st)
		if (!vis[u]){
			g++;
			kosaraju(u);
			sum += mn[g];
			ans = (ans * tt[g]) % MOD;
		}
	cout << sum << " " << ans << "\n";
	return	0;	
}