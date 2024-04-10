#include<bits/stdc++.h>

using namespace std;

#define FAILURE {printf("No\n");	exit(0);}
#define F first
#define S second

const int MAXN = 5e4 + 10;
const int XX = 2e6 + 10;

int n, m, sz;
int from[MAXN], to[MAXN], col[MAXN], w[MAXN];
vector<int>	adj[MAXN];
int _from[XX], _to[XX], _prv[XX], _head[XX], ec;
int _rfrom[XX], _rto[XX], _rprv[XX], _rhead[XX], rec;

bool cmpCol(int e1, int e2){return col[e1] < col[e2];}

void addEdge(int x, int y){
	_from[ec] = x, _to[ec] = y, _prv[ec] = _head[x], _head[x] = ec++;
	_rfrom[rec] = y, _rto[rec] = x, _rprv[rec] = _rhead[y], _rhead[y] = rec++;
}	

void addClause(int x, int y){
	addEdge(y^1, x);
	addEdge(x^1, y);
}

pair<int, int> getSpace(int req){
	pair<int, int> ret(sz, sz + req);
	sz += req;
	return ret;
}

int sArr[XX], tz, comp[XX], cmpCnt;
short compType[XX];
bool vis[XX];

void tSort(int v, int mid){
	if (vis[v])	return;
	vis[v] = 1;
	for (int e = _head[v]; ~e; e = _prv[e])
		tSort(_to[e], mid);
	if ((v & 1) == 0 && v>>1 < m && w[v>>1] > mid)
		tSort(v^1, mid);
	sArr[tz++] = v;
}

void kosaraju(int v, int curCmp, int mid){
	if (vis[v])	return;
	vis[v] = 1;
	comp[v] = curCmp;
	for (int e = _rhead[v]; ~e; e = _rprv[e])
		kosaraju(_rto[e], curCmp, mid);
	if ((v & 1) && v>>1 < m && w[v>>1] > mid)
		kosaraju(v^1, curCmp, mid);
}

bool cmp(int u, int v){return comp[u] < comp[v];}

bool ok(int mid){
	tz = cmpCnt = 0;

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < sz<<1; i++)
		if (!vis[i])
			tSort(i, mid);
	reverse(sArr, sArr + tz);
	memset(vis, 0, sizeof(vis));	cmpCnt = 0;
	for (int i = 0; i < tz; i++)
		if (!vis[sArr[i]])
			kosaraju(sArr[i], cmpCnt++, mid);

	for (int i = 0; i < sz; i++)
		if (comp[i<<1] == comp[i<<1^1])
			return false;

	sort(sArr, sArr + tz, cmp);
	memset(compType, 0, sizeof(compType));
	for (int i = tz - 1; ~i; i--){
		int v = sArr[i];
		int cc = comp[v];
		if (compType[cc]){
			compType[comp[v^1]] = 3 - compType[cc];
			continue;
		}
		
		compType[comp[v]] = 1;
		compType[comp[v^1]] = 2;
	}

	return true;
}

int main(){
	{
		scanf("%d %d", &n, &m);
		sz = m;
		for (int e = 0; e < m; e++){
			scanf("%d %d %d %d", &from[e], &to[e], &col[e], &w[e]), from[e]--, to[e]--;
			adj[from[e]].push_back(e);
			adj[to[e]].push_back(e);
		}

		memset(_head, -1, sizeof(_head));
		memset(_rhead, -1, sizeof(_rhead));
		for (int i = 0; i < n; i++){
			sort(adj[i].begin(), adj[i].end(), cmpCol);
			for (int l = 0; l < adj[i].size();){
				int r = l;
				while (r < adj[i].size() && col[adj[i][l]] == col[adj[i][r]])	r++;
				if (r - l > 2)
					FAILURE

				if (l + 1 < r)
					addClause(adj[i][l]<<1, adj[i][l + 1]<<1);
				l = r;
			}

			pair<int, int>	seg = getSpace(adj[i].size());
			for (int j = 0; j < adj[i].size(); j++)
				addClause(adj[i][j]<<1^1, seg.F+j<<1);
			for (int j = 1; j < adj[i].size(); j++)
				addClause(seg.F+j-1<<1^1, seg.F+j<<1);
			for (int j = 0; j + 1 < adj[i].size(); j++)
				addClause(seg.F+j<<1^1, adj[i][j+1]<<1^1);
		}
	}

	int b = 0, e = 1e9, ret = 2e9;
	while (b <= e){
		int mid = b+e>>1;
		if (ok(mid))
			ret = mid, e = mid - 1;
		else
			b = mid + 1;
	}
	if (ret > 1e9)
		FAILURE

	ok(ret);
	{
		printf("Yes\n");
		int cnt = 0;
		for (int e = 0; e < m; e++)
			if (compType[comp[e<<1]] == 1)	cnt++;
		printf("%d %d\n", ret, cnt);
		for (int e = 0; e < m; e++)
			if (compType[comp[e<<1]] == 1)
				printf("%d ", e + 1);
		printf("\n");
	}
	return 0;
}