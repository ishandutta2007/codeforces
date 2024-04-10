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

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

const int N = 1043;

pair<ld, ld> a[N];
int n;

bool read() {
 	if(!(cin >> n))
 		return false;
 	forn(i, n) cin >> a[i].x >> a[i].y;
 	return true;
}

ld dist(const pair<ld, ld>& x, const pair<ld, ld>& y)
{
 	return sqrtl(sqr(x.x - y.x) + sqr(x.y - y.y));
}

void solve() {
	ld ans = 1e20;
	forn(i, n)
	{
		ans = min(ans, dist(a[i], a[(i + 1) % n]) / 2);
		auto z1 = a[(i + n - 1) % n];
		auto z2 = a[i];
		auto z3 = a[(i + 1) % n];
		ld s = fabsl(0.5 * ((z2.x - z1.x) * (z2.y - z3.y) - (z2.y - z1.y) * (z2.x - z3.x)));
		//cerr << s << endl;
		ans = min(ans, s / dist(z1, z3));
		//cerr << dist(z1, z3) << endl;
	} 
	cout << ans << endl;
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	while(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}