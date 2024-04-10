#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb(x) push_back(x)

const int MAXN = 1e5 + 10;

int n, sub[MAXN];
char ans[MAXN];
vector<int> adj[MAXN];
bool blocked[MAXN];

void plant(int v, int p = -1){
	sub[v] = 1;
	for (int u:adj[v])
		if (u^p && !blocked[u])
			plant(u, v), sub[v] += sub[u];
}

void go(int v, char cur){
	plant(v);
	int p = -1, tot = sub[v], changed = 1;
	while (changed){
		changed = 0;
		for (int u:adj[v])
			if (u^p && !blocked[u] && sub[u]*2 > tot){
				p = v;
				v = u;
				changed = 1;
				break;
			}
	}

	ans[v] = cur;
	blocked[v] = true;
	for (int u:adj[v])
		if (!blocked[u])
			go(u, cur+1);
	blocked[v] = false;

	//solve for v
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v, u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	go(0, 'A');

	for (int i=0; i < n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return	0;
}