#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,avx")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;
 
template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}
 
const double PI = acos(-1.0);
const int INF = 1e9 + 47;
const LL LINF = 1LL * INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

VI op1(VI a, int n)
{
	FOR(i, 0, n)
		swap(a[2 * i], a[2 * i + 1]);
	return a;
}
VI op2(VI a, int n)
{
	FOR(i, 0, n)
		swap(a[i], a[i + n]);
	return a;
}

bool sor(VI a, int n)
{
	bool ok = 1;
	FOR(i, 0, 2 * n)
		ok &= (a[i] == i + 1);
	return ok;
}
int ps1(VI a, int n)
{
	FOR(i, 0, 2 * n)
		if(a[i] == 1) return i;
	assert(0);
}

VI arr[1 << 11];
int d[1 << 11];
int Q[1 << 11];
void gen(int n)
{
	VI a(2 * n);
	FOR(i, 0, 2 * n)
	{
		a[i] = i + 1;
		d[i] = INF;
	}
	d[0] = 0;
	int qh = 0, qt = 1;
	Q[0] = 0;
	arr[0] = a;
	
	while(qh != qt)
	{
		int v = Q[qh++];
		a = arr[v];
		VI b = op1(a, n), c = op2(a, n);
		int P1 = ps1(b, n);
		if(d[P1] == INF)
		{
			d[P1] = d[v] + 1;
			arr[P1] = b;
			Q[qt++] = P1;
		}
		else
			assert(arr[P1] == b);
		
		int P2 = ps1(c, n);
		if(d[P2] == INF)
		{
			d[P2] = d[v] + 1;
			arr[P2] = c;
			Q[qt++] = P2;
		}
		else
			assert(arr[P2] == c);
	}
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	gen(n);
	VI a(2*n);
	FOR(i, 0, 2 * n)
		cin >> a[i];
	int pos1 = ps1(a, n);
	FOR(i, 0, 2* n)
		if(a[i] != arr[pos1][i])
		{
			cout << -1 << endl;
			return 0;
		}
	cout << d[pos1] << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}