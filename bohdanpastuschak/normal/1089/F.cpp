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
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (LL)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = (LL)INF * INF;

void bad()
{
	cout << "NO" << endl;
	exit(0);
}

int n;

vector<PII> solve()
{
	int N = n;
	vector<PII> ans;
	map<int, int> mp;
	for(int i = 2; i * i <= n; ++i)
		while(n % i == 0)
			n /= i, mp[i]++;
	if (n > 1)
		mp[n]++;
	if (SZ(mp) == 1)
		bad();
		
	n = N;
	int p = mp.begin()->X;
	mp.erase(mp.begin());
	int q = mp.begin()->X;

	int xx = -1, yy = -1;
	FOR(y, 1, p)
	{
		int val = y * q + 1;
		if (val % p)
			continue;
		
		xx = (n - 1 - y * q) / p;
		yy = y;
		break;
	}
	
	assert(xx > 0);
	assert(xx * p + yy * q == n - 1);
	
	ans.PB({xx, n / p});
	ans.PB({yy, n / q});
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("In.txt" , "r" , stdin);
	
	cin >> n;
	vector<PII> ans = solve();
	cout << "YES" << endl;
	cout << SZ(ans) << endl;
	FOR(i, 0, SZ(ans))	
		cout << ans[i].X << " " << ans[i].Y << endl;
	
	return 0;
}