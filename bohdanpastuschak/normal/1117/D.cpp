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

const int mod = 1e9 + 7;

inline void add(int& x, int y)
{
	x += y;
	if (x >= mod)
		x -= mod;
}

inline int mult(int x, int y)
{
	return x * (LL) y % mod;
}

struct matrix
{
	vector<VI> a;
	int sz;
	matrix(int x)
	{
		sz = x;
		a.resize(x, VI(sz, 0));
	}
	
	void print()
	{
		FOR(i, 0, sz)
		{
			FOR(j, 0, sz)	
				cout << a[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
	}
};

matrix mult(matrix& a, matrix& b)
{
	matrix c(a.sz);
	FOR(i, 0, a.sz)
		FOR(j, 0, a.sz)
			FOR(k, 0, a.sz)
				add(c.a[i][j], mult(a.a[i][k], b.a[k][j]));
	return c;
}

matrix power(matrix a, LL y)
{
	matrix res(a.sz);
	FOR(i, 0, a.sz)
		res.a[i][i] = 1;
	while(y)
	{
		if (y & 1)
			res = mult(res, a);
		a = mult(a, a);
		y >>= 1;		
	}
	return res;
}

LL n, m;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	if (n < m)
	{
		cout << 1;
		return 0;
	}
	
	matrix mt(m);
	mt.a[0][0] = 1;
	mt.a[m - 1][0] = 1;
	FOR(i, 1, m)
		mt.a[i - 1][i] = 1;
	
	//mt.print();
	matrix res = power(mt, n - m + 1);
	int ans = 0;
	for(auto i: res.a)
			add(ans, i[0]);
	
	//res.print();
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}