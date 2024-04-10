#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if(i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

mt19937 rnd(time(NULL));

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 150 * 1000 + 11;

int n, m;
vector<int> g[N];

bool read () {
	if (scanf("%d %d", &n, &m) != 2)
		return false;
	forn(i, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x, --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	return true;
}

bool used[N];
int szc;
vector<int> vert;

void dfs(int v) {
	used[v] = true;
	szc++;
	vert.pb(v);
	for(auto to : g[v]) {
		if(!used[to])
			dfs(to);
	}
}

void solve() {
	forn(i, n) {
		if(!used[i]) {
			vert.clear();
			dfs(i);
		}
		forn(j, sz(vert)) {
			if(sz(g[vert[j]]) != sz(vert) - 1) {
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int tt = clock();
	
#endif
	
	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while(read()) {	
		solve();
		
#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	}
}