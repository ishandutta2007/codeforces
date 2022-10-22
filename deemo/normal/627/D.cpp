#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<functional>

using namespace std;

const int MAXN = 2e5 + 20;
const int MAXX = 1e6 + 10;

int n, k, val[MAXN];
int d[MAXN], pu[MAXN], sm[MAXN], fin[MAXN], sz[MAXN], mx[MAXN], kk, sec[MAXN], cn[MAXN];
vector<int>	adj[MAXN];
vector<pair<int, int>>	vec[MAXN];

int plant(int v, int p = -1){
	cn[v] = 1;
	for (int u:adj[v])
		if (u != p)	cn[v] += plant(u, v);
	return	cn[v];
}

void dn(int v, int p, int mid){
	sz[v] = bool(val[v] < mid);
	sm[v] = bool(sz[v] == 0);

	for (int u:adj[v])
		if (u != p){
			dn(u, v, mid);
				
			if (sm[v]){
				if (sz[u] == 0)
					sm[v] += sm[u];
				else{
					mx[v] = max(mx[v], sm[u] + mx[u]);
					vec[v].push_back({sm[u] + mx[u], u});
				}
			}
			sz[v] += sz[u];
		}
	sort(vec[v].begin(), vec[v].end(), greater<pair<int, int>>());
}

void up(int v, int p, int mid){
	if (p != -1 && val[p] >= mid && val[v] >= mid){
		d[v] = sm[v];
		if (sz[v] == kk)
			d[v] += n - cn[v];
		else{
			int z = sm[p] - sm[v] * int(sz[v] == 0);
			pu[v] = z + pu[p];
			if (sz[p] == kk)
				z += n - cn[p];

			for (int i = 0; i < 2 && i < (int)vec[p].size(); i++)
				if (vec[p][i].second != v)
					pu[v] = max(pu[v], z + vec[p][i].first);
		}
	}
	fin[v] = max(sm[v], d[v]) + max(pu[v], mx[v]);

	for (int u:adj[v])
		if (u != p)
			up(u, v, mid);
}

void init(){
	for (int i = 0; i < n; i++)
		vec[i].clear();
	memset(sz, 0, sizeof(sz));
	memset(d, 0, sizeof(d));
	memset(pu, 0, sizeof(pu));
	memset(sm, 0, sizeof(sm));
	memset(fin, 0, sizeof(fin));
	memset(mx, 0, sizeof(mx));
}

int get(int mid){
	kk = lower_bound(sec, sec + n, mid) - sec;
	init();
	dn(0, -1, mid);
	up(0, -1, mid);
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret = max(ret, fin[i]);
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> val[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memcpy(sec, val, sizeof(val));
	sort(sec, sec + n);
	plant(0);
	
	int b = 1, e = MAXX, ret = 0; 
	while (b <= e){
		int mid = (b + e)/ 2;
		if (get(mid) >= k)
			ret = mid, b = mid + 1;
		else
			e = mid - 1;
	}
	cout << ret << "\n";
	return	0;
}