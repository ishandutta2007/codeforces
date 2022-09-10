#define CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>
#include <complex>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) (ll)((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvch vector<vch>
#define vvb vector<vb>
#define vs vector<string>
#define vss vector<vs>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define base complex<double>
#define PI 3.141592653589793
using namespace std;
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	ll n, p, q, r;
	cin >> n >> p >> q >> r;

	vll a(n + 1);
	FOR(i, 0, n)
		cin >> a[i + 1];

	/*vpll max_pref(n + 1);
	max_pref[1] = MP(a[1], 1);

	FOR(i, 2, n + 1)
	{
		max_pref[i] = max_pref[i - 1];
		if (a[i] > max_pref[i].X)
			max_pref[i] = MP(a[i], i);
	}

	vpll min_pref(n + 1);
	min_pref[1] = MP(a[1], 1);

	FOR(i, 2, n + 1)
	{
		min_pref[i] = min_pref[i - 1];
		if (a[i] < min_pref[i].X)
			min_pref[i] = MP(a[i], i);
	}

	state dp[MAXN][3];

	dp[1][0] = dp[1][1] = dp[1][2] = { (p + q + r) * a[1], 1, 1, 1 };

	FOR(f, 2, n + 1)
	{
		dp[f][0] = dp[f - 1][0];
	
		if (dp[f - 1][0].ans < a[f] * (p + q + r))
			dp[f][0] = { a[f] * (p + q + r), f, f, f };

		
		dp[f][1] = dp[f - 1][1];
		
		if (p >= 0)
		{
			if (a[f] * (q + r) + max_pref[f].X * p > dp[f][1].ans)
			{
				dp[f][1] = { a[f] * (q + r) + max_pref[f].X * p , max_pref[f].Y, f, f };
			}
		}
		else
		{
			if (a[f] * (q + r) + min_pref[f].X * p > dp[f][1].ans)
			{
				dp[f][1] = { a[f] * (q + r) + min_pref[f].X * p , max_pref[f].Y, f, f };
			}
		}

		dp[f][2] = dp[f - 1][2];




	}

	cout << dp[n][2].ans;
	*/

	vvll dp(n + 1, vll(3, -INF));

	dp[1][0] = a[1] * p;
	FOR(i, 2, n + 1)
		dp[i][0] = max(dp[i - 1][0], a[i] * p);

	dp[1][1] = a[1] * (p + q);
	FOR(i, 2, n + 1)
		dp[i][1] = max(dp[i - 1][1], dp[i][0] + a[i] * q);

	dp[1][2] = a[1] * (p + q + r);
	FOR(i, 2, n + 1)
		dp[i][2] = max(dp[i - 1][2], dp[i][1] + a[i] * r);

	cout << dp[n][2];
	//cin >> n;
	return 0;
}