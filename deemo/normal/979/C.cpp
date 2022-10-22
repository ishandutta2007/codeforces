#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, x, y;
vector<int> adj[MAXN];
int sub[MAXN];

void dfs(int v, int p = -1){
	sub[v] = 1;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v), sub[v] += sub[u];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x >> y, x--, y--;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(y);
	int t1 = sub[x];
	dfs(x);
	int t2 = sub[y];
	ll ans = 1ll*n*(n-1);
	ans -= 1ll*t1*t2;
	cout << ans << endl;
	return 0;
}