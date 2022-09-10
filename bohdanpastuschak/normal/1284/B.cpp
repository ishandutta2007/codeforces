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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 17;
int n;
vector<int> a[N];

bool spadna(vector<int>& x)
{
	FOR(i, 0, SZ(x) - 1) if (x[i] < x[i + 1])
		return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	vector<PII> e;
	FOR(i, 0, n)
	{
		int l;
		cin >> l;
		a[i].resize(l);
		FOR(j, 0, l) cin >> a[i][j];
		if (spadna(a[i]))
		{
			e.PB({a[i][0], -1});
			e.PB({a[i].back(), 1});
		}
	}
	
	sort(ALL(e));
	int cnt = 0;
	LL ans = 0;
	for(auto i: e)
	{
		if (i.Y == 1) 
			ans += cnt;
		else
			cnt++;
	}	
	
	ans = n * (LL) n - ans;
	cout << ans << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}