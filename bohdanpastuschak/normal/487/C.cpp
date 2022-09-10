#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

int mult(int x, int y, int m)
{
	return x * (LL) y % m;
}

int power(int x, int y, int m)
{
	int r = 1;
	while(y)
	{
		if (y & 1)
			r = mult(r, x, m);
		x = mult(x, x, m);
		y >>= 1;
	}
	
	return r;
}

bool check(VI& a)
{
	set<int> s;
	int last = 1;
	FOR(i, 0, SZ(a))
	{
		last *= a[i];
		last %= SZ(a);
		s.insert(last);
	}
	
	return SZ(s) == SZ(a);
}

void get(VI& a)
{
	int last = 1;
	FOR(i, 0, SZ(a))
	{
		last *= a[i];
		last %= SZ(a);
		cout << last << ' ' ;
	}
	cout << endl;
}

void print(VI& a)
{
	for(auto i: a)
		cout << i << ' ';
	cout << endl;
}

bool is_prime(int n)
{
	for(int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	int n;
	cin >> n;
	if (n == 4)
	{
		cout << "YES\n1\n3\n2\n4\n";
		return 0;
	}
	
	if (n == 1)
	{
		cout << "YES\n1\n";
		return 0;
	}
	
	if (!is_prime(n))
	{
		cout << "NO" << endl;
		return 0;
	}
	
	VI a;
	a.PB(1);
	a.PB(2);
	FOR(i, 2, n - 1)
		a.PB(mult(i + 1, power(i, n - 2, n), n));
	
	if (n > 2)
		a.PB(n);
	
	cout << "YES\n";
	for(auto i: a)
		cout << i << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}