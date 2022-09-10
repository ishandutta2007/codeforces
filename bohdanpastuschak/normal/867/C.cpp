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

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
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

int f(pair<ll, pll> a, pair<ll, pll> b)
{
	return a.Y.X - a.Y.Y < b.Y.X - b.Y.Y;
}

ll n, s;
vector<pair<ll, pll>> a;
ll sum;
ll pizzas;

ll check(ll x)
{
	ll res = 0;

	FOR(i, 0, n)
		res += a[i].X * a[i].Y.X;

	ll ye_druhoi = 0;
	ll max_druhoi = (pizzas - x)*s;
	ll treba_zlyty_pershoi = sum - x * s;

	FOR(i, 0, n)
	{
		if (ye_druhoi >= max_druhoi)
			break;

		if (a[i].Y.Y - a[i].Y.X <= 0 && treba_zlyty_pershoi <= 0)
			break;

		if (a[i].Y.Y > a[i].Y.X)
		{
			if (ye_druhoi + a[i].X <= max_druhoi)
			{
				ye_druhoi += a[i].X;
				treba_zlyty_pershoi -= a[i].X;
				res += a[i].X * (a[i].Y.Y - a[i].Y.X);
			}
			else
			{
				ll zlyly = max_druhoi - ye_druhoi;
				ye_druhoi = max_druhoi;
				treba_zlyty_pershoi -= zlyly;
				res += zlyly * (a[i].Y.Y - a[i].Y.X);
			}
		}
		else
		{
			if (treba_zlyty_pershoi <= 0)
				break;

			if (treba_zlyty_pershoi >= a[i].X)
			{
				treba_zlyty_pershoi -= a[i].X;
				ye_druhoi += a[i].X;
				res += a[i].X * (a[i].Y.Y - a[i].Y.X);
			}
			else
			{
				
				ll zlyly = treba_zlyty_pershoi;
				treba_zlyty_pershoi = 0;
				ye_druhoi += zlyly;
				res += zlyly  * (a[i].Y.Y - a[i].Y.X);
			}
		}
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> s;
	a.assign(n, MP(0, MP(0, 0)));
	FOR(i, 0, n)
		cin >> a[i].X >> a[i].Y.X >> a[i].Y.Y;

	sum = 0;
	FOR(i, 0, n)
		sum += a[i].X;

	pizzas = (sum + s - 1LL) / s;
	sort(ALL(a), f);

	ll l = 0, r = pizzas, med1, med2, ans = 0;
	while (r - l > 2)
	{
		med1 = l + (r - l) / 3;
		med2 = r - (r - l) / 3;
		
		if (check(med1) < check(med2))
			l = med1;
		else
			r = med2;
	}

	FOR(i, l, r + 1)
		ans = max(ans, check(i));

	cout << ans;
	//cin >> n;
	return 0;
}