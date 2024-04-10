//And if you fall I'll get you there I'll get you there
//I'll be your savior from all the wars that are fought inside your world
//please have faith in my words..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e5 + 10;

int n, from[MAXN], to[MAXN], sz[MAXN], depth[MAXN];
ld w[MAXN];
ld sum;
vector<int>	adj[MAXN];

ld get(ld x){return	x * (x - 1)/ 2;}

int plant(int v, int p = -1, int de = 0){
	depth[v] = de;
	sz[v] = 1;
	for (int e:adj[v]){
		int u = from[e] == v?to[e]:from[e];
		if (u != p){
			sz[v] += plant(u, v, de + 1);
			sum += (ld)sz[u] * get(n - sz[u]) * 6.0 * w[e];
			sum += get(sz[u]) * ld(n - sz[u]) * 6.0 * w[e];
		}
	}
	return	sz[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		cin >> from[i] >> to[i] >> w[i];	from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	plant(0);

	int q;	cin >> q;
	ld temp = ld(n) * ld(n - 1) * ld(n - 2);
	cout << fixed << setprecision(12);
	while (q--){
		int e, x;	cin >> e >> x;	e--;
		int u = from[e], v = to[e];
		if (depth[u] > depth[v])	swap(u, v);
		sum -= (ld)sz[v] * get(n - sz[v]) * 6.0 * w[e];
		sum -= get(sz[v]) * ld(n - sz[v]) * 6.0 * w[e];
		w[e] = x;
		sum += (ld)sz[v] * get(n - sz[v]) * 6.0 * w[e];
		sum += get(sz[v]) * ld(n - sz[v]) * 6.0 * w[e];
		cout << sum * 2.0/temp << "\n";
	}
	return	0;
}