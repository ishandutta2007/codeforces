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
const int nax = 400011;

int v = 1;
int fail[nax];
int to[nax][26];
queue <int> q;

int Add(const string &a) {
	int u = 0;
	for(auto it: a) {
		if(!to[u][it - 'a'])
			to[u][it - 'a'] = v++;
		u = to[u][it - 'a'];
	}
	return u;
}

void Aho() {
	q.push(0);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < 26; ++i) {
			if(to[u][i]) {
				fail[to[u][i]] = u == 0 ? 0 : to[fail[u]][i];
				q.push(to[u][i]);
			}
			else {
				to[u][i] = to[fail[u]][i];
			}
		}
	}
}

vector <int> graf[nax];
int in[nax], out[nax];
int Pre = 1;

void dfs(int u) {
	in[u] = Pre++;
	for(auto it: graf[u])
		dfs(it);
	out[u] = Pre;
}
	
int ile[nax];

int fen[nax];

void add(int pos, int val) {
	for(; pos <= v; pos += pos & -pos) 
		fen[pos] += val;
	
}

int sum(int x) {
	int res = 0;
	for(; x > 0; x -= x & -x) 
		res += fen[x];
	return res;
}

vector <int> g[nax];
vector <pair<int, int>> query[nax];

int n;
string s;
int type, x;
int c[nax];
char C;
int ans[nax];

void solve(int u, int cur) {
	if(u > 0)
		cur = to[cur][c[u]];
	add(in[cur], 1);
	for(auto it: query[u]) 
		ans[it.se] = sum(out[it.fi] - 1) - sum(in[it.fi] - 1);
		
	for(auto it: g[u])
		solve(it, cur);
	
	add(in[cur], -1);
}
	

int main() {
	ios;
	cin >> n;
	FOR(i, 1, n) {
		cin >> type;
		if(type == 1) {
			cin >> C;
			c[i] = C - 'a';
			g[0].pb(i);
		}
		else {
			cin >> x >> C;
			c[i] = C - 'a';
			g[x].pb(i);
		}
	}
	
	int Q;
	cin >> Q;
	FOR(i, 1, Q) {
		cin >> x >> s;
		int id = Add(s);
		query[x].pb(mp(id, i));
	}
	
	Aho();
	
	
	FOR(i, 1, v - 1) 
		graf[fail[i]].pb(i);
			
		
	dfs(0);
	
	solve(0, 0);
	
	
	FOR(i, 1, Q)
		cout << ans[i] << endl;
	
	 
	
	
	
	
	
	return 0;
}