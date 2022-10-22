#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second
#define tm alfk

const int MAXN = 1e6 + 10;

int n, k;
vector<int> adj[MAXN];
int st[MAXN], ft[MAXN], tm, depth[MAXN], par[MAXN];
bool picked[MAXN];

void dfs(int v, int p = -1, int de = 0){
	st[v] = tm++;
	par[v] = p;
	depth[v] = de;
	for (int u:adj[v])
		if (u^p)
			dfs(u, v, de+1);
	ft[v] = tm;
}

int fen[MAXN];
void add(int v, int val){for (v++; v<MAXN; v+=v&-v) fen[v] += val;}
int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

void go(int v){
	if (v == -1) return;
	if (picked[v]) return;
	picked[v] = true;
	add(st[v], 1);
	add(ft[v], -1);

	go(par[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k; k = n-k;
	for (int i = 0; i < n-1; i++){
		int a, b; cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(n-1);
	for (int i = n-1; ~i; i--)
		if (!picked[i]){
			int req = depth[i]+1 - get(st[i]+1);
			if (req <= k){
				k -= req;
				go(i);
			}
		}
	for (int i = 0; i < n; i++)
		if (!picked[i])
			cout << i+1 << " ";
	cout << "\n";
	return 0;
}