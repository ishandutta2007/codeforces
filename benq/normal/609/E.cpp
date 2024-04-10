#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

int n,m, anc[200000], parent[200000][20], depth[200000];
ll weight[200000][20], ans;
bool used[200000];
vector<pair<int,pii>> edge, edge1;
vector<pii> nei[200000];

int get(int ind) {
	int k = anc[ind];
	if (anc[k] != k) return anc[ind] = get(k);
	return k;
}

void dfs(int node, int par) {
	for (pii i: nei[node]) if (i.f != par) {
		parent[i.f][0] = node, weight[i.f][0] = i.s, depth[i.f] = depth[node]+1;
		F0R(j,19) {
			parent[i.f][j+1] = parent[parent[i.f][j]][j];
			weight[i.f][j+1] = max(weight[i.f][j],weight[parent[i.f][j]][j]);
		}
		dfs(i.f,node);
	}
}

ll query(pair<int,pii> x) {
	int a = x.s.f, b = x.s.s;
	ll max1 = 0;
	if (depth[a]>depth[b]) swap(a,b);
	int y = depth[b]-depth[a];
	F0R(i,20) {
		if (y & 1) {
			max1 = max(max1,weight[b][i]);
			b = parent[b][i];
		}
		y /= 2;
	}
	for (int i = 19; i >= 0; --i) if (parent[a][i] != parent[b][i]) {
		max1 = max(max1,max(weight[a][i],weight[b][i]));
		a = parent[a][i], b = parent[b][i];
	}
	if (a != b) max1 = max(max1, max(weight[b][0],weight[a][0]));
	return ans+(ll)x.f-max1;
}

int main() {
	scanf("%d%d",&n,&m);
	F0R(i,m) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge.pb(mp(w,mp(u-1,v-1)));
	}
	edge1 = edge;
	F0R(i,200000) anc[i] = i;
	sort(edge.begin(), edge.end());
	int z = 0;
	F0R(i,edge.size()) {
		int a = edge[i].s.f, b = edge[i].s.s;
		int c = get(a), d = get(b);
		if (c>d) swap(c,d);
		if (c != d) {
			anc[d] = c, ans += edge[i].f;
			nei[a].pb(mp(b,edge[i].f)), nei[b].pb(mp(a,edge[i].f));
		}
	}
	dfs(0,0);
	for (auto i: edge1) cout << query(i) << endl;
}