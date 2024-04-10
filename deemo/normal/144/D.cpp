#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const ll max_n = 1e5 + 10;
const ll INF = 1e18;

struct Edge{
	ll v, u, w;
	Edge(ll a, ll b, ll c): v(a), u(b), w(c){}
};

ll n, m, s, d, ans;
vector<pair<ll, ll>>	adj[max_n];
vector<Edge>	edges;
set<pair<ll, ll>>	st;
ll save[max_n];
bool mark[max_n];

void update(ll v){
	mark[v] = 1;
	if (save[v] == d)	
		ans++;
	for (ll i = 0; i < adj[v].size(); i++){
		ll u = adj[v][i].first;
		ll w = adj[v][i].second;
		if (mark[u])	continue;
		if (save[u] > save[v] + w){
			st.erase({save[u], u});
			save[u] = save[v] + w;
			st.insert({save[u], u});
		}
	}
}

ll find_min(){
	pair<ll, ll>	temp = *st.begin();
	st.erase(st.begin());
	return	temp.second;
}

void dijk(ll v){
	fill(save, save + max_n, INF);
	save[v] = 0;
	update(v);
	ll mini;

	while (!st.empty()){
		mini = find_min();
		update(mini);
	}
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &s);	s--;
	for (ll i = 0; i < m; i++){
		ll a, b, c;	scanf("%I64d%I64d%I64d", &a, &b, &c);	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
		edges.pb(Edge(a, b, c));
	}
	scanf("%I64d", &d);
	dijk(s);

	for (ll i = 0; i < m; i++){
		ll a = edges[i].v, b = edges[i].u, c = edges[i].w;
		if (save[a] < save[b])	swap(a, b);
		if (save[b] >= d)	continue;
		if (save[b] + c <= d)	continue;
		double t = double(save[b] + save[a] + c) / 2;
		if (t < d)	continue;
		if (t == d){
			ans++;
			continue;
		}
		ans += 1;
		if (save[a] < d)	ans++;
		continue;
	}
	printf("%I64d\n", ans);
	return 0;
}