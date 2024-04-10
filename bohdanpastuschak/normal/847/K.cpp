#define _CRT_SECURE_NO_WARNINGS
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

#define ld double
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
#define alphabet_size 26
using namespace std;

#define mod 1000000007
#define INF (ll)1e18
#define MAXN 301

ll n, a, b, k, f;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> a >> b >> k >> f;

	vector<pair<string, string>> s(n);
	FOR(i, 0, n)
		cin >> s[i].X >> s[i].Y;

	map<pair<string, string>, int> count_a, count_b, vyhr;

	ll ans = 0;
	ans += a;
	count_a[MP(min(s[0].X, s[0].Y), max(s[0].X, s[0].Y))]++, count_b[MP(min(s[0].X, s[0].Y), max(s[0].X, s[0].Y))] += 0;
	FOR(i, 1, n)
		if (s[i].X == s[i - 1].Y)
			ans += b, count_b[MP(min(s[i].X, s[i].Y), max(s[i].X, s[i].Y))]++, count_a[MP(min(s[i].X, s[i].Y), max(s[i].X, s[i].Y))] += 0;
		else
			ans += a, count_a[MP(min(s[i].X, s[i].Y), max(s[i].X, s[i].Y))]++, count_b[MP(min(s[i].X, s[i].Y), max(s[i].X, s[i].Y))] += 0;

	ll ans2 = ans;
	/*set<pair<string, string >> aa;
	FOR(i, 0, n)
		aa.insert(MP(min(s[i].X, s[i].Y), max(s[i].X, s[i].Y)));

	set<pair<string, string >> kupl;
	REPEAT(k)
	{
		vector<pair<string, string>> ss(ALL(aa));
		int m = ss.size();
		vll zap(m);
		FOR(i, 0, m)
		{
			ll curr = 0;

			if (s[0] == ss[i] || (s[0].X == ss[i].Y && s[0].Y == ss[i].X))
				curr = 0;
			else
				curr = a;

			FOR(j, 1, n)
				if (s[j] == ss[i] || has(s[j], kupl) || has(MP(s[j].Y, s[j].X), kupl) || (s[j].X == ss[i].Y && s[j].Y == ss[i].X))
					continue;
				else
				{
					if (s[j].X == s[j - 1].Y)
						curr += b;
					else
						curr += a;
				}

			curr += f;
			zap[i] = curr;
		}

		ll best = zap[0];
		FOR(i, 1, m)
			best = min(best, zap[i]);

		if (best > ans)
			break;

		ans = best;
		FOR(i,0,m)
			if (zap[i] == best)
			{
				kupl.insert(ss[i]);
				break;
			}
	}
	*/
	for (auto i : count_a)
	{
		vyhr[i.X] =   i.Y * a +   count_b[i.X] * b - f;
	}

	vll vh;
	for (auto i : vyhr)
		vh.push_back(i.Y);

	sort(ALL(vh));
	reverse(ALL(vh));
	FOR(i, 0, min((int)vh.size(), (int)k))
		if (vh[i] > 0)
			ans2 -= vh[i];

	cout << min(ans, ans2);
	return 0;
}