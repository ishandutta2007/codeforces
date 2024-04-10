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

int n;

const int N = 200043;

int a[N];
int c[N];
int cnt[2];
int siz[N][2];
int par[N];

vector<int> g[N];

int add(int x, int y)
{
	int z = (x + y);
	while(z < 0) z += MOD;
	while(z >= MOD) z -= MOD;
	return z;
}

int mul(int x, int y)
{
	return add(0, (x * 1ll * y) % MOD);
}

void dfs1(int x, int p = -1, int cur = 0)
{
	c[x] = cur;
	cnt[cur]++;
	par[x] = p;
	siz[x][cur]++;
	for(auto y : g[x]) if (y != p) 
	{
		dfs1(y, x, cur ^ 1);
		forn(z, 2) siz[x][z] += siz[y][z];
	}
}

int ans = 0;

void update(int x)
{
	ans = add(ans, mul(cnt[c[x]], a[x]));
	ans = add(ans, mul(-cnt[c[x] ^ 1], a[x]));
	ans = add(ans, mul(n - 1, a[x]));
	int sum_all = n - 1;
	for(auto y : g[x])
	{
		if(y == par[x]) continue;
		int cnt_white = siz[y][0];
		int cnt_black = siz[y][1];
		if(c[x] == 0)
		{
			ans = add(ans, mul(cnt_white, mul(sum_all - cnt_white - cnt_black, a[x])));
			ans = add(ans, mul(-cnt_black, mul(sum_all - cnt_white - cnt_black, a[x])));
		}
		else
		{
			ans = add(ans, mul(-cnt_white, mul(sum_all - cnt_white - cnt_black, a[x])));
			ans = add(ans, mul(cnt_black, mul(sum_all - cnt_white - cnt_black, a[x])));
		}
	}
	if(par[x] != -1)
	{
		int cnt_white = cnt[0] - siz[x][0];
		int cnt_black = cnt[1] - siz[x][1];
		if(c[x] == 0)
		{
			ans = add(ans, mul(cnt_white, mul(sum_all - cnt_white - cnt_black, a[x])));
			ans = add(ans, mul(-cnt_black, mul(sum_all - cnt_white - cnt_black, a[x])));
		}
		else
		{
			ans = add(ans, mul(-cnt_white, mul(sum_all - cnt_white - cnt_black, a[x])));
			ans = add(ans, mul(cnt_black, mul(sum_all - cnt_white - cnt_black, a[x])));
		}
	}
}

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, n) scanf("%d", &a[i]);
 	forn(i, n - 1)
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

void solve() {
	dfs1(0);
	forn(i, n) update(i);
	cout << ans << endl;
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