#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;
vector<int> adj[MAXN];
ll sm = 0, s[MAXN];

void dfs(int v, int de = 0, int p = -1){
	if (de&1)
		s[v] = s[p];
	for (int u:adj[v])
		dfs(u, de+1, v);

	if (adj[v].size() && (de&1)){
		ll mn = 1e18;
		for (int u:adj[v])
			mn = min(mn, s[u]);
		if (s[v] > mn){
			cout << "-1\n";
			exit(0);
		}
		s[v] = mn;
	}
}

void dfs2(int v, int p = -1){
	for (int u:adj[v])
		dfs2(u, v);
	if (p == -1)
		sm += s[v];
	else{
		if (s[v] < s[p]){
			cout << "-1\n";
			exit(0);
		}
		else
			sm += s[v] - s[p];
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++){
		int p; cin >> p, p--;
		adj[p].push_back(i);
	}
	for (int i = 0; i < n; i++) cin >> s[i];
	dfs(0);
	dfs2(0);
	cout << sm << "\n";
	return 0;
}