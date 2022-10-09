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

const int M = 998244353;

int add(int x, int y)
{
	int z = x + y;
	while(z < 0) z += M;
	while(z >= M) z -= M;
	return z;
}

int mul(int x, int y)
{
	return add((x * 1ll * y) % M, 0);
}

int binpow(int x, int y)
{
	int z = 1;
	while(y)
	{
		if(y & 1) z = mul(z, x);
		y >>= 1;
		x = mul(x, x);
	}
	return z;
}

int n;

int fact[1000043];
int rev[1000043];

bool read() {
 	if(!(cin >> n))
 		return false;
 	return true;
}

void solve() {
	fact[0] = 1;
	fore(i, 1, n + 1) fact[i] = mul(fact[i - 1], i);
	forn(i, n + 1) rev[i] = binpow(fact[i], M - 2);
	int ans = 0;
	int cntr1 = binpow(3, n);
	int cntr2 = add(binpow(3, n), -3);
	for(int i = 0; i < n; i++)
	{
		ans = add(ans, mul(3, mul(binpow(cntr2, i), binpow(cntr1, n - i - 1))));
	}
	for(int i = 0; i < n; i++)
	{
		int cur = ((i & 1) ? -1 : 1);
		int row_count = binpow(3, n - i - 1);
		int bad_row_count = add(row_count, -1);
		int C = mul(fact[n], mul(rev[n - i - 1], rev[i + 1]));
		C = mul(C, cur);
		int m2 = mul(3, binpow(bad_row_count, n));
		m2 = add(m2, mul(add(-3, binpow(3, i + 1)), binpow(row_count, n)));
		C = mul(C, m2);
		ans = add(ans, C);
	}
	cout << ans << endl;
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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