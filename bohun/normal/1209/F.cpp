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

const int nax = 2e6 + 111;
const int mod = 1e9 + 7;

int n, m;
int a, b;
vector <int> dig;
vector <pair<int, int>> v[nax];
int all;
int zmod[nax];
bool odw[nax];
int nr[nax];
vector <int> nodes, to;
pair<int, int> gao[nax];

void add(int l, int r, vector <int> &x, int g = 0) {
	if(g == ss(x) - 1) {
		v[l].pb(mp(r, x[0]));
		v[r].pb(mp(l, x[ss(x) - 1]));
		return;
	}
	int u = all++;
	v[u].pb(mp(r, x[ss(x) - 1 - g]));
	v[r].pb(mp(u, x[g]));
	add(l, u, x, g + 1);
}
		

int main() {	
	scanf("%d%d", &n, &m);
	all = n + 1;
	FOR(i, 1, m) {
		scanf("%d%d", &a, &b);
		dig.clear();
		int c = i;
		while(c > 0) {
			dig.pb(c % 10);
			c /= 10;
		}
		reverse(dig.begin(), dig.end());
		add(a, b, dig);
	}
	
	FOR(i, 1, all - 1)
		gao[i] = mp(-1, -1);
	nodes.pb(1);
	odw[1] = 1;
	
	while(!nodes.empty()) {
		// fazy //
		to.clear();
		for(auto it : nodes) {
			for(auto g : v[it]) {
				if(odw[g.fi])
					continue;
				if(gao[g.fi] == mp(-1, -1))
					gao[g.fi] = mp(it, g.se);
				else {
					if(nr[it] != nr[gao[g.fi].fi]) {
						if(nr[it] < nr[gao[g.fi].fi])
							gao[g.fi] = mp(it, g.se);
					}
					else if(g.se < gao[g.fi].se)
						gao[g.fi] = mp(it, g.se);
				}
				to.pb(g.fi);
			}
		}
		sort(to.begin(), to.end());
		to.erase(unique(to.begin(), to.end()), to.end());
		
		sort(to.begin(), to.end(), [](int a, int b) {
			if(nr[gao[a].fi] != nr[gao[b].fi])
				return nr[gao[a].fi] < nr[gao[b].fi];
			return gao[a].se < gao[b].se;
		});
		
		nodes.clear();
		int id = 0;
		pair<int, int> Last = mp(-1, -1);
		for(auto it : to) {
			if(mp(nr[gao[it].fi], gao[it].se) != Last)
				id += 1;
			odw[it] = 1;
			nodes.pb(it);
			zmod[it] = ((ll) zmod[gao[it].fi] * 10 + gao[it].se) % mod;
			nr[it] = id;
			Last = mp(nr[gao[it].fi], gao[it].se);
		}
	}
	
	FOR(i, 2, n)
		printf("%d\n", zmod[i]);	
	
	
	return 0;
}