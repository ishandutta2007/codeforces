#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 2e5 + 10;

int n, sz[MAXN], par[MAXN];
vector<int>	adj[MAXN];
ld ans[MAXN];

void dfs(int v){
	sz[v] = 1;
	for (int u:adj[v])
		dfs(u), sz[v] += sz[u];
}

void go(int v, ld x = 1){
	int sm = sz[v] - 1;
	ans[v] = x;
	x += 1.;
	for (int u:adj[v])
		go(u, x + (sm-sz[u])/2.);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int p;	cin >> p, p--;
		par[i] = p;
		adj[p].push_back(i);
	}
	dfs(0);
	go(0);
	cout << fixed << setprecision(9);
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}