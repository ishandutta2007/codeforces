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

vector<LL> d(LL n)
{
	vector<LL> ans;
	for(LL i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			ans.PB(i);
			if (i * i < n)
				ans.PB(n / i);
		}
	sort(ALL(ans));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	LL a, b;
	cin >> a >> b;
	
	LL ans = -1;
	vector<LL> da = d(a), db = d(b);
	LL v = a + b;
	for(LL i = 1; i * i <= v; ++i)
	{
		if (v % i)
			continue;
		
		bool ok = 0;
		
		auto it = upper_bound(ALL(da), i) - da.begin() - 1;
		if (it >= 0)
		{
			LL treba = a / da[it];
			if (treba <= v / i)
				ok = 1;
		}
		
		it = upper_bound(ALL(da), v / i) - da.begin() - 1;
		if (it >= 0)
		{
			LL treba = a / da[it];
			if (treba <= i)
				ok = 1;
		}
		
		it = upper_bound(ALL(db), i) - db.begin() - 1;
		if (it >= 0)
		{
			LL treba = b / db[it];
			if (treba <= v / i)
				ok = 1;
		}
		
		it = upper_bound(ALL(db), v / i) - db.begin() - 1;
		if (it >= 0)
		{
			LL treba = b / db[it];
			if (treba <= i)
				ok = 1;
		}

		if (!ok)
			continue;
		ans = i + v / i;
		ans += ans;
	}
	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}