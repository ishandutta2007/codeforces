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
const int nax = 2e5 + 111;

int n, k, a, b;
bool good[nax];
vector <int> v[nax], kan[nax], e;
int siz[nax];

void dfs(int u, int p) {
	siz[u] = good[u];
	for(auto it : v[u])
		if(it != p) {
			dfs(it, u);
			siz[u] += siz[it];
		}
}

int daj(int u, int p) {
	for(auto it : v[u])
		if(it != p && siz[it] * 2 > siz[1])
			return daj(it, u);
	return u;
}

void go(int u, int p) {
	if(good[u])
		e.pb(u);
	for(auto it : v[u])
		if(it != p)
			go(it, u);
}
		

set <pair<int, int>> secik;

int main() {
	scanf("%d%d", &n, &k);
	FOR(i, 1, n - 1) {
		scanf("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	FOR(i, 1, 2 * k) {
		scanf("%d", &a);
		good[a] = 1;
	}
	dfs(1, 0);
	int cen = daj(1, 0);
	
	for(auto it : v[cen]) {
		e.clear();
		go(it, cen);
		kan[it] = e;
	}
	
	if(good[cen]) {
		int id = 0;
		for(auto it : v[cen]) {
			if(ss(kan[it]) > ss(kan[id]))
				id = it;
		}
		bool ok = 0;
		for(auto it : v[cen]) {
			if(it != id) {
				ok = 1;
				kan[it].pb(cen);
				break;
			}
		}
		if(!ok)
			kan[v[cen][0]].pb(cen);
		
	}
	
	printf("1\n");
	printf("%d\n", cen);
	for(auto it : v[cen]) {
		secik.insert(mp(ss(kan[it]), it));
	}
	
	while(k--) {
		auto a = --secik.end();
		auto b = a;
		b--;
		int A = kan[a->se].back();
		kan[a->se].pop_back();
		int B = kan[b->se].back();
		kan[b->se].pop_back();
		printf("%d %d %d\n", A, B, cen);
		int ile = a->fi;
		int ww = a->se;
		secik.erase(a);
		secik.insert(mp(ile - 1, ww));
		ile = b->fi;
		ww = b->se;
		secik.erase(b);
		secik.insert(mp(ile - 1, ww));
	}
	
	
	
	
	return 0;
}