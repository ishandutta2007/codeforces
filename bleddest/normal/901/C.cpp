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

template<class A, class B> ostream& operator << (ostream &out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, const vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 300043;

int n, m;
vector<int> g[N];
bool used[N];
int T, tin[N], fup[N];
vector<int> curv;
set<pt> bridge;
int used2[N];
 
void dfs(int v, int p = -1) {
	if (used[v]) return;
	used[v] = true;
	tin[v] = fup[v] = T++;
	for(auto to : g[v])
	{
		if (to == p)  continue;
		if (used[to])
			fup[v] = min(fup[v], tin[to]);
		else 
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v])
				bridge.insert(mp(min(v, to), max(v, to)));
		}
	}
}

void dfs2(int v)
{
	if (used2[v]) return;
	used2[v] = true;
	curv.pb(v);
	for(auto to : g[v])
		if (!bridge.count(mp(min(v, to), max(v, to))))
			dfs2(to);
}

vector<int> constr[N];

bool read() {
 	if(scanf("%d %d", &n, &m) != 2)
 		return false;
 	for(int i = 0; i < m; i++)
 	{
 		int x, y;
 		scanf("%d %d", &x, &y);
 		--x;
 		--y;
 		g[x].pb(y);
 		g[y].pb(x);
 	}
 	return true;
}

int a[N];

vector<int> t[4 * N];
vector<li> pref[4 * N];

void build(int v, int l, int r)
{
	if (l == r - 1)
	{
		t[v].pb(a[l]);
	}
	else
	{
		int mid = (l + r) >> 1;
		build(v * 2 + 1, l, mid);
		build(v * 2 + 2, mid, r);
		for(auto x : t[v * 2 + 1]) t[v].pb(x);
		for(auto y : t[v * 2 + 2]) t[v].pb(y);
	}
	pref[v].pb(0);
	for(auto x : t[v])
	{
		li z = pref[v].back();
		pref[v].pb(z + x);
	}
}	

li get(int v, int l, int r, int L, int R, int bound)
{
	if (L >= R) return 0;
	if (L == l && R == r)
	{
		int z = lower_bound(all(t[v]), bound) - t[v].begin();
		return pref[v][z] + (sz(t[v]) - z) * 1ll * bound;
	}
	int mid = (l + r) / 2;
	return get(v * 2 + 1, l, mid, L, min(R, mid), bound) + get(v * 2 + 2, mid, r, max(L, mid), R, bound);
}

void solve() {
	forn(i, n) dfs(i);
	forn(i, n) 
	{
		if (used2[i] == 0)
		{
			dfs2(i);
			if (sz(curv) > 2)
			{
				sort(all(curv));
				constr[curv[0]].pb(curv.back());
			}
			curv.clear();
		}
	}
	int cur = n;
	for(int i = n - 1; i >= 0; i--)
	{
		for(auto x : constr[i]) cur = min(cur, x);
		a[i] = cur;
	}
	build(0, 0, n);
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		li ans = get(0, 0, n, x, y, y) - ((x + y - 1) * 1ll * (y - x)) / 2;
		printf("%I64d\n", ans);
	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	if(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}