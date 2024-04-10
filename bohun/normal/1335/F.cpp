#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

const int nax = 1e6 + 100;

vector <int> g[nax];

int n, m;
char s[nax];
int c[nax];
bool odw[nax];

int id(int row, int col) {
	return row * m + col;
}

int kolor[nax];
vector <int> stos, cycle;
bool ok;
bool oncycle[nax];
int parent[nax];
int H[nax];
bool used[nax];
int where[nax];

vector <int> qw;

void wio(int v, int p, int h) {
	H[v] = h;
	qw.pb(v);
	parent[v] = p;
	odw[v] = 1;
	for (auto it : g[v])
		if (!oncycle[it] && !odw[it])
			wio(it, p, h + 1);
}

void szukaj(int v) {
	kolor[v] = 1;
	stos.pb(v);
	for (auto it : g[v]) {
		//printf ("%d %d\n", v, it);
		if (kolor[it] == 1 && !ok) {
			ok = 1;
			while (stos.back() != it) {
				cycle.pb(stos.back());
				stos.pop_back();
			}
			cycle.pb(it);
		}
		if (kolor[it] == 0)
			szukaj(it);
	}
	if (ss(stos))
	stos.pop_back();
	kolor[v] = 2;
}
			
vector <pair<int, int>> ans;

void solve() {
	scanf ("%d%d", &n, &m);
	rep(i, 0, n - 1) {
		scanf ("%s", s);
		rep(j, 0, m - 1)
			c[id(i, j)] = s[j] - '0';
	}
	rep(i, 0, n - 1) {
		scanf ("%s", s);
		rep(j, 0, m - 1) {
			if (s[j] == 'U') g[id(i - 1, j)].pb(id(i, j));
			if (s[j] == 'D') g[id(i + 1, j)].pb(id(i, j));
			if (s[j] == 'L') g[id(i, j - 1)].pb(id(i, j));
			if (s[j] == 'R') g[id(i, j + 1)].pb(id(i, j));
		}
	}
	
	int black = 0;
	
	rep(i, 0, n * m - 1) {
		if (kolor[i] == 2) continue;
		cycle.clear();
		stos.clear();
		ok = 0;
		szukaj(i);
		if (ok == 0) continue;
		//assert(ok == 1);
		//cat("cycle");
		//for (auto it : cycle) cat(it);
		
		for (auto it : cycle)
			oncycle[it] = 1;
			
		for (auto it : cycle) 
			wio(it, it, 0);
			
		rep(i, 0, ss(cycle) - 1) {
			where[cycle[i]] = i;
			used[i] = 0;
		}
		
		sort(all(qw), [](int a, int b) {
			return c[a] < c[b];
		});
		
		for (auto it : qw) {
			int xd = 123212312 - H[it];
			xd %= ss(cycle);
			int pos = (where[parent[it]] + xd) % ss(cycle);
			if (!used[pos]) {
				used[pos] = 1;
				if (c[it] == 0) black++;
				ans.pb({it / m, it % m});
			}
		}
		
		qw.clear();
		//cat(ss(ans));
		//cat(black);
	}
	
	printf ("%d %d\n", ss(ans), black);
	
	ans.clear();
	stos.clear();
	cycle.clear();
		
	rep(i, 0, n * m - 1) {
		g[i].clear();
		odw[i] = 0;
		kolor[i] = 0;
		oncycle[i] = 0;
		where[i] = 0;
		used[i] = 0;
		H[i] = 0;
		parent[i] = 0;
	}
}	
	

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}