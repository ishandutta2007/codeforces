#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;

const int MAXN = 1e5 + 20;

int n;
vector<int>	adj[MAXN];
ld ans;

void dfs(int v, int p = -1, ld de = 1){
	ans += ld(1)/de;
	for (int u:adj[v])
		if (u != p)
			dfs(u, v, de + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a>> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	cout << fixed << setprecision(8);
	cout << ans << endl;
	return 0;
}