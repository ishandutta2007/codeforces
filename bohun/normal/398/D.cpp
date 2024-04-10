#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;

const int P = 500;
const int nax = 3e5 + 11;

map <pair<int, int>, int> id;
int n, m, a, b, q, o;
int deg[nax];
vector <pair<int, int>> v[nax];
int mapa[600005];
int fre = 1;
int online[nax];
int type[nax];
int sum[nax];
vector <pair<int, int>> som[50005];
pair<int, int> edge[nax];

struct query {
	char c;
	vector <int> x;
};

vector <query> Q;

void add(int x, int y, int ind) { // add edge
	mapa[ind] = 1;
	if(type[x] == 0 && type[y] == 1 && online[x])
		sum[y] += 1;
	if(type[x] == 1 && type[y] == 0 && online[y])
		sum[x] += 1;
}

void del(int x, int y, int ind) { // del edge
	mapa[ind] = 0;
	if(type[x] == 0 && type[y] == 1 && online[x])
		sum[y] -= 1;
	if(type[x] == 1 && type[y] == 0 && online[y])
		sum[x] -= 1;
}

void add(int x) { // node
	online[x] = 1;
	if(!type[x]) {
		for(auto it : som[x])
			if(mapa[it.se] == 1)
				sum[it.fi] += 1;
	}
}

void del(int x) {
	online[x] = 0;
	if(!type[x]) {
		for(auto it : som[x])
			if(mapa[it.se] == 1)
				sum[it.fi] -= 1;
	}
}

void solve(int u) {
	int res = sum[u];
	if(!type[u]) {
		for(auto it : v[u])
			if(online[it.fi] && mapa[it.se])
				res += 1;
	}
	else {
		for(auto it : som[u])
			if(online[it.fi] && mapa[it.se])
				res += 1;
	}
	printf("%d\n", res);
}


int main() {	
	scanf("%d %d %d %d", &n, &m, &q, &o);
	FOR(i, 1, o) {
		scanf("%d", &a);
		online[a] = 1;
	}
	FOR(i, 1, m) {
		scanf("%d %d", &a, &b);
		edge[i] = mp(a, b);
		deg[a] += 1;
		deg[b] += 1;
		if(id.find(mp(a, b)) == id.end()) {
			id[mp(a, b)] = id[mp(b, a)] = fre;
			mapa[fre++] = 1;
		}
		v[a].pb(mp(b, id[mp(a, b)]));
		v[b].pb(mp(a, id[mp(a, b)]));
	}
	
	FOR(i, 1, q) {
		query x;
		scanf(" %c", &x.c);
		int ind = ((x.c == 'A' || x.c == 'D') ? 2 : 1);
		while(ind--) {
			scanf("%d", &a);
			x.x.pb(a);
		}
		Q.pb(x);
		if(x.c == 'A') {
			a = x.x[0];
			b = x.x[1];
			
			if(id.find(mp(a, b)) == id.end()) {
				id[mp(a, b)] = id[mp(b, a)] = fre++;
			}
			 
			deg[a] += 1;
			deg[b] += 1;
			v[a].pb(mp(b, id[mp(a, b)]));
			v[b].pb(mp(a, id[mp(a, b)]));
		}
	}
	
	FOR(i, 1, n) {
		if(deg[i] >= P) {
			type[i] = 1;
		}
	}
	
	FOR(i, 1, n) {
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		for(auto it : v[i])
			if(type[it.fi])
				som[i].pb(it);
	}
	
	FOR(i, 1, m)
		add(edge[i].fi, edge[i].se, id[mp(edge[i].fi, edge[i].se)]);
	
	
	for(auto it : Q) {
		if(it.c == 'O')
			add(it.x[0]);
		if(it.c == 'F')
			del(it.x[0]);
		if(it.c == 'A')
			add(it.x[0], it.x[1], id[mp(it.x[0], it.x[1])]);
		if(it.c == 'D')
			del(it.x[0], it.x[1], id[mp(it.x[0], it.x[1])]);
		if(it.c == 'C')
			solve(it.x[0]);
	}
	
	
	
	
	
	
	
	
			
	
	return 0;
}