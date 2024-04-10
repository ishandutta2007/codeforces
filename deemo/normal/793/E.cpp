#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int n, x[4], ss[4], mark[MAXN];
int par[MAXN], sub[MAXN], cnt;
vector<int> adj[MAXN];

void plant(int v, int p = -1){
	if (~p)
		adj[v].erase(find(adj[v].begin(), adj[v].end(), p));

	if (adj[v].empty()) sub[v] = 1;
	par[v] = p;
	for (int u:adj[v])
		plant(u, v), sub[v] += sub[u];
	if (adj[v].empty()) cnt++;
}

bool check(int nd, int u, int v){
	bitset<MAXN> can; can[0] = 1;

	{
		int lst = u;
		while (par[u]){
			u = par[u];
			for (int w:adj[u])
				if (w^lst)
					can |= can<<sub[w];
			lst = u;
		}
	}

	{
		int lst = v;
		while (par[v]){
			v = par[v];
			for (int w:adj[v])
				if (w^lst)
					can |= can<<sub[w];
			lst = v;
		}
	}

	for (int w:adj[0])
		if (mark[w]==-1)
			can |= can<<sub[w];
	return can[nd];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int w = 0; w < 4; w++)
		cin >> x[w], x[w]--;
	for (int i = 1; i < n; i++){
		int a=i, b;	cin >> b, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	plant(0);
	memset(mark, -1, sizeof(mark));
	for (int w = 0; w < 4; w++){
		int v = x[w];
		while (par[v]) v = par[v];
		mark[v] = w;
		ss[w] = sub[v];
	}

	bool fail = 0;
	if (cnt&1) fail = 1;
	else if ((cnt-2>>1) - ss[1] < 0) fail = 1;
	else if ((cnt-2>>1) - ss[2] < 0) fail = 1;
	else{
		fail |= !check((cnt-2>>1) - ss[1], x[0], x[2]);
		fail |= !check((cnt-2>>1) - ss[2], x[1], x[3]);
	}

	if (fail)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}