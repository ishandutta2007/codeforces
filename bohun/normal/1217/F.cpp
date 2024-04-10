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
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const int nax = 2e5 + 111, base = 1e6;
int block;

int n, m, a, b;
int t[nax][3];
vector <int> ans;

struct uf {
	int p[nax];
	
	void init() {
		FOR(i, 1, n)
			p[i] = i;
	}
	
	int Find(int x) {
		if(x == p[x])
			return x;
		return p[x] = Find(p[x]);
	}
	
	void Onion(int x, int y) {
		x = Find(x);
		y = Find(y);
		if(x == y)
			return;
		p[x] = y;
	}
};

uf ja;

bool True[nax];

vector <int> used;
vector <pair<int, int>> good;
unordered_map <ll, int > bad, Last, mam;
unordered_map <int, int> graf[nax];

inline ll hasz(int x, int y) {
	return x + (ll) base * y;
}

void akt(int u) {
	int x = (t[u][1] - 1) % n + 1;
	int y = (t[u][2] - 1) % n + 1;
	if(x > y)
		swap(x, y);
	bad[hasz(x, y)] = 1;
	x = t[u][1] % n + 1;
	y = t[u][2] % n + 1;
	if(x > y)
		swap(x, y);
	bad[hasz(x, y)] = 1;
}

int LAST = 0;
	
inline void Add(int x, int y, int id) {
	if(ja.Find(x) == ja.Find(y))
		return;
	assert(x < y);
	if(mam.find(hasz(x, y)) == mam.end()) {
		if(id) {
			True[id] = 1;
			Last[hasz(x, y)] = id;
		}
		
		mam[hasz(x, y)] = 1;
		int X = ja.Find(x);
		int Y = ja.Find(y);
		graf[X][Y] += 1;
		graf[Y][X] += 1;
	}
	else {
		assert(id > 0);
		True[Last[hasz(x, y)]] = 0;
			
		mam.erase(hasz(x, y));
		
		int X = ja.Find(x);
		int Y = ja.Find(y);
		
		graf[X][Y] -= 1;
		graf[Y][X] -= 1;
		
		if(graf[X][Y] == 0)
			graf[X].erase(Y);
		if(graf[Y].find(X) != graf[Y].end() && graf[Y][X] == 0)
			graf[Y].erase(X);
	}
}

bool Odw[nax];

void dfs(int u) {
	used.pb(u);
	Odw[u] = 1;
	for(auto it: graf[u]) {
		if(!Odw[it.fi])
			dfs(it.fi);
	}
}

void solve(int l, int r) {
	bad.clear();
	good.clear();
	mam.clear();
	
	FOR(i, 1, n) 
		graf[i].clear();
	
	
	FOR(i, 1, l - 1) 
		if(t[i][0] == 1 && True[i])
			good.pb(mp(t[i][1], t[i][2]));
	
	FOR(i, l, r) 
		if(t[i][0] == 1) 
			akt(i);
	
	ja.init();
	for(auto it: good) {
		if(bad.find(hasz(it.fi, it.se)) == bad.end()) {
			int x = it.fi;
			int y = it.se;
			ja.Onion(x, y);
		}
		else 
			Add(it.fi, it.se, 0);
		
	}
	
	FOR(i, l, r) {
		if(t[i][0] == 1) {
			int xx = (t[i][1] + LAST - 1) % n + 1;
			int yy = (t[i][2] + LAST - 1) % n + 1;
			
			if(xx > yy)
				swap(xx, yy);
				
			t[i][1] = xx;
			t[i][2] = yy;
				
			Add(xx, yy, i);
		}
		if(t[i][0] == 2) {
			int xx = (t[i][1] + LAST - 1) % n + 1;
			int yy = (t[i][2] + LAST - 1) % n + 1;
	
			xx = ja.Find(xx);
			yy = ja.Find(yy);
			
			used.clear();
			
			dfs(xx);
			
			LAST = (Odw[yy] == 1);
			ans.pb(LAST);
			
			for(auto it: used)
				Odw[it] = 0;
		}
	}
	
	
}		
	
	
	
int main() {	
	ios;
	cin >> n >> m;
	FOR(i, 1, m) {
		FOR(j, 0, 2)
			cin >> t[i][j];
		if(t[i][1] > t[i][2])
			swap(t[i][1], t[i][2]);
	}
	
			
	block = 500;;
	
	for(int i = 1; i <= m; i += block)
		solve(i, min(m, i + block - 1));
	
	for(auto it: ans)
		cout << it;
	
	
	
	
	
	return 0;
}