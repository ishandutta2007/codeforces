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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define double long double

int get(string s)
{
	int res = 0;
	for(auto i: s)
		if (i != '.')
			res = res * 10 + i - '0';
	return res;
}

const double EPS = 1e-6;

int cmp(double x, double y)
{
	if (abs(x - y) < EPS)
		return 0;
	if (x < y)
		return 1;
	else
		return -1;
}

pair<double, int> get(double x, double y, double z)
{
	if (abs(x - 1) < EPS)
		return {1.0, 1};
	
	if (x > 1)
	{
		double pw = z * log (y);
		int id = 1;
		if (cmp(pw, y * log (z)) == 1)
			pw = y * log (z), id = 2;
		
		if (cmp(pw, log(y) + log (z)) == 1)
			pw = log(y) + log (z), id = 3;
		
		return {pw, id};
	}
	else
	{
		double pw = z * log (y);
		int id = 1;
		if (cmp(pw, y * log (z)) == -1)
			pw = y * log (z), id = 2;
		
		if (cmp(pw, log(y) + log (z)) == -1)
			pw = log(y) + log (z), id = 3;
		
		return {pw, id};
	}
}

int cmp(pair<double, double> x, pair<double, double> y)
{
	double valx = log (x.X) * exp(x.Y);
	double valy = log (y.X) * exp(y.Y);
	if (abs(valx - valy) < EPS)
		return 1;
	return valx > valy;
}

void solve(int x)
{
	string s;
	if (x == 1)
		s = "x^y^z";
	if (x == 2)
		s = "x^z^y";
	if (x == 3)
		s = "(x^y)^z";
		
	if (x == 5)
		s = "y^x^z";
	if (x == 6)
		s = "y^z^x";
	if (x == 7)
		s = "(y^x)^z";
	
	if (x == 9)
		s = "z^x^y";
	if (x == 10)
		s = "z^y^x";
	if (x == 11)
		s = "(z^x)^y";
	cout << s << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	string X, Y, Z;
	cin >> X >> Y >> Z;
	double x = get(X) / 10.0;
	double y = get(Y) / 10.0;
	double z = get(Z) / 10.0;
	
	auto mxx = get(x, y, z);
	auto mxy = get(y, x, z);
	auto mxz = get(z, x, y);
	
	if (cmp({x, mxx.X}, {y, mxy.X}))
	{
		if (cmp({x, mxx.X}, {z, mxz.X}))
			solve(mxx.Y);
		else
			solve(mxz.Y + 8);
	}
	else
	{
		if (cmp({y, mxy.X}, {z, mxz.X}))
			solve(mxy.Y + 4);
		else
			solve(mxz.Y + 8);
	}	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}