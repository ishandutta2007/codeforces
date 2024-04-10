#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

void bad()
{
	cout << -1 << endl;
	exit(0);
}

const int MAX = 100000 + 7;
int n;
PII a[MAX];

bool can(double x)
{
	double L = -LINF, R = LINF;
	double x1, x2;
	FOR(i, 0, n)
	{
		if (a[i].Y > x + x)
			return 0;
		
		x1 = a[i].X - sqrt(a[i].Y *1.0* (2*x - a[i].Y));
		x2 = a[i].X + sqrt(a[i].Y *1.0* (2*x - a[i].Y));
		
		L = max(L, x1);
		R = min(R, x2);
	}
	
	//cout << L << " " << R << endl;	
	return L <= R;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	FOR(i, 0, n)	
		cin >> a[i].X >> a[i].Y;;
	
	bool dod = a[0].Y > 0;
	FOR(i, 1, n)
		if (dod != (a[i].Y > 0))
			bad();

	if (!dod)
	{
		FOR(i, 0, n)
			a[i].Y *= -1;
	}
	
	double L = 0.5, R = LINF, M;
	FOR(iter, 0, 100)
	{
		M = (L + R) / 2.0;
		if (can(M))
			R = M;
		else
			L = M;
	}
	
	cout << fixed << setprecision(10) << L << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}