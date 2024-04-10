#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

vvi G,T;

map<pii,int> edge;
const int N = 3e5+5;

int d[N], parent[N];
bool vis[N] = {};
void get_tree(int u, int v) {
	if(u != -1) {
		T[u].pb(v);

	}
	// cout << u << " -> " << v << endl;
	parent[v] = u;
	vis[v] = true;
	for(int w : G[v]) {
		if(vis[w]) continue;
		get_tree(v,w);
	}
}


vector<int> neg1;
vector<pii> subset;
set<int> ans;

int find_ans(int v) {
	int parity = d[v];
	for(int w : T[v]) {
		parity ^= find_ans(w);
	}
	if(parity) {
		pii p(parent[v],v);
		if(p.fi > p.se) swap(p.fi,p.se);
		subset.pb(p);
	}
	return parity;
}

int main() {	
	int n,m;
	scanf("%d%d",&n,&m);
	G = T = vvi(n);
	bool parity = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d",d+i);
		if(d[i] == -1)
			neg1.pb(i);
		else
			parity ^= d[i];
	}

	for(int i = 0; i < m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v),--u,--v;
		if(v < u) swap(u,v);
		edge[pii(u,v)] = i+1;
		G[u].pb(v), G[v].pb(u);
	}

	get_tree(-1,0);

	if(parity == 1) {
		if(neg1.empty()) {
			printf("-1\n");
			return 0;
		} else {
			d[neg1.back()] = 1;
			neg1.pop_back();
		}
	}
	for(int i : neg1)
		d[i] = 0;
	find_ans(0);
	printf("%d\n",int(subset.size()));
	for(auto &e : subset) {
		ans.insert(edge[e]);
	}
	for(int i : ans)
		printf("%d\n",i);

}