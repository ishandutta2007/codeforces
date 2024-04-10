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
const int N = 200 * 1000 + 43;

int n;
int a[N];
int b[N];
int cur = 1;
int fact[N];
int rev[N];

li binpow(li x, li y)
{
 	li ans = 1;
 	while(y)
 	{
 	 	if (y & 1)
 	 		ans = (ans * x) % MOD;
 	 	x = (x * x) % MOD;
 	 	y >>= 1;
 	}
 	return ans;
}

void step()
{
 	for(int i = 1; i < n; i++)
 	{
 	 	b[i - 1] = ((a[i - 1] + cur * a[i]) % MOD + MOD) % MOD;
 	 	cur *= -1;
 	}
 	n--;
 	forn(i, n) a[i] = b[i];
 	forn(i, n) b[i] = 0;
}

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, n) scanf("%d", &a[i]);
 	return true;
}

void solve() {
	cur = 1;
	forn(i, N)
	{
	 	if (i == 0) fact[i] = 1;
	 	else fact[i] = (fact[i - 1] * 1ll * i) % MOD;
	 	rev[i] = binpow(fact[i], MOD - 2) % MOD;
	}
	while((cur != 1 || (n & 1) == 0) && n > 1)
		step();
	//forn(i, n) cerr << a[i] << endl;
	//cerr << "!\n";
	if (n >= 5)
	{
	 	int cnt = (n - 1) / 4;
	 	int ch = cnt * 4;
	 	int nn = cnt * 2;
	 	for(int i = 0; i < n - ch; i++)
	 		for(int j = 0; j <= nn; j++)
	 		{
	 		 	int c = ((fact[nn] * 1ll * rev[j]) % MOD * 1ll * rev[nn - j]) % MOD;
	 		 	//cerr << c << endl;
	 		 	b[i] += (c * 1ll * a[i + 2 * j]) % MOD;
	 		 	//cerr << b[i] << endl;
	 		 	b[i] = (b[i] % MOD + MOD) % MOD;
	 		 	//cerr << i << " " << c << " " << j << endl;
	 	   	}
	 	n = n - ch;
	 	forn(i, n) a[i] = b[i];
	 	//forn(i, n) cerr << a[i] << endl;
	}            
	while(n > 1)
		step();
	printf("%d\n", (a[0] % MOD + MOD) % MOD);
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