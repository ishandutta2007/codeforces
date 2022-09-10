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

	ll a, b, f, k;
	cin >> a >> b >> f >> k;

	ll ans = 0;

	if (k == 1)
	{
		if (b >= a)
			cout << 0;
		else
		{
			if (b >= f && b >= a - f)
				cout << 1;
			else
				cout << -1;
		}

		return 0;
	}

	if (k == 2)
	{
		if (b >= 2 * a)
			cout << 0;
		else
		{
			if (b >= a + (a - f))
				cout << 1;
			else
			{
				if (b < f || b < 2 * (a - f))
					cout << -1;
				else
					cout << 2;
			}
		}

		return 0;
	}

	if ((b < 2 * f) || (b < 2 * (a - f)))
	{
		cout << -1;
		return 0;
	}

	ans = 0;
	int curr = 0;
	ll ye = b;

	while (k - 1)
	{
		if (curr == 0)
		{
			if (ye >= a + (a - f))
			{
				ye -= a;
				curr = a;
			}
			else
			{
				ye = b - (a - f);
				ans++;
				curr = a;
			}
		}
		else
		{
			if (ye >= a + f)
			{
				ye -= a;
				curr = 0;
			}
			else
			{
				ans++;
				ye = b - f;
				curr = 0;
			}
		}

		--k;
	}

	if (ye < a)
		ans++;

	cout << ans;
	//cin >> k;
	return 0;
}