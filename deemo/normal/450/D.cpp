#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const ll MAXN = 1e6 + 10;
const int MAXE = 1e6 + 10;

ll n, m, k, cnt, ec;
bool mark[MAXN];
ll depth[MAXN];
vector<int>	par[MAXN];
set<pair<ll, ll>>	st;
int head[MAXN], from[MAXE], to[MAXE], w[MAXE], prv[MAXE];
bool f[MAXE];

void add_edge(int a, int b, int c, bool fl = 0){
	from[ec] = a, to[ec] = b, f[ec] = fl, w[ec] = c, prv[ec] = head[a];	head[a] = ec++;
	from[ec] = b, to[ec] = a, f[ec] = fl, w[ec] = c, prv[ec] = head[b];	head[b] = ec++;
}

ll get_min(){
	pair<ll, ll>	temp = *st.begin();
	st.erase(st.begin());
	return	temp.second;
}

void update(ll v){
	mark[v] = 1;
	for (int e = head[v]; e != -1; e = prv[e]){
		int u = to[e], c = w[e];
		if (mark[u])	continue;

		if (depth[u] > depth[v] + c){
			st.erase({depth[u], u});
			depth[u] = depth[v] + c;
			st.insert({depth[u], u});

			par[u].clear();
			par[u].push_back(e);
		}
		else if (depth[u] == depth[v] + c)
			par[u].push_back(e);
	}
}

void dijk(ll v){
	fill(depth, depth + MAXN, INF);
	depth[v] = 0;
	update(v);

	while (st.size())
		update(get_min());
}

void check(int v){
	int c1 = 0, c2 = 0;
	for (int e:par[v]){
		if (f[e])	c2++;
		else	c1++;
	}

	if (c1 == 0)
		cnt++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	memset(head, -1, sizeof(head));

	while (m--){
		ll a, b, c;	cin >> a >> b >> c;	a--, b--;
		add_edge(a, b, c);
	}

	for (int i = 0; i < k; i++){
		ll v,	c;	cin >> v >> c;	v--;
		add_edge(0, v, c, 1);
	}
	dijk(0);
	
	for (int i = 1; i < n; i++)
		check(i);

	cout << k - cnt << endl;
	return	0;
}