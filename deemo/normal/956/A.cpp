#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 100 + 3;

int n, m;
string s[MAXN];
vector<int> adj[MAXN];
int ce, ca, cb;
bool vis[MAXN];

void dfs(int v){
	vis[v] = true;
	if (v < n)
		ce += adj[v].size(), ca++;
	else
		cb++;
	for (int u:adj[v])
		if (!vis[u])
			dfs(u);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#')
				adj[i].push_back(n+j), adj[n+j].push_back(i);
	for (int v = 0; v < n+m; v++)
		if (!vis[v]){
			ca = cb = ce = 0;
			dfs(v);
			if (ca*cb != ce){
				cout << "No\n";
				return 0;
			}
		}
	cout << "Yes\n";
	return 0;
}