#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;

int n;
vector<int>	adj[MAXN];
ll c[MAXN], f[MAXN], g[MAXN];

void get(int v, int p = -1){
	ll m1 = 0, m2 = 0;
	for (int u:adj[v])
		if (u != p){
			get(u, v);
			m1 = max(m1, f[u]);
			m2 = min(m2, g[u]);
		}	

	c[v] += m1;
	c[v] += m2;

	f[v] = m1;
	g[v] = m2;

	if (c[v] < 0){
		f[v] -= c[v];
		c[v] = 0;
	}
	else{
		g[v] -= c[v];
		c[v] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++)	cin >> c[i];
	get(0);
	cout << f[0] - g[0] << endl;
	return 0;
}