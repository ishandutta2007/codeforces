#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAXN = 50 + 2;
const int MAX = MAXN * MAXN;//XXX
const int MAXE = 1e7 + 3;//XXX
const ll INF = 1e15 + 1000;
const int FF = 1e9;

ll n, m, x, y;
char c[MAXN][MAXN];
int dis[MAX][MAX];
bool mark[MAX];
int hs[MAXN][MAXN];
vector<pair<ll, ll>>	vec, sec;
ll cap[MAXE];
int from[MAXE], to[MAXE], prv[MAXE], head[MAX], pt[MAX], ec;

bool fit(int a, int b){return	a >= 0 && a < n && b >= 0 && b < m;}
int hhash(int a, int b){return	a * m + b;}

void init(){
	for (int i = 0; i < n * m; i++)
		for (int j = 0; j < n * m; j++)
			if (i != j)	dis[i][j] = FF;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (c[i][j] == '#')	continue;
			ll h = hs[i][j];
			if (fit(i + 1, j) && c[i + 1][j] != '#')	dis[h][hs[i + 1][j]] = 1;
			if (fit(i - 1, j) && c[i - 1][j] != '#')	dis[h][hs[i - 1][j]] = 1;
			if (fit(i, j + 1) && c[i][j + 1] != '#')	dis[h][hs[i][j + 1]] = 1;
			if (fit(i, j - 1) && c[i][j - 1] != '#')	dis[h][hs[i][j - 1]] = 1;
		}	

	for (int k = 0; k < n * m; k++)
		for (int i = 0; i < n * m; i++)
			for (int j = 0; j < n * m; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void addEdge(int u, int v, ll uv, ll vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
}


void put(ll maxi){
	memset(head, -1, sizeof(head)), ec = 0;
	int source = x + y + 2 * n * m;	int sink = source + 1;
	for (int i = 0; i < x; i++)	addEdge(source, i, 1);

	for (int i = 0; i < x; i++){
		ll h = vec[i].first, v = vec[i].second;
		for (int j = 0; j < n; j++)
			for (int w = 0; w < m; w++){
				ll hh = hs[j][w];
				if (dis[h][hh] == FF)	continue;
				ll time = v * dis[h][hh];
				if (time > maxi)	continue;
				addEdge(i, x + hh, 1);
			}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			ll hh = hs[i][j];//x + n * m 
			hh += x;
			addEdge(hh, hh + n * m, 1);
		}

	for (int i = 0; i < y; i++){
		int id = x + 2 * n * m + i;
		ll h = sec[i].first, v = sec[i].second;
		for (int j = 0; j < n; j++)
			for (int w = 0; w < m; w++){
				ll hh = hs[j][w];
				if (dis[h][hh] == FF)	continue;
				ll temp = v * dis[h][hh];
				if (temp > maxi)	continue;
				addEdge(x + hh + n * m, id, 1);
			}
	}		
	for (int i = 0; i < y; i++){
		int id = x + 2 * n * m + i;
		addEdge(id, sink, 1);
	}
}

int lv[MAX], q[MAX];
bool bfs(int source, int sink){
	memset(lv, 63, sizeof(lv));
	int h = 0, t = 0;
	lv[source] = 0;
	q[t++] = source;
	while (t-h){
		int v = q[h++];
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + 1 < lv[to[e]]){
				lv[to[e]] = lv[v] + 1;
				q[t++] = to[e];
			}
	}
	return lv[sink] < 1e8;
}

ll dfs(int v, int sink, ll f = INF) {
	if (v == sink || f == 0)
		return f;
	int ret = 0;
	for (int &e = pt[v]; ~e; e = prv[e])
		if (lv[v]+1 == lv[to[e]]){
			int x = dfs(to[e], sink, min(f, cap[e]));
			cap[e] -= x;
			cap[e^1] += x;
			ret += x;
			f -= x;
			if (!f)
				break;
		}
	return ret;
}

ll dinic(int source, int sink){
	ll ret = 0;
	while (bfs(source, sink)){
		memcpy(pt, head, sizeof(head));
		ret += dfs(source, sink);
	}
	return ret;
}

int main(){
	cin >> n >> m >> x >> y;
	if ((x + y + 1) % 2){
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	hs[i][j] = hhash(i, j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)	cin >> c[i][j];

	init();
	{
		int a, b;
		ll v;
		cin >> a >> b >> v;	a--, b--;
		if (x < y){
			x++;
			vec.push_back({hs[a][b], v});
		}
		else	sec.push_back({hs[a][b], v}), y++;
		
		int i = 0;
		if (vec.size())	i++;
		for (; i < x; i++){
			cin >> a >> b >> v;	a--, b--;
			vec.push_back({hs[a][b], v});
		}

		i = 0;
		if (sec.size())	i++;
		for (; i < y; i++){
			cin >> a >> b >> v;	a--, b--;
			sec.push_back({hs[a][b], v});
		}
	}

	ll b = 0, e = 1e12, mid, ret = -1;
	while (b <= e){
		mid = (b + e)/ 2;
		put(mid);
		if (dinic(x + y + 2 * n * m, x + y + 2 * n * m + 1) == max(x, y)){
			e = mid - 1;
			ret = mid;
		}
		else	b = mid + 1;
	}
	cout << ret << endl;
	return 0;
}