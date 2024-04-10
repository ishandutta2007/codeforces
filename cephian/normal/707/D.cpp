#include <iostream>
#include <vector>

using namespace std;

struct op {
	int type;
	int i,j;
	
	op(int _type, int _i, int _j) {
		type = _type;
		i = _i;
		j = _j;
	}
};

typedef pair<int,op> pio;
typedef vector<vector<pio> > graph;

graph G;
const int Q = 100005;
int where[Q],n,m,q,nm;
int ans[Q];

const int NM = 1000006;
bool lazy[4*NM]={0};
int segt[4*NM]={0};

int gl(int v, int l, int r) {
	return lazy[v]?r-l+1-segt[v]:segt[v];
}

void prop(int v) {
	lazy[v*2]^=lazy[v];
	lazy[v*2+1]^=lazy[v];
	lazy[v]=0;
}

void recalc(int v, int l, int r) {
	segt[v] = gl(v*2,l,(l+r)/2)+gl(v*2+1,(l+r)/2+1,r);
}

int query(int v, int l, int r, int i, int j) {
	if(j < l || r < i) {
		return 0;
	}
	if(i <= l && r <= j) {
		return gl(v,l,r);
	}
	prop(v);
	recalc(v,l,r);
	return query(v*2,l,(l+r)/2,i,j) + query(v*2+1,(l+r)/2+1,r,i,j);
}

void flip(int v, int l, int r, int i, int j) {
	if(j < l || r < i) {
		return;
	}
	if(i <= l && r <= j) {
		lazy[v]^=1;
		return;
	}
	prop(v);
	flip(v*2,l,(l+r)/2,i,j);
	flip(v*2+1,(l+r)/2+1,r,i,j);
	recalc(v,l,r);
}

void apply_op(op& o) {
	if(o.type == -1) return;
	if(o.type == 1) {
		int loc = o.j + (o.i-1)*m;
		if(query(1,1,nm,loc,loc)) {
			o.type = -1;
			return;
		}
		flip(1,1,nm,loc,loc);
		o.type = 2;
	} else if(o.type == 2) {
		int loc = o.j + (o.i-1)*m;
		if(!query(1,1,nm,loc,loc)) {
			o.type = -1;
			return;
		}
		flip(1,1,nm,loc,loc);
		o.type = 1;
	} else {
		flip(1,1,nm,1+(o.i-1)*m,(o.i)*m);
	}
}

void dfs(int v, int f, op& o) {
	apply_op(o);
	
	ans[v] = query(1,1,nm,1,nm);
	for(int i = 0; i < G[v].size(); ++i) {
		if(G[v][i].first == f) continue;
		dfs(G[v][i].first,v,G[v][i].second);
	}

	apply_op(o);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m >> q;
	nm = n*m;
	where[0] = 0;
	G.push_back(vector<pio>());
	
	for(int l = 1; l <= q; ++l) {
		int type,i,j;
		cin >> type >> i;
		if(type == 4) {
			where[l] = where[i];
		} else {
			if(type != 3) cin >> j;
			where[l] = G.size();
			op o(type,i,j);
			G[where[l-1]].push_back(pio(where[l],o));
			G.push_back(vector<pio>());
		}
	}
	op o(-1,-1,-1);
	dfs(0,-1,o);
	for(int l = 1; l <= q; ++l) {
		cout << ans[where[l]] << "\n";
	}
	return 0;
}