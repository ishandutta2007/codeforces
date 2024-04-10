#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m, k, z;
vector<int>	adj[MAXN], ans;
int depth[MAXN], nxt[MAXN];
bool mark[MAXN];

void get(int v, int de = 0){
	depth[v] = de;
	mark[v] = de;
	for (int u:adj[v])
		if (!mark[u]){
			nxt[v] = u;
			get(u, de + 1);
			return;
		}
		else{
			if (de - depth[u] >= k){
				nxt[v] = u;
				z = u;
				return;
			}
		}
}

void show(int v){
	mark[v] = 1;
	ans.push_back(v);
	if (mark[nxt[v]])	return;
	show(nxt[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	get(0);
	fill(mark, mark + MAXN, 0);
	show(z);
	
	cout << (int)ans.size() << endl;
	for (int v:ans)
		cout << v + 1 << " ";
	cout << endl;
	return	0;
}