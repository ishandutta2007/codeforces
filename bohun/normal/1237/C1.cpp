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

const int nax = 50005;
const int mod = 1e9 + 7;

pair< pair<int, int>, pair<int, int>> t[nax];

int a, b, c, n;

vector <pair<int, int>> res;
map <pair<int, int>, vector <int>> mapa;
map <int, vector <int> > X;
vector <int> ha;

bool done[nax];

int main() {	
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d %d %d", &a, &b, &c);
		t[i] = mp(mp(a, b), mp(c, i));
		mapa[mp(a, b)].pb(i);
	}
	for(auto it : mapa) {
		sort(it.se.begin(), it.se.end(), [](int a, int b) {
			return t[a].se.fi < t[b].se.fi;
		});
		for(int i = 0; i + 1 < ss(it.se); i += 2) {
			int id1 = t[it.se[i]].se.se;
			int id2 = t[it.se[i + 1]].se.se;
			done[id1] = done[id2] = 1;
			res.pb(mp(id1, id2));
		}
	}
	
	FOR(i, 1, n) {
		if(!done[i])
			X[t[i].fi.fi].pb(i);
	}
	
	for(auto it : X) {
		sort(it.se.begin(), it.se.end(), [](int a, int b) {
			return t[a].fi.se < t[b].fi.se;
		});
		for(int i = 0; i + 1 < ss(it.se); i += 2) {
			int id1 = t[it.se[i]].se.se;
			int id2 = t[it.se[i + 1]].se.se;
			done[id1] = done[id2] = 1;
			res.pb(mp(id1, id2));
		}
	}
	
	FOR(i, 1, n) {
		if(!done[i]) {
			ha.pb(i);
		}
	}
	
	sort(ha.begin(), ha.end(), [](int a, int b) {
		return t[a].fi.fi < t[b].fi.fi;
	});
	
	for(int i = 0; i < ss(ha); i += 2) {
			int id1 = t[ha[i]].se.se;
			int id2 = t[ha[i + 1]].se.se;
			done[id1] = done[id2] = 1;
			res.pb(mp(id1, id2));
	}
	
	for(auto it : res)
		printf("%d %d\n", it.fi, it.se);
	
	
		
	
	
	
	
	
	
		
	
	
				
	return 0;
}