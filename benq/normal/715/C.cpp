#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second

ll ans,n,M;

struct {
	vector<pii> adj, child;
	map<int,int> val1, val2; // remainder, lengths
	pii t1 = {1,0}, t2 = {1,0};
	int loc, add = 0, sz = 1;
} node[100000];

void EE(int a, int b, int& x, int& y) {
    if(a%b == 0) {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp - y*(a/b);
}

int inv(int a) {
    int x,y;
    EE(a,M,x,y); 
    if(x<0) x += M;
    return x;
}

void dfs1(int p, int cur) {
	for (pii a: node[cur].adj) if (a.f != p) {
		dfs1(cur,a.f);
		node[cur].child.pb(a);
		node[cur].sz += node[a.f].sz;
	}
}

void init() {
	cin >> n >> M;
	F0R(i,n) node[i].loc = i;
	F0R(i,n-1) {
		int u,v,w; cin >> u >> v >> w;
		node[u].adj.pb({v,w});
		node[v].adj.pb({u,w});
	}
	dfs1(-1,0);
}

void test1(int from, pii val, int to) { 
	val.f = (node[from].t1.f*val.f+node[from].t1.s) % M;
	int y = ((-10*val.f-node[to].t2.s)*inv(node[to].t2.f)) % M;
	while (y<0) y += M;
	if (node[to].val2.count(y)) ans += val.s*node[to].val2[y];
} 

void test2(int from, pii val, int to) {
	val.f = (node[from].t2.f*val.f+node[from].t2.s) % M;
	int y = ((-val.f*inv(10)-node[to].t1.s)*inv(node[to].t1.f)) % M;
	while (y<0) y += M;
	if (node[to].val1.count(y)) ans += val.s*node[to].val1[y];
} 

void ins1(int from, pii val, int to) {
	val.f = (node[from].t1.f*val.f+node[from].t1.s) % M;
	int y = ((val.f-node[to].t1.s)*inv(node[to].t1.f)) % M;
	while (y<0) y += M;
	node[to].val1[y] += val.s;
} 

void ins2(int from, pii val, int to) { 
	val.f = (node[from].t2.f*val.f+node[from].t2.s) % M;
	int y = ((val.f-node[to].t2.s)*inv(node[to].t2.f)) % M;
	while (y<0) y += M;
	node[to].val2[y] += val.s;
} 

void dfs2(int cur) {
	int mxchild;
	if (node[cur].child.size() == 0) mxchild = cur; 
	else mxchild = node[cur].child[0].f;
	
	for (pii a: node[cur].child) {
		dfs2(a.f);
		int l = node[a.f].loc;
		node[l].t1.f = (10*node[l].t1.f) % M;
		node[l].t1.s = (10*node[l].t1.s+a.s) % M;
		node[l].t2.f = (inv(10)*node[l].t2.f) % M;
		node[l].t2.s = (inv(10)*node[l].t2.s+a.s) % M;
		if (node[a.f].sz > node[mxchild].sz) mxchild = a.f;
	}
	node[cur].loc = node[mxchild].loc;
	node[cur].val1[0] = node[cur].val2[0] = 1;
	for (pii a: node[cur].child) if (node[a.f].loc != node[cur].loc) {
		int l = node[a.f].loc;
		for (auto b: node[l].val1) test1(l,b,node[cur].loc);
		for (auto b: node[l].val2) test2(l,b,node[cur].loc);
		for (auto b: node[l].val1) ins1(l,b,node[cur].loc);
		for (auto b: node[l].val2) ins2(l,b,node[cur].loc);
	}
	if (cur != node[cur].loc) {
		for (auto b: node[cur].val1) test1(cur,b,node[cur].loc);
		for (auto b: node[cur].val2) test2(cur,b,node[cur].loc);
		for (auto b: node[cur].val1) ins1(cur,b,node[cur].loc);
		for (auto b: node[cur].val2) ins2(cur,b,node[cur].loc);
	}
}

int main() {
	init();
	dfs2(0);
	cout << ans;
}