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
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline bool even(int& x)
{
	return (x % 2 == 0);
}

vector<int> solve(vector<PII>& a, int n)
{
	vector<int> ans;
	FOR(i, 0, n) if ((a[i].X + a[i].Y) & 1)
		ans.PB(i);
	
	if (SZ(ans) > 0 && SZ(ans) < n) return ans;
	
	if (SZ(ans) == 0)
	{
		// - 
		bool ok = true;
		FOR(i, 0, n) if (even(a[i].X) != even(a[0].X))
			ok = false;
		
		if (!ok)
		{
			FOR(i, 0, n) if (even(a[i].X) != even(a[0].X))
				ans.PB(i);
			return ans;
		}
		
		if (!even(a[0].X))
			FOR(i, 0, n) a[i].X++, a[i].Y++;
		
		FOR(i, 0, n) a[i].X /= 2, a[i].Y /= 2;
		return solve(a, n);
	}
	else
	{
		ans.clear();
		// - 
		
		bool ok = true;
		FOR(i, 0, n) if (even(a[i].X) != even(a[0].X))
			ok = false;
		
		if (!ok)
		{
			FOR(i, 0, n) if (even(a[i].X) == even(a[0].X))
				ans.PB(i);
			return ans;
		}
		
		if (even(a[0].X))
			FOR(i, 0, n) a[i].Y++;
		else
			FOR(i, 0, n) a[i].X++;
		return solve(a, n);
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	vector<PII> a(n);
	FOR(i, 0, n) 
	{
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	
	auto ans = solve(a, n);
	cout << SZ(ans) << endl;
	for(auto i: ans) cout << i + 1 << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}