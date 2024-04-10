#include <iostream>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <stdio.h>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <memory.h>
#include <utility>
#include <cctype>
#include <complex>
#include <fstream>
#include <sstream>
#include <climits>
using namespace std;

#define ll long long
#define mod 1000000007
#define infinity (ll)1e18
#define epsilon 1e-6

#define pll pair<ll, ll>
#define pdd pair<double, double>
#define pii pair<ll,ll>
#define MP make_pair

#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(ll i = (b) - 1; i >= a; --i)
#define REPEAT(n) FOR(counter1488, 0, (n))

#define vi vector<ll>
#define vvi vector<vi>
#define ALL(V) V.begin(), V.end()
#define MAXN 100001

string add(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		if (s1.length() > s2.length())
		{
			string zeros;
			for (ll i = 0; i < s1.length() - s2.length(); ++i)
			{
				zeros += "0";
			}

			s2 = zeros + s2;
		}
		else
		{
			string zeros;
			for (ll i = 0; i < s2.length() - s1.length(); ++i)
			{
				zeros += "0";
			}

			s1 = zeros + s1;
		}
	}

	ll i = s1.length() - 1;
	while (i > 0)
	{
		if (s1[i] + s2[i] <= 48 + 48 + 9)
		{
			s1[i] += (s2[i] - 48);
		}
		else
		{

			s1[i] += (s2[i] - 58);
			s1[i - 1] += 1;
		}
		--i;
	}

	if (s1[0] + s2[0] <= 48 + 48 + 9)
	{
		s1[0] += (s2[0] - 48);
	}
	else
	{
		s1[0] += (s2[0] - 58);
		string one = "1";
		s1 = one + s1;
	}

	return s1;
}

ll power(ll n, ll t)
{
	if (t == 0) return 1;
	if (t == 1) return n;
	ll res = n;
	ll p = 1;
	while (2 * p < t)
	{
		res *= res;
		p *= 2;
	}
	return power(n, t - p) * res;
}

ll sigma(ll n)
{
	ll s = 1;
	for (ll i = 2; i <= n; ++i)
	{
		ll p = 0;
		if (n%i == 0)
		{
			while (n%i == 0)
			{
				n /= i;
				p++;
			}
			s *= power(i, p + 1) - 1;
			s /= (i - 1);
		}
	}
	return s;
}

ll maxSubArraySum(vi a)
{
	ll max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < a.size(); i++)
	{
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int main()
{
	/*ll b1, q, l, m;
	cin >> b1 >> q >> l >> m;

	vi a(m);
	FOR(i, 0, m)cin >> a[i];

	if (b1 == 0)
	{
		FOR(i,0,m)
			if (a[i] == 0)
			{
				cout << 0;
				return 0;
			}
		cout << "inf";
		return 0;
	}

	if (q == 0)
	{
		bool isZ = false, isB1 = false;
		FOR(i, 0, m)
		{
			if (a[i] == 0)
			{
				isZ = true;
			}
			if (a[i] == b1)
			{
				isB1 = true;
			}
		}

		if (!isZ)
		{
			cout << "inf";
			return 0;
		}
		else
		{
			if (isB1 || abs(b1) > l)
			{
				cout << 0;
			}
			else
				cout << 1;
			return 0;
		}		
	}

	if (q == 1)
	{
		if (abs(b1) > l)
		{
			cout << 0;
			return 0;
		}
		bool  isB1 = false;
		FOR(i, 0, m)
		{			
			if (a[i] == b1)
			{
				isB1 = true; break;
			}
		}
		if (isB1)
			cout << 0;
		else cout << "inf";
		return 0;
	}

	if (q == -1)
	{
		if (abs(b1) > l)
		{
			cout << 0;
			return 0;
		}

		bool isB = false, isMB = false;
		FOR(i, 0, m)
		{
			if (a[i] == b1)
				isB = true;
			if (a[i] == -b1)
				isMB = true;
		}

		if (!isB || !isMB)
			cout << "inf";
		else
			cout << 0;
		return 0;	
	}

	ll ans = 0;
	vector<ll> good;
	FOR(i, 0, infinity)
	{
		if (abs(b1) > l) break;
		good.push_back(b1);
		b1 *= q;
	}

	bool isA = false;
	FOR(i, 0, good.size())
	{
		isA = false;
		FOR(j,0,m)
			if (good[i] == a[j])
			{
				isA = true;
				break;
			}
		if (!isA)
		{
			ans++;
		}
	}
	cout << ans;
	*/
	

	int n; cin >> n;
	vi a(n);
	FOR(i, 0, n)cin >> a[i];

	vi d(n - 1);
	FOR(i, 0, n - 1)
		d[i] = abs(a[i + 1] - a[i]);


	ll best = 0;
	
	//
	for (int i = 1; i < n - 1; i += 2)
		d[i] -= 2 * d[i];

	best = max(best, maxSubArraySum(d));
	
	FOR(i, 0, n - 1)
		d[i] = -d[i];

	best = max(best, maxSubArraySum(d));

	cout << best;

	return 0;
}