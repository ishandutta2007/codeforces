#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int MM = 1e5+5, SZ = MM*3, TOT = SZ*2+MM, ONE = MM, TWO = MM+SZ;

int n, m, ptr, st;
vector<pair<int, ll>> adj[TOT];
ll dis[TOT];

struct Tree{
	#define p (rt>>1)
	#define lc (rt<<1)
	#define rc (rt<<1|1)
	#define nm ((nl+nr)/2)
	void update(int l, int r, int i, ll w, int op, int nl = 1, int nr = MM, int rt = 1){
		if(r < nl or l > nr)
			return;
		if(l <= nl and nr <= r){
			if(op == 2){
				adj[i].emplace_back(rt+ONE, w);
			}
			else{
				adj[rt+TWO].emplace_back(i, w);
			}
			return;
		}
		update(l, r, i, w, op, nl, nm, lc);
		update(l, r, i, w, op, nm+1, nr, rc);
	}
	void build(int nl = 1, int nr = MM, int rt = 1){
		if(rt != 1)
			adj[TWO+rt].emplace_back(TWO+p, 0); //up
		if(nl == nr){
			//to real nodes
			adj[ONE+rt].emplace_back(nl, 0);
			adj[nl].emplace_back(TWO+rt, 0);
			return;
		}
		// down
		adj[MM+rt].emplace_back(MM+lc, 0);
		adj[MM+rt].emplace_back(MM+rc, 0);

		build(nl, nm, lc);
		build(nm+1, nr, rc);
	}

} ST;
// 0 for v -> [l, r] (down ch)
// 1 for [l, r] -> v (up par)
priority_queue<pii, vector<pii>, greater<pii>> q;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m>>st;
	ST.build();
	while(m--){
		int op, a, b, c, l, r;
		cin>>op;
		if(op == 1){
			cin>>a>>b>>c;
			adj[a].emplace_back(b, c);
		}
		else{
			cin>>a>>l>>r>>c;
			ST.update(l, r, a, c, op);
		}
	}

	memset(dis, 0x3f, sizeof dis);
	dis[st] = 0;
	q.emplace(0, st);
	while(q.size()){
		int cur = q.top().second; ll curd = q.top().first; q.pop();
		if(curd > dis[cur])
			continue;

		for(auto e: adj[cur]){
			int u = e.first, w = e.second;
			if(dis[cur] + w < dis[u]){
				q.emplace(dis[u] = dis[cur] + w, u);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(dis[i] == dis[0])
			dis[i] = -1;
		cout<<dis[i]<<' ';
	}
	
	return 0;
}