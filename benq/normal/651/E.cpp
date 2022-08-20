#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin()
#define e end()
 
int n,m;
vector<pii> parent[1000001], hv[1000001], vv[1000001];
vector<vector<pii>> edges[1000001];
vi vals[1000001],  done[1000001];

pii get (pii x) {
	pii k = parent[x.f][x.s];
	if (parent[k.f][k.s] == k) return k;
	else return parent[k.f][k.s] = get(k);
}

void unite(pii a, pii c) {
	a = get(a), c = get(c);
	if (a == c) return;
	parent[c.f][c.s] = a;
}

int dp(pii x) {
	x = get(x);
	if (edges[x.f][x.s].size() == 0) return 1;
	if (done[x.f][x.s]) return done[x.f][x.s];
	sort(edges[x.f][x.s].b, edges[x.f][x.s].e);
	edges[x.f][x.s].erase( unique(edges[x.f][x.s].b, edges[x.f][x.s].e), edges[x.f][x.s].e );
	int ans = 0;
	for(pii i: edges[x.f][x.s]) ans = max(ans,dp(i));
	return done[x.f][x.s] = (ans+1);
}

int main() {
	cin >> n >> m;
	F0R(i,m) parent[i].resize(n), edges[i].resize(n), vals[i].resize(n),  done[i].resize(n);
	F0R(j,n) F0R(i,m) {
		pii x = mp(i,j);
		scanf("%d",&vals[x.f][x.s]), parent[x.f][x.s] = x;
		vv[i].pb(mp(vals[x.f][x.s],j)), hv[j].pb(mp(vals[x.f][x.s],i));
	}
	
	F0R(i,m) {
		sort(vv[i].b, vv[i].e);
		F0R(j,n-1) if (vv[i][j].f == vv[i][j+1].f) unite(mp(i,vv[i][j].s),mp(i,vv[i][j+1].s));
	}
	F0R(j,n) {
		sort(hv[j].b, hv[j].e);
		F0R(i,m-1) if (hv[j][i].f == hv[j][i+1].f) unite(mp(hv[j][i].s,j),mp(hv[j][i+1].s,j));
	}
	
	F0R(i,m) F0R(j,n-1) if (vv[i][j].f < vv[i][j+1].f) {
		pii a = get(mp(i,vv[i][j+1].s));
		pii c = get(mp(i,vv[i][j].s));
		edges[a.f][a.s].pb(c);
	}
	
	F0R(j,n) F0R(i,m-1) if (hv[j][i].f < hv[j][i+1].f) {
		pii a = get(mp(hv[j][i+1].s,j));
		pii c = get(mp(hv[j][i].s,j));
		edges[a.f][a.s].pb(c);
	}
	F0R(j,n) {
		F0R(i,m) printf("%d ", dp(mp(i,j)));
		printf("\n");
	}
	return 0;
}