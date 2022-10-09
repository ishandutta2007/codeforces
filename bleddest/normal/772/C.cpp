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

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

const int N = 200 * 1000 + 43;

int m, n;
bool used[N];
vector<int> cnt[N];
vector<int> g[N];
int mb[N];
int p[N];
int dp[N];
int ph;

int gcd(int x, int y)
{
 	if (x == 0) return y;
 	return gcd(y % x, x);
}

bool read() {
 	if(scanf("%d %d", &n, &m) != 2)
 		return false;
 	forn(i, m) used[i] = false;
 	forn(i, n)
 	{
 	 	int k;
 	 	scanf("%d", &k);
 	 	used[k] = true;
 	}
 	ph = phi(m);
 	return true;
}

int inv(int x)
{
 	int b = ph - 1;
 	int res = 1;
 	while(b)
 	{
 	 	if (b & 1)
 	 		res = (res * 1ll * x) % m;
 	 	b >>= 1;
 	 	x = (x * 1ll * x) % m;
 	}
 	return res;
}

int advance(int x, int y)
{
	if (x == 0) return y % m; 
 	int gx = gcd(x, m);
 	int gy = gcd(y, m);
 	int gg = gy / gx;
 	x /= gx;
 	y /= gy;
 	return ((y * 1ll * inv(x)) % m * 1ll * gg) % m;
}

void solve() {
	for(int i = 1; i <= m; i++)
	{
		if (used[i % m]) continue;
		cnt[gcd(i, m)].pb(i);
	}
	for(int i = 1; i <= m; i++)
 	{
 	 	if (gcd(i, m) != i)
 	 		continue;
 	 	int mi = m / i;
 	 	for(int j = 2; j <= mi; j++)
 	 	{
 	 	 	if (gcd(i * j, m) != i * j)
 	 	 		continue;
 	 	 	g[i].pb(i * j);
 	 	}
 	}
 	forn(i, m + 1)
 	{
 	 	dp[i] = 0;
 	 	p[i] = -1;
 	}
 	for(int i = 1; i <= m; i++)
 	{
 		dp[i] += sz(cnt[i]);
 		for(auto to : g[i])
 			if (dp[to] <= dp[i])
 			{
 			 	dp[to] = dp[i];
 			 	p[to] = i;
			}
 	}
 	int cur = m;
 	vector<int> path;
 	while(cur != -1)
 	{
 	 	path.pb(cur);
 	 	cur = p[cur];
 	}
 	reverse(all(path));
 	vector<int> pathans;
 	for(auto z : path)
 		if (sz(cnt[z]) > 0)
 			pathans.pb(z);
 	int last = 0;
 	vector<int> ans;
 	//cerr << pathans << endl;
 	for(auto z : pathans)
 		for(auto to : cnt[z])
 		{
 		 	ans.pb(advance(last, to));
 		 	last = to;
 		}
 	printf("%d\n", sz(ans));
 	for(auto z : ans) printf("%d ", z);
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