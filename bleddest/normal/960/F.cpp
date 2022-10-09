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

int n, m;
const int N = 100043;

map<int, int> f[N];

bool gen()
{
	n = m = 100000;
	return true;
}

bool read() {
	//return gen();
 	if(scanf("%d %d", &n, &m) != 2)
 		return false;
 	return true;
}

int get(int v, int r)
{
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		if(f[v].count(r))
			res = max(res, f[v][r]);
	return res;
}

void upd(int v, int i, int val)
{
	for(; i < N; i |= (i+ 1))
		f[v][i] = max(f[v][i], val);
}

void solve() {
	int ans = 0;
	forn(i, m)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
	//	x = y = 1;
	//	w = i;
		--x;
		--y;
		int ans1 = get(x, w - 1) + 1;
		upd(y, w, ans1);
		ans = max(ans, ans1);
	}
	printf("%d\n", ans);
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