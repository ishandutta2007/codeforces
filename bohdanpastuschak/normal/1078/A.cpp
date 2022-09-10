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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;

LL a, b, c;
pair<LL, LL> s, t;
double A, B, C;

double dist(pair<double, double> x, pair<double, double> y)
{
	return abs(x.X - y.X) + abs(x.Y - y.Y);
}

double DIST(pair<double, double> x, pair<double, double> y)
{
	return sqrt((x.X - y.X) * (x.X - y.X) + (x.Y - y.Y) * (x.Y - y.Y));
}

pair<double, double> get(double coef)
{
	return MP(coef, (-c - a * coef + 0.0) / b);
}

const int MAX = 477;

double f(pair<double, double> x)
{
	double ans = LINF;
	double L = -LINF, R = LINF, M1, M2;
	
	FOR(it, 0, MAX)
	{
		M1 = L + (R - L) / 3.0;
		M2 = R - (R - L) / 3.0;

		pair<double, double> x1 = get(M1);
		pair<double, double> x2 = get(M2);
		
		double v1 = dist(x1, t) + DIST(x1, x);
		double v2 = dist(x2, t) + DIST(x2, x);
		
		ans = min(ans, v1);
		ans = min(ans, v2);
		
		if (v1 < v2)
			R = M2;
		else
			L = M1;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> a >> b >> c;
	A = a, B = b, C = c;
	cin >> s.X >> s.Y >> t.X >> t.Y;
	
	double ans = dist(s, t);
	cout << fixed << setprecision(10);
	
	if (a == 0 || b == 0)
	{		
		cout << ans << endl;
		return 0;
	}
	
	double L = -LINF, R = LINF, M1, M2;
	FOR(it, 0, MAX)
	{
		M1 = L + (R - L) / 3.0;
		M2 = R - (R - L) / 3.0;

		pair<double, double> x1 = get(M1);
		pair<double, double> x2 = get(M2);
		double v1 = f(x1) + dist(x1, s);
		double v2 = f(x2) + dist(x2, s);
		
		ans = min(ans, v1);
		ans = min(ans, v2);

		if (v1 < v2)
			R = M2;
		else
			L = M1;
	}
	 
	cout << ans << endl;
	cerr << "Time elapsed : " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}