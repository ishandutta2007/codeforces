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

VI solve(vector<pair<PII, int>> vec)
{
	if (SZ(vec) == 0)
		return VI();
		
	sort(ALL(vec));
	int n = SZ(vec);
	
	VI dp(n, 1);
	VI go(n, -1);
	VI mx_on_pref(n, 0);
	
	FOR(i, 1, n)
	{
		dp[i] = 1;
		mx_on_pref[i] = mx_on_pref[i - 1];
		
		int b = vec[i].X.Y;
		int it = lower_bound(ALL(vec), MP(MP(b, -1), -1)) - vec.begin();
		if (it == 0)
			continue;
		
		it = min(it, i);
		--it;
		
		int best = mx_on_pref[it];
		go[i] = best;
		dp[i] = dp[best] + 1;
		if (dp[i] > dp[mx_on_pref[i]])
			mx_on_pref[i] = i;
	}
	
	VI ans;
	int mx_dp = 0;
	FOR(i, 1, n)
		if (dp[i] > dp[mx_dp])
			mx_dp = i;
	
	while(mx_dp != -1)
	{
		ans.PB(vec[mx_dp].Y);
		mx_dp = go[mx_dp];
	}
	
	return ans;
}

const int N = 1 << 20;
int n;
PII a[N];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n;
	VI ans;
	vector<pair<PII, int>> raz, dwa;
	FOR(i, 0, n)
	{
		cin >> a[i].X >> a[i].Y;
		if (a[i].X < a[i].Y)
			raz.PB(MP(a[i], i));
		else
			dwa.PB(MP(a[i], i));
	}
	
	for(auto& i: dwa)
		swap(i.X.X, i.X.Y);
	
	ans = solve(raz);
	VI tut = solve(dwa);
	if (SZ(tut) > SZ(ans))
	{
		ans = tut;
		reverse(ALL(ans));
	}
	
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i + 1 << ' ';	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}