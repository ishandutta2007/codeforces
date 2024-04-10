#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 1e5 + 10;

ll n, rt, val[MAXN], depth[MAXN], vec[MAXN], sec[MAXN], le[MAXN], ri[MAXN];
ll d[MAXN];
vector<ll>	adj[MAXN];

void init(ll v, ll de = 0){
	depth[v] = de;
	if (adj[v].empty()){
		le[v] = ri[v] = v;
		return;
	}

	if (val[adj[v][0]] > val[v])	swap(adj[v][0], adj[v][1]);
	init(adj[v][0], de + 1);
	le[v] = le[adj[v][0]];
	init(adj[v][1], de + 1);
	ri[v] = ri[adj[v][1]];
}

void glue(ll v, ll p = -1){
	if (~p){	
		d[v] = d[p];
		if (adj[p][0] == v)
			d[v] += val[le[adj[p][1]]];
		else
			d[v] += val[ri[adj[p][0]]];
	}

	for (ll u:adj[v])	glue(u, v);
}

bool cmp(ll u, ll v){return val[u] < val[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll p;	cin >> p >> val[i], p--;
		if (p < 0)
			rt = i;
		else
			adj[p].push_back(i);
	}
	init(rt);
	glue(rt);
	iota(vec, vec + n, 0);
	sort(vec, vec + n, cmp);
	for (ll i = 0; i < n; i++)	sec[i] = val[vec[i]];
	ll q;	cin >> q;
	cout << fixed << setprecision(12);
	while (q--){
		ll x;	cin >> x;
		ll pos = lower_bound(sec, sec + n, x) - sec - 1;
		ll v = 0;
		if (pos == -1)	v = le[rt];
		else if (le[vec[pos]] == vec[pos])	v = vec[pos];
		else v = le[adj[vec[pos]][1]];
		cout << ld(d[v])/ ld(depth[v]) << "\n";
	}
	return	0;
}