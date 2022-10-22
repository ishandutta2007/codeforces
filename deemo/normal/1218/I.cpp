#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
string s[MAXN], t[MAXN], bar;
vector<int> adj[MAXN];
vector<int> revAdj[MAXN];

void addEdge(int u, int v){
	adj[u].push_back(v);
	revAdj[v].push_back(u);
}

void addClause(int u, int v){
	addEdge(u^1, v);
	addEdge(v^1, u);
}

void failed(){
	cout << "-1\n";
	exit(0);
}

int sec[MAXN], sz;
bool vis[MAXN];
void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;

	for (int u: adj[v])
		dfs(u);
	sec[sz++] = v;
}

int comp[MAXN], gg;
int ord[MAXN], tt;
void revDfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	comp[v] = gg;

	for (int u: revAdj[v])
		revDfs(u);
	ord[v] = tt++;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	cin >> bar;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			int mask = 0;
			if (bar[j] == '1') mask |= 1;
			if (bar[i] == '1') mask |= 2;
			if (s[i][j] != t[i][j]){//should change
				if (mask == 0) failed();
				if (mask == 3){//both
					addClause(i<<1^1, n+j<<1^1);
					addClause(i<<1, n+j<<1);
				}
				else{//only one
					if (mask == 1)
						addClause(i<<1, i<<1);
					else
						addClause(n+j<<1, n+j<<1);
				}
			}
			else{//shouldn't change
				if (mask == 0) continue;
				if (mask == 3){
					addClause(i<<1, n+j<<1^1);
					addClause(i<<1^1, n+j<<1);
				}
				else{
					if (mask == 1)
						addClause(i<<1^1, i<<1^1);
					else
						addClause(n+j<<1^1, n+j<<1^1);
				}
			}
		}
	for (int v = 0; v < n<<2; v++)
		if (!vis[v])
			dfs(v);
	reverse(sec, sec + sz);
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < sz; i++){
		int v = sec[i];
		if (!vis[v]){
			revDfs(v);
			gg++;
		}
	}

	for (int i = 0; i < n<<1; i++)
		if (comp[i<<1] == comp[i<<1^1])
			failed();
	vector<pair<string, int>> vec;
	for (int i = 0; i < n<<1; i++)
		if (ord[i<<1] > ord[i<<1^1]) {
			if (i < n)
				vec.push_back({"row", i+1});
			else
				vec.push_back({"col", i-n+1});
		}
	cout << vec.size() << "\n";
	for (auto x: vec)
		cout << x.first << " " << x.second-1 << "\n";
	return 0;
}