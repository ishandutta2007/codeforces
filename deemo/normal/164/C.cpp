//Rise from bed
//For the ones who sacrificed
//The ones who never cried
//The ones who haven't died
//The ones who are alive
//Tonight..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 4e3 + 10;
const int INF = 1e9 + 10;
const int MAXE = MAXN * 3;

int n, k, tl[MAXN], tr[MAXN], val[MAXN], sec[MAXN], sz;
int from[2 * MAXE], to[2 * MAXE], cost[2 * MAXE], cap[2 * MAXE], head[MAXN], prv[2 * MAXE], ee;
int par[2 * MAXN], d[MAXN];
bool mark[MAXN];
int mp[MAXN];

void add_edge(int u, int v, int z, int cc){
	from[ee] = u, to[ee] = v, cost[ee] = -z, cap[ee] = cc, prv[ee] = head[u], head[u] = ee++;
	from[ee] = v, to[ee] = u, cost[ee] = z, cap[ee] = 0, prv[ee] = head[v], head[v] = ee++;
}

int flow(int source, int sink){
	memset(par, -1, sizeof(par));
	for (int i = 0; i <= sz; i++)	d[i] = INF;
	d[source] = 0;
	for (int i = 0; i <= sz + 2; i++)
		for (int e = 0; e < ee; e++)
			if (cap[e] && d[from[e]] + cost[e] < d[to[e]])
				d[to[e]] = d[from[e]] + cost[e], par[to[e]] = e;
	
	int fl = -1;
	int v = sink;
	while (v ^ source){
		int e = par[v];
		cap[e]--;
		cap[e^1]++;
		v = from[par[v]];
	}
	return d[sink];
}

int get(int source, int sink){
	int ret = 0;
	for (int i = 0; i < k; i++)
		ret += flow(source, sink);
	return ret;
}

int main(){
	memset(head, -1, sizeof(head));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> tl[i] >> tr[i] >> val[i], tr[i] += tl[i], sec[sz++] = tl[i], sec[sz++] = tr[i];
	sort(sec, sec + sz);
	sz = unique(sec, sec + sz) - sec;
	for (int i = 0; i < n; i++){
		tl[i] = lower_bound(sec, sec + sz, tl[i]) - sec;
		tr[i] = lower_bound(sec, sec + sz, tr[i]) - sec;
		mp[i] = ee;
		add_edge(tl[i], tr[i], val[i], 1);
	}
	for (int i = 0; i + 1 < sz; i++)
		add_edge(i, i + 1, 0, k);
	add_edge(sz, 0, 0, k);

	get(sz, sz - 1);
	for (int i = 0; i < n; i++)
		if (cap[mp[i]])
			cout << "0 ";
		else
			cout << "1 ";
	cout << "\n";
	return 0;
}