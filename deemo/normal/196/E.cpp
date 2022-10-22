//In these promises broken deep below
//Each word gets lost in the echo..

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 3e5 + 10;
const ll MAXE = 3e5 + 10;
const ll INF = 2e18 + 3;

ll n, m, k, ec;
ll from[2 * MAXE], to[2 * MAXE], prv[2 * MAXE], w[2 * MAXE], head[MAXN], sec[2 * MAXE];
ll comp[MAXN], d[MAXN], ss[MAXN];
bool portal[MAXN], mark[MAXN];
set<pair<ll, ll>>	st;
ll ans = 0;

void add_edge(ll u, ll v, ll c){from[ec] = u, to[ec] = v, w[ec] = c, prv[ec] = head[u];	head[u] = ec++;}

ll get_min(){
	pair<ll, ll>	fr = *st.begin();	
	st.erase(st.begin());
	return	fr.second;
}

void update(ll v){
	mark[v] = 1;
	for (ll e = head[v]; e != -1; e = prv[e]){
		ll u = to[e], c = w[e];
		if (!mark[u] && d[u] > w[e] + d[v]){
			st.erase({d[u], u});
			d[u] = d[v] + w[e];
			st.insert({d[u], u});
			ss[u] = ss[v];
		}
	}
}

void dijk(){
	fill(d, d + MAXN, INF);
	memset(ss, -1, sizeof(ss));
	for (ll i = 0; i < n; i++)
		if (portal[i])	mark[i] = 1, d[i] = 0, ss[i] = i;
	for (ll i = 0; i < n; i++)
		if (portal[i])	update(i);

	while (st.size())
		update(get_min());
}

bool cmp(ll e1, ll e2){
	if (w[e1] != w[e2])
		return	w[e1] < w[e2];
	return	e1 < e2;
}

ll get_comp(ll v){
	if (comp[v] == v)	return	v;
	return	comp[v] = get_comp(comp[v]);
}

void merge(ll e){
	if (get_comp(ss[to[e]]) == get_comp(ss[from[e]]))	return;
	ans += w[e];
	comp[get_comp(ss[to[e]])] = get_comp(ss[from[e]]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	while (m--){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		add_edge(a, b, c);
		add_edge(b, a, c);
	}

	cin >> k;
	while (k--)	{ll temp;	cin >> temp,	temp--, 	portal[temp] = 1;}
	dijk();
	ans = d[0];
	iota(comp, comp + n, 0);
	iota(sec, sec + ec, 0);
	for (int i = 0; i < ec; i++)
		w[i] += d[from[i]] + d[to[i]];
	sort(sec, sec + ec, cmp);
	for (ll e = 0; e < ec; e++)
		merge(sec[e]);
	cout << ans << endl;
	return	0;
}