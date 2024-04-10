//Here we are don't turn away now
//We are the warriors who built this town..

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 22 + 2;
const ll MAXE = 2e6 + 200;//XXX
const ll MAX = 4000;//XXX
const ll INF = 1e18 + 1000;

ll n, m, x, y, ec;
char c[MAXN][MAXN];
ll lvl[MAX];
ll q[MAX * 5];
ll dis[MAX][MAX];
ll from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], prv[2 * MAXE];
ll head[MAX];
ll ptr[MAX];
bool mark[MAX];
vector<pair<ll, ll>>	vec, sec;


bool fit(ll a, ll b){return	a >= 0 && a < n && b >= 0 && b < m;}
ll hhash(ll a, ll b){return	a * m + b;}

void init(){
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			for (ll w = 0; w < n; w++)
				for (ll o = 0; o < m; o++)
					if (i != w || j != o)
						dis[hhash(i, j)][hhash(w, o)] = INF;
	
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++){
			if (c[i][j] == '#')	continue;
			ll h = hhash(i, j);
			if (fit(i + 1, j) && c[i + 1][j] != '#')	dis[h][hhash(i + 1, j)] = 1;
			if (fit(i - 1, j) && c[i - 1][j] != '#')	dis[h][hhash(i - 1, j)] = 1;
			if (fit(i, j + 1) && c[i][j + 1] != '#')	dis[h][hhash(i, j + 1)] = 1;
			if (fit(i, j - 1) && c[i][j - 1] != '#')	dis[h][hhash(i, j - 1)] = 1;
		}	
	for (ll k = 0; k < n * m; k++)
		for (ll i = 0; i < n * m; i++)
			for (ll j = 0; j < n * m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void put_edge(ll u, ll v, ll uv, ll vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v];	head[v] = ec++;
}

void put(ll maxi){
	memset(head, -1, sizeof(head));
	ec = 0;
	ll source = x + y + 2 * n * m;	ll sink = source + 1;
	for (ll i = 0; i < x; i++)
		put_edge(source, i, 1);

	for (ll i = 0; i < x; i++){
		ll h = vec[i].first, v = vec[i].second;
		for (ll j = 0; j < n; j++)
			for (ll w = 0; w < m; w++){
				ll hh = hhash(j, w);
				if (dis[h][hh] == INF)	continue;
				ll time = v * dis[h][hh];
				if (time > maxi)	continue;
				put_edge(i, hh + x, 1);
			}
	}

	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++){
			ll hh = hhash(i, j);//x + n * m 
			hh += x;
			put_edge(hh, hh + n * m, 1);
		}

	for (ll i = 0; i < y; i++){
		ll id = x + 2 * n * m + i;
		ll h = sec[i].first, v = sec[i].second;
		for (ll j = 0; j < n; j++)
			for (ll w = 0; w < m; w++){
				ll hh = hhash(j, w);
				if (dis[h][hh] == INF)	continue;
				ll temp = v * dis[h][hh];
				if (temp > maxi)	continue;
				put_edge(x + hh + n * m, id, 1);
			}
	}		
	for (ll i = 0; i < y; i++){
		ll id = x + 2 * n * m + i;
		put_edge(id, sink, 1);
	}
}

bool bfs(ll v, ll des){
	memset(lvl, -1, sizeof(lvl));
	lvl[v] = 0;
	ll h = 0, t = 0;
	q[t++] = v;

	while (h < t){
		v = q[h++];
		for (ll e = head[v]; e != -1; e = prv[e]){
			ll u = to[e];
			if (cap[e] && (lvl[u] == -1 || lvl[u] > lvl[v] + 1)){
				lvl[u] = lvl[v] + 1;
				q[t++] = u;
			}
		}	
	}
	return	lvl[des] != -1;
}

ll dfs(ll v, ll sink, ll flow = INF){
	if (flow == 0 || v == sink)
		return	flow;

	ll ret = 0;
	for (; ptr[v] != -1; ptr[v] = prv[ptr[v]])
		if (lvl[to[ptr[v]]] == lvl[v] + 1){
			ll xx = dfs(to[ptr[v]], sink, min(flow, cap[ptr[v]]));
			cap[ptr[v]] -= xx;
			cap[ptr[v]^1] += xx;
			flow -= xx;
			ret += xx;
			if (flow == 0)
				break;
		}
	return	ret;
}

ll max_flow(ll source, ll sink){
	ll ret = 0;
	while (bfs(source, sink)){
		memcpy(ptr, head, sizeof(head));
		ret += dfs(source, sink);
	}
	return	ret;
}

int main(){
	cin >> n >> m >> x >> y;
	if ((x + y + 1) % 2){
		cout << -1 << endl;
		return 0;
	}

	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> c[i][j];
	init();
	{
		ll a, b, v;
		cin >> a >> b >> v;	a--, b--;
		if (x < y){
			x++;
			vec.push_back({hhash(a, b), v});
		}
		else	sec.push_back({hhash(a, b), v}), y++;
		
		ll i = 0;
		if (vec.size())	i++;
		for (; i < x; i++){
			cin >> a >> b >> v;	a--, b--;
			vec.push_back({hhash(a, b), v});
		}

		i = 0;
		if (sec.size())	i++;
		for (; i < y; i++){
			cin >> a >> b >> v;	a--, b--;
			sec.push_back({hhash(a, b), v});
		}
	}

	ll b = 0, e = 1e18, mid, ret = -1;
	while (b <= e){
		mid = (b + e)/ 2;
		put(mid);
		if (max_flow(x + y + 2 * n * m, x + y + 2 * n * m + 1) == x){
			e = mid - 1;
			ret = mid;
		}
		else	b = mid + 1;
	}
	cout << ret << endl;
	return 0;
}